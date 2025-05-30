// ==UserScript==
// @name         SCUPI Blackboard Assignment Displayer
// @namespace    http://tampermonkey.net/
// @version      0.9
// @description  Refines SCU Blackboard module to display assignments. Ensures only the assignment list is scrollable, includes timeout/error feedback, and automatically reloads if page content overwrites script output.
// @author       Gilbert Chen
// @match        https://pibb.scu.edu.cn/webapps/portal/execute/tabs/tabAction?tab_tab_group_id=_1_1
// @grant        none
// @run-at       document-idle
// @license      MIT
// ==/UserScript==

(function () {
    'use strict';

    console.log('SCUPI blackboard Assignment Displayer script started (v0.9).');

    const SCRIPT_CONTENT_ID = 'userscript-assignment-content';
    let isMainRunning = false; // Flag to indicate main() is currently executing
    let currentObserver = null;
    const assignmentsUrl = 'https://pibb.scu.edu.cn/webapps/calendar/calendarData/selectedCalendarEvents';

    class Assignment {
        constructor(title, calendarName, end) {
            this.title = title;
            this.calendarName = calendarName;
            this.end = new Date(end); // Store 'end' as a Date object
        }
    }

    async function loadAssignments(url, timeout = 15000) {
        console.log(`Fetching assignments from: ${url} with ${timeout}ms timeout`);
        const controller = new AbortController();
        const signal = controller.signal;
        const timeoutId = setTimeout(() => controller.abort(), timeout);

        try {
            const response = await fetch(url, { signal });
            clearTimeout(timeoutId); // Clear timeout if fetch completes

            if (!response.ok) {
                let errorMsg = `服务器返回错误状态: ${response.status}`;
                if (response.status === 500) {
                    errorMsg = "服务器内部错误 (HTTP 500)。请稍后重试或检查服务器状态。";
                } else if (response.status === 404) {
                    errorMsg = "找不到请求的资源 (HTTP 404)。请检查URL是否正确。";
                }
                console.error(errorMsg, response);
                return { success: false, errorType: 'httpError', message: errorMsg };
            }

            let jsonData;
            try {
                jsonData = await response.json();
            } catch (e) {
                console.error("解析JSON数据失败:", e);
                return { success: false, errorType: 'invalidFormat', message: "无法解析服务器响应，格式可能不是有效的JSON。" };
            }

            if (!Array.isArray(jsonData)) {
                console.error("Fetched data is not an array:", jsonData);
                return { success: false, errorType: 'invalidFormat', message: "服务器返回的数据格式不正确（预期为数组）。" };
            }
            const assignments = jsonData.map(item => new Assignment(item.title, item.calendarName, item.end));
            return { success: true, data: assignments };

        } catch (error) {
            clearTimeout(timeoutId); // Ensure timeout is cleared on other errors too
            if (error.name === 'AbortError') {
                console.error("加载作业超时:", url);
                return { success: false, errorType: 'timeout', message: "加载作业数据超时，请检查网络连接或稍后重试。" };
            } else {
                console.error("加载或解析JSON文件失败 (网络问题):", error);
                return { success: false, errorType: 'network', message: "网络连接错误或服务器无响应，请检查网络并重试。" };
            }
        }
    }

    function formatDateTime(date) {
        return date.toLocaleString('en-US', { 
            year: 'numeric', 
            month: 'long', 
            day: 'numeric', 
            hour: '2-digit', 
            minute: '2-digit',
            hour12: true 
        });
    }

    function startIndividualCountdown(endDate, displayElement) {
        const update = () => {
            const now = new Date().getTime();
            const timeLeft = endDate.getTime() - now;

            if (timeLeft <= 0) {
                displayElement.textContent = '已截止';
                displayElement.style.color = '#757575';
                if (displayElement.intervalId) clearInterval(displayElement.intervalId);
                return;
            }

            const days = Math.floor(timeLeft / (1000 * 60 * 60 * 24));
            const hours = Math.floor((timeLeft % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
            const minutes = Math.floor((timeLeft % (1000 * 60 * 60)) / (1000 * 60));
            const seconds = Math.floor((timeLeft % (1000 * 60)) / 1000);

            let countdownText = days > 0 ? `${days}d ` : '';
            countdownText += `${hours}h ${minutes}min ${seconds}s`;
            displayElement.textContent = ` ${countdownText}`;

            if (timeLeft < (1 * 60 * 60 * 1000)) displayElement.style.color = '#D32F2F';
            else if (timeLeft < (24 * 60 * 60 * 1000)) displayElement.style.color = '#F57C00';
            else displayElement.style.color = '#388E3C';
        };
        update();
        displayElement.intervalId = setInterval(update, 1000);
    }

    async function main() {
        if (isMainRunning) {
            console.log('main() is already running. Skipping this call.');
            return;
        }
        isMainRunning = true;
        console.log('Executing main()');

        try {
            const targetModule = document.getElementById('module:_27_1');
            if (!targetModule) {
                console.error('Target module "module:_27_1" not found.');
                return;
            }

            targetModule.style.display = 'flex';
            targetModule.style.flexDirection = 'column';
            targetModule.style.maxHeight = '300px'; // Restore max-height for the module to enable internal scrolling
            targetModule.style.boxSizing = 'border-box'; // Ensure padding/border don't add to max-height

            const headerElement = targetModule.querySelector('h2.dragHandle.clearfix');
            if (headerElement) {
                const titleSpan = headerElement.querySelector('span.moduleTitle');
                if (titleSpan) {
                    titleSpan.textContent = 'Assignment Deadline';
                } else {
                    console.warn('span.moduleTitle not found in h2. Creating and prepending a new one.');
                    const newTitleSpan = document.createElement('span');
                    newTitleSpan.className = 'moduleTitle';
                    newTitleSpan.textContent = 'Assignment Deadline';
                    headerElement.prepend(newTitleSpan);
                }
                if (headerElement.nextElementSibling && headerElement.nextElementSibling.classList.contains('collapsible')) {
                    headerElement.style.marginBottom = '10px';
                }
            } else {
                console.warn('Original h2.dragHandle.clearfix header not found.');
            }

            let contentHostElement;
            let listContainer;
            const collapsibleDiv = targetModule.querySelector('div.collapsible#On_Demand_Help_Tools');

            if (collapsibleDiv) {
                contentHostElement = collapsibleDiv;
                const innerDivForList = contentHostElement.querySelector('#div_27_1');
                if (innerDivForList) {
                    listContainer = innerDivForList;
                } else {
                    listContainer = contentHostElement;
                    console.warn('#div_27_1 not found within .collapsible. Using .collapsible itself as list container.');
                }
            } else {
                console.warn('div.collapsible#On_Demand_Help_Tools not found. Creating a new content host div.');
                contentHostElement = document.createElement('div');
                listContainer = contentHostElement;
                const refNodeForInsertion = headerElement || targetModule.querySelector('div.edit_controls');
                if (refNodeForInsertion && refNodeForInsertion.parentElement === targetModule) {
                    refNodeForInsertion.after(contentHostElement);
                } else {
                    targetModule.appendChild(contentHostElement);
                }
            }

            contentHostElement.style.flexGrow = '1';
            contentHostElement.style.minHeight = '0';
            contentHostElement.style.display = 'flex';
            contentHostElement.style.flexDirection = 'column';
            contentHostElement.style.overflow = 'hidden';

            listContainer.style.flexGrow = '1';
            listContainer.style.minHeight = '0';
            listContainer.style.display = 'flex';
            listContainer.style.flexDirection = 'column';
            listContainer.style.overflow = 'hidden';

            listContainer.innerHTML = ''; // Clear before adding loading message
            const loadingMessageEl = document.createElement('p');
            loadingMessageEl.id = SCRIPT_CONTENT_ID;
            loadingMessageEl.textContent = 'Loading...';
            loadingMessageEl.style.padding = '10px';
            loadingMessageEl.style.textAlign = 'center';
            loadingMessageEl.style.margin = 'auto';
            listContainer.appendChild(loadingMessageEl);

            if (currentObserver) {
                currentObserver.disconnect();
            }
            currentObserver = new MutationObserver((mutationsList, obs) => {
                if (isMainRunning) {
                    // main() is active, mutations are expected (e.g. clearing listContainer, adding new content).
                    return;
                }
                // Check if our specific content ID is gone from the entire document.
                if (!document.getElementById(SCRIPT_CONTENT_ID)) {
                    console.log(`Userscript content (ID: ${SCRIPT_CONTENT_ID}) no longer in DOM. Re-initializing.`);
                    obs.disconnect();
                    currentObserver = null;
                    main().catch(e => console.error("Error during observer-triggered main() execution:", e));
                }
            });
            currentObserver.observe(listContainer, { childList: true, subtree: false });

            const loadResult = await loadAssignments(assignmentsUrl);

            // After await, check if our loading message (with SCRIPT_CONTENT_ID) is still in listContainer.
            // If not, listContainer was likely cleared by external script during fetch.
            // The observer should detect this and re-run main. So, bail out here.
            const currentScriptContent = document.getElementById(SCRIPT_CONTENT_ID);
            if (!currentScriptContent || !listContainer.contains(currentScriptContent)) {
                console.warn("Userscript content (loading message) was removed from listContainer during data fetch. Observer will handle re-initialization.");
                // isMainRunning will be set to false in finally block
                return;
            }

            listContainer.innerHTML = ''; // Clear loading message (which has SCRIPT_CONTENT_ID)

            if (loadResult.success) {
                const allAssignments = loadResult.data;
                const now = new Date();
                const upcomingAssignments = allAssignments.filter(assignment => assignment.end > now).sort((a, b) => a.end - b.end);

                if (upcomingAssignments.length > 0) {
                    const assignmentListWrapper = document.createElement('div');
                    assignmentListWrapper.id = SCRIPT_CONTENT_ID; // Assign ID
                    assignmentListWrapper.style.flexGrow = '1';
                    assignmentListWrapper.style.overflowY = 'auto';
                    assignmentListWrapper.style.minHeight = '0';

                    const list = document.createElement('ul');
                    list.style.listStyleType = 'none';
                    list.style.paddingLeft = '0';
                    upcomingAssignments.forEach(assignment => {
                        const listItem = document.createElement('li');
                        listItem.style.marginBottom = '15px';
                        listItem.style.padding = '10px';
                        listItem.style.border = '1px solid #eee';
                        listItem.style.borderRadius = '4px';

                        const titleEl = document.createElement('strong');
                        titleEl.textContent = assignment.title;
                        titleEl.style.display = 'block';
                        titleEl.style.fontSize = '1.1em';
                        titleEl.style.marginBottom = '5px';

                        const courseEl = document.createElement('div');
                        courseEl.textContent = `Course: ${assignment.calendarName}`;
                        courseEl.style.fontSize = '0.9em';
                        courseEl.style.color = '#555';

                        const endEl = document.createElement('div');
                        endEl.textContent = `Due: ${formatDateTime(assignment.end)}`;
                        endEl.style.fontSize = '0.9em';
                        endEl.style.color = '#D32F2F';
                        endEl.style.fontWeight = 'bold';

                        const countdownEl = document.createElement('div');
                        countdownEl.style.fontSize = '1.1em';
                        countdownEl.style.marginTop = '5px';
                        countdownEl.style.fontWeight = 'bold';

                        listItem.appendChild(titleEl);
                        listItem.appendChild(courseEl);
                        listItem.appendChild(endEl);
                        listItem.appendChild(countdownEl);
                        list.appendChild(listItem);
                        startIndividualCountdown(assignment.end, countdownEl);
                    });
                    assignmentListWrapper.appendChild(list);
                    listContainer.appendChild(assignmentListWrapper);
                } else {
                    const noAssignmentsMessage = document.createElement('p');
                    noAssignmentsMessage.id = SCRIPT_CONTENT_ID; // Assign ID
                    noAssignmentsMessage.textContent = 'No due! Enjoy your free day!';
                    noAssignmentsMessage.style.padding = '10px';
                    noAssignmentsMessage.style.textAlign = 'center';
                    listContainer.appendChild(noAssignmentsMessage);
                }
            } else {
                const errorMessageEl = document.createElement('p');
                errorMessageEl.id = SCRIPT_CONTENT_ID; // Assign ID
                errorMessageEl.textContent = `Error: ${loadResult.message}`;
                errorMessageEl.style.color = 'red';
                errorMessageEl.style.padding = '10px';
                errorMessageEl.style.textAlign = 'center';
                listContainer.appendChild(errorMessageEl);
                console.error(`Failed to load assignments: ${loadResult.errorType} - ${loadResult.message}`);
            }
        } catch (error) {
            console.error("Error in main function execution:", error);
        } finally {
            isMainRunning = false;
            console.log('main() execution finished.');
        }
    }

    main().catch(e => {
        console.error("Error during initial main() execution:", e);
        isMainRunning = false; // Ensure flag is reset on initial error too
    });

})();
