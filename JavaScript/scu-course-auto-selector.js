// ==UserScript==
// @name         SCU Course Auto Selector
// @namespace    https://github.com/violetctl39/scu-course-auto-selector
// @version      1.0.0
// @description  Auto course selection assistant for Sichuan University - Ultra-fast version with precise matching and batch processing
// @author       violetctl39
// @match        http://zhjw.scu.edu.cn/student/courseSelect/freeCourse/index*
// @match        https://zhjw.scu.edu.cn/student/courseSelect/freeCourse/index*
// @license      MIT
// @homepage     https://github.com/violetctl39/scu-course-auto-selector
// @supportURL   https://github.com/violetctl39/scu-course-auto-selector/issues
// @updateURL    https://github.com/violetctl39/scu-course-auto-selector/raw/main/scu-course-auto-selector.js
// @downloadURL  https://github.com/violetctl39/scu-course-auto-selector/raw/main/scu-course-auto-selector.js
// @grant        none
// @run-at       document-end
// ==/UserScript==

(function() {
    'use strict';

    const CONFIG = {
        targetCourses: [
            {
                courseName: "法医世界：全球大案的深度剖析",
                courseCode: "501265020",
                classNumber: "01",
                priority: 1
            },
            {
                courseName: "中华文化（哲学篇）",
                courseCode: "999009020",
                classNumber: "03",
                priority: 2
            },
            {
                courseName: "静力学与材料力学1（全英文）",
                courseCode: "312015030",
                classNumber: "01",
                priority: 3
            },
            {
                courseName: "概率、随机变量与分布（全英文）",
                courseCode: "312176030",
                classNumber: "02",
                priority: 4
            },
            {
                courseName: "用C++解决ECE问题（全英文）",
                courseCode: "501265020",
                classNumber: "01",
                priority: 5
            },
            {
                courseName: "ECE分析方法（全英文）",
                courseCode: "312177030",
                classNumber: "02",
                priority: 6
            }
        ],

        autoSelect: {
            enabled: true,
            autoSubmit: false
        },

        ui: {
            showPanel: true,
            highlightTarget: true,
            showNotification: true
        }
    };    let selectedCourses = [];
    let controlPanel = null;
    let courseCheckboxCache = new Map();
    let lastQueryTime = 0;

    const utils = {
        log: (message, type = 'info') => {
            const timestamp = new Date().toLocaleTimeString();
            const prefix = `[SCU Course Selector ${timestamp}]`;

            switch(type) {
                case 'success':
                    console.log(`%c${prefix} ✅ ${message}`, 'color: #4CAF50; font-weight: bold;');
                    break;
                case 'error':
                    console.log(`%c${prefix} ❌ ${message}`, 'color: #f44336; font-weight: bold;');
                    break;
                case 'warning':
                    console.log(`%c${prefix} ⚠️ ${message}`, 'color: #FF9800; font-weight: bold;');
                    break;
                default:
                    console.log(`%c${prefix} ℹ️ ${message}`, 'color: #2196F3; font-weight: bold;');
            }
        },

        showNotification: (message, type = 'info') => {
            if (!CONFIG.ui.showNotification) return;

            if (window.urp && window.urp.alert) {
                window.urp.alert(message);
            } else {
                alert(message);
            }
        },

        sleep: (ms) => new Promise(resolve => setTimeout(resolve, ms)),

        waitFor: async (condition, timeout = 5000, interval = 25) => {
            const startTime = Date.now();
            while (Date.now() - startTime < timeout) {
                if (typeof condition === 'function') {
                    const result = condition();
                    if (result) return result;
                } else if (condition) {
                    return condition;
                }
                await utils.sleep(interval);
            }
            return false;
        },

        waitForQueryResult: async (timeout = 1000) => {
            return utils.waitFor(() => {
                const checkboxes = document.querySelectorAll('input[type="checkbox"][name="kcId"]');
                const loadingElement = document.querySelector('.loading, .spinner, [class*="loading"]');
                
                if (loadingElement && loadingElement.style.display !== 'none') {
                    return false;
                }
                
                return checkboxes.length > 0 ? checkboxes : false;
            }, timeout, 10);
        },

        fuzzyMatch: (text, pattern) => {
            if (!pattern) return true;
            return text.toLowerCase().includes(pattern.toLowerCase());
        }
    };    const courseSelector = {
        getAllCourseCheckboxes: () => {
            const cacheKey = 'checkboxes_' + Date.now();
            if (courseCheckboxCache.has(cacheKey) && Date.now() - lastQueryTime < 5000) {
                return courseCheckboxCache.get(cacheKey);
            }
            
            const checkboxes = document.querySelectorAll('input[type="checkbox"][name="kcId"]');
            courseCheckboxCache.set(cacheKey, checkboxes);
            lastQueryTime = Date.now();
            return checkboxes;
        },

        parseCourseInfo: (checkbox) => {
            try {
                const courseData = JSON.parse(checkbox.value);
                return {
                    element: checkbox,
                    id: checkbox.id,
                    courseName: courseData.kcm || '',
                    courseCode: courseData.kch || '',
                    classNumber: courseData.kxh || '',
                    teacher: courseData.skjs || '',
                    capacity: courseData.bkskyl || 0,
                    rawData: courseData
                };
            } catch (e) {
                utils.log(`解析课程信息失败: ${e.message}`, 'error');
                return null;
            }
        },

        findMatchingCourses: () => {
            const checkboxes = courseSelector.getAllCourseCheckboxes();
            const matchingCourses = [];

            checkboxes.forEach(checkbox => {
                const courseInfo = courseSelector.parseCourseInfo(checkbox);
                if (!courseInfo) return;

                CONFIG.targetCourses.forEach(targetCourse => {
                    const codeMatch = courseInfo.courseCode === targetCourse.courseCode;
                    const classMatch = courseInfo.classNumber === targetCourse.classNumber;

                    if (codeMatch && classMatch) {
                        matchingCourses.push({
                            ...courseInfo,
                            priority: targetCourse.priority || 999,
                            targetConfig: targetCourse
                        });
                    }
                });
            });

            return matchingCourses.sort((a, b) => a.priority - b.priority);
        },

        selectCourse: async (courseInfo) => {
            const checkbox = courseInfo.element;

            if (checkbox.disabled) {
                utils.log(`课程 ${courseInfo.courseName}(${courseInfo.courseCode}_${courseInfo.classNumber}) 不可选择（已禁用）`, 'warning');
                return false;
            }

            if (checkbox.checked) {
                utils.log(`课程 ${courseInfo.courseName}(${courseInfo.courseCode}_${courseInfo.classNumber}) 已经选中`, 'info');
                return true;
            }

            try {
                checkbox.checked = true;
                
                const events = ['change', 'click', 'input'];
                events.forEach(eventType => {
                    checkbox.dispatchEvent(new Event(eventType, { bubbles: true }));
                });

                if (checkbox.checked) {
                    utils.log(`✅ 成功选中课程: ${courseInfo.courseName}(${courseInfo.courseCode}_${courseInfo.classNumber})`, 'success');
                    selectedCourses.push(courseInfo);
                    return true;
                }

                checkbox.click();
                await utils.sleep(10);
                
                if (checkbox.checked) {
                    utils.log(`✅ 成功选中课程: ${courseInfo.courseName}(${courseInfo.courseCode}_${courseInfo.classNumber})`, 'success');
                    selectedCourses.push(courseInfo);
                    return true;
                } else {
                    utils.log(`❌ 选择课程失败: ${courseInfo.courseName}(${courseInfo.courseCode}_${courseInfo.classNumber})`, 'error');
                    return false;
                }
            } catch (error) {
                utils.log(`选择课程时出错: ${error.message}`, 'error');
                return false;
            }
        }
    };// 自动选课主逻辑
    const autoSelectHandler = {        // 一键勾选所有目标课程
        selectAllTargetCourses: async () => {
            const btn = document.getElementById('auto-select-btn');
            const resultArea = document.getElementById('result-area');
            const successList = document.getElementById('success-list');
            const failedList = document.getElementById('failed-list');            // 更新按钮状态            btn.disabled = true;
            btn.textContent = '⚡ Selecting...';
            btn.style.background = '#999';

            // 显示结果区域
            resultArea.style.display = 'block';
            successList.innerHTML = '';
            failedList.innerHTML = '';

            const successCourses = [];
            const failedCourses = [];

            utils.log('开始自动勾选所有目标课程...', 'info');            try {
                // 按课程号分组处理目标课程
                const courseGroups = {};
                CONFIG.targetCourses.forEach(course => {
                    if (!courseGroups[course.courseCode]) {
                        courseGroups[course.courseCode] = [];
                    }
                    courseGroups[course.courseCode].push(course);
                });

                // 逐个处理每个课程号
                for (const [courseCode, courseList] of Object.entries(courseGroups)) {
                    utils.log(`正在处理课程号: ${courseCode} (包含 ${courseList.length} 个课序号)`, 'info');

                    // 1. 填写课程号（不填写课序号）
                    const success = await autoSelectHandler.fillCourseInfo({ courseCode });
                    if (!success) {
                        utils.log(`填写课程号失败: ${courseCode}`, 'error');
                        courseList.forEach(course => {
                            failedCourses.push(course);
                            const failedItem = document.createElement('div');
                            failedItem.style.cssText = 'color: #f44336; padding: 2px 0; font-size: 12px;';
                            failedItem.textContent = `❌ ${course.courseName} (填写课程号失败)`;
                            failedList.appendChild(failedItem);
                        });
                        continue;
                    }                    // 2. 点击查询
                    await autoSelectHandler.queryThisCourse();                    // 3. 极速等待查询结果加载完成
                    const queryResult = await utils.waitForQueryResult(1000);
                    if (!queryResult) {
                        utils.log(`查询超时: ${courseCode}`, 'warning');
                        // 继续处理下一个课程
                        continue;
                    }// 4. 查找并勾选该课程号下的所有目标课序号 - 批量并发处理
                    const matchingCourses = courseSelector.findMatchingCourses();

                    // 并发处理同一课程号下的所有课序号 - 无等待极速版本
                    const selectPromises = courseList.map(async (targetCourse) => {
                        const targetMatch = matchingCourses.find(course =>
                            course.courseCode === targetCourse.courseCode &&
                            course.classNumber === targetCourse.classNumber
                        );

                        if (targetMatch) {
                            const result = await courseSelector.selectCourse(targetMatch);

                            if (result) {
                                successCourses.push(targetMatch);
                                const successItem = document.createElement('div');
                                successItem.style.cssText = 'color: #4CAF50; padding: 2px 0; font-size: 12px;';
                                successItem.textContent = `✅ ${targetCourse.courseName} (${targetCourse.courseCode}_${targetCourse.classNumber})`;
                                successList.appendChild(successItem);
                                utils.log(`✅ 成功勾选: ${targetCourse.courseName} (${targetCourse.classNumber})`, 'success');
                                return { success: true, course: targetCourse };
                            } else {
                                failedCourses.push(targetCourse);
                                const failedItem = document.createElement('div');
                                failedItem.style.cssText = 'color: #f44336; padding: 2px 0; font-size: 12px;';
                                failedItem.textContent = `❌ ${targetCourse.courseName} (勾选失败)`;
                                failedList.appendChild(failedItem);
                                return { success: false, course: targetCourse };
                            }
                        } else {
                            utils.log(`未找到课序号: ${targetCourse.classNumber} (课程号: ${targetCourse.courseCode})`, 'warning');
                            failedCourses.push(targetCourse);
                            const failedItem = document.createElement('div');
                            failedItem.style.cssText = 'color: #f44336; padding: 2px 0; font-size: 12px;';
                            failedItem.textContent = `❌ ${targetCourse.courseName} (未找到课序号 ${targetCourse.classNumber})`;
                            failedList.appendChild(failedItem);
                            return { success: false, course: targetCourse };
                        }
                    });

                    // 极速并发处理 - 所有课序号同时勾选
                    const results = await Promise.all(selectPromises);// 每个课程号处理完后极短等待
                    await utils.sleep(100);
                }

                // 显示最终结果
                const totalTargets = CONFIG.targetCourses.length;
                const successCount = successCourses.length;
                const failedCount = failedCourses.length;

                if (successCount > 0) {
                    utils.log(`✅ 成功勾选 ${successCount} 门课程`, 'success');
                    utils.showNotification(`✅ 成功勾选 ${successCount}/${totalTargets} 门课程！请手动提交选课申请。`);
                }

                if (failedCount > 0) {
                    utils.log(`❌ ${failedCount} 门课程勾选失败`, 'error');
                }

                // 更新已选课程计数
                selectedCourses = successCourses;
                updateControlPanel();

            } catch (error) {
                utils.log(`勾选课程时发生错误: ${error.message}`, 'error');
                const errorItem = document.createElement('div');
                errorItem.style.cssText = 'color: #f44336; padding: 5px; background: #ffebee; border-radius: 3px;';
                errorItem.textContent = `❌ 发生错误: ${error.message}`;
                failedList.appendChild(errorItem);            } finally {
                // 恢复按钮状态                btn.disabled = false;
                btn.textContent = '⚡ Auto Select Courses';
                btn.style.background = '#4CAF50';
            }},        // 填写课程信息到搜索框（只填写课程号） - 极速版本
        fillCourseInfo: async (targetCourse) => {
            try {
                // 查找课程号输入框
                const kchInput = document.getElementById('kch') ||
                                document.querySelector('input[name="kch"]') ||
                                document.querySelector('input[placeholder*="课程号"]') ||
                                document.querySelector('input[placeholder*="课程代码"]') ||
                                document.querySelector('input[id*="course"]');

                if (!kchInput) {
                    utils.log('未找到课程号输入框，正在查找其他可能的输入框...', 'warning');

                    // 尝试查找其他可能的输入框
                    const allInputs = document.querySelectorAll('input[type="text"]');
                    utils.log(`找到 ${allInputs.length} 个文本输入框`, 'info');

                    for (let i = 0; i < allInputs.length; i++) {
                        const input = allInputs[i];
                        utils.log(`输入框 ${i}: id="${input.id}", name="${input.name}", placeholder="${input.placeholder}"`, 'info');
                    }

                    return false;
                }

                // 极速填写：直接设置值，批量触发事件
                kchInput.value = '';
                kchInput.focus();
                kchInput.value = targetCourse.courseCode;

                // 批量触发所有可能的事件
                const events = ['input', 'change', 'blur', 'keyup'];
                events.forEach(eventType => {
                    kchInput.dispatchEvent(new Event(eventType, { bubbles: true }));
                });

                utils.log(`已填写课程号: ${targetCourse.courseCode}（将查询该课程的所有课序号）`, 'info');
                await utils.sleep(150); // 极短等待
                return true;

            } catch (error) {
                utils.log(`填写课程信息时出错: ${error.message}`, 'error');
                return false;
            }
        },

        // 点击查询按钮
        queryThisCourse: async () => {
            try {
                // 查找查询按钮
                const queryButton = document.getElementById('queryButton') ||
                                  document.querySelector('button[onclick*="guolv"]') ||
                                  document.querySelector('input[value="查询"]') ||
                                  document.querySelector('button:contains("查询")') ||
                                  document.querySelector('[onclick*="query"]');

                if (queryButton) {
                    utils.log('点击查询按钮...', 'info');
                    queryButton.click();
                    return true;
                } else {
                    // 如果找不到按钮，尝试调用查询函数
                    if (window.guolv && typeof window.guolv === 'function') {
                        utils.log('调用查询函数...', 'info');
                        window.guolv(1);
                        return true;
                    } else {
                        utils.log('未找到查询按钮或查询函数', 'error');
                        return false;
                    }
                }
            } catch (error) {
                utils.log(`执行查询时出错: ${error.message}`, 'error');
                return false;
            }
        },

        // 刷新课程列表
        refreshCourseList: async () => {
            try {
                // 使用页面的查询函数刷新课程列表
                if (window.guolv && typeof window.guolv === 'function') {
                    window.guolv(1);
                    await utils.sleep(2000); // 等待数据加载
                } else {
                    // 如果没有guolv函数，尝试点击查询按钮
                    const queryButton = document.getElementById('queryButton');
                    if (queryButton) {
                        queryButton.click();
                        await utils.sleep(2000);
                    }
                }
            } catch (error) {
                utils.log(`刷新课程列表时出错: ${error.message}`, 'error');
            }
        }
    };

    // 创建控制面板
    const createControlPanel = () => {
        if (!CONFIG.ui.showPanel) return;

        const panel = document.createElement('div');
        panel.id = 'auto-select-panel';
        panel.style.cssText = `
            position: fixed;
            top: 20px;
            right: 20px;
            width: 300px;
            background: white;
            border: 2px solid #2196F3;
            border-radius: 8px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.15);
            z-index: 10000;
            font-family: Arial, sans-serif;
            font-size: 14px;
        `;        panel.innerHTML = `
            <div id="panel-header" style="background: #2196F3; color: white; padding: 10px; border-radius: 6px 6px 0 0; font-weight: bold; cursor: move; user-select: none;">
                🎯 SCU Course Auto Selector
                <button id="toggle-panel" style="float: right; background: none; border: none; color: white; cursor: pointer;">－</button>
            </div>            <div id="panel-content" style="padding: 15px;">
                <div style="margin-bottom: 10px;">
                    <strong>Selected:</strong> <span id="selected-count">0</span> / ${CONFIG.targetCourses.length}
                </div>                <div style="margin-bottom: 15px;">
                    <button id="auto-select-btn" style="background: #4CAF50; color: white; border: none; padding: 10px 20px; border-radius: 4px; cursor: pointer; width: 100%; font-size: 16px; font-weight: bold;">⚡ Auto Select Courses</button>
                </div>
                <div id="result-area" style="margin-bottom: 15px; display: none;">
                    <div style="background: #f5f5f5; padding: 10px; border-radius: 4px; margin-bottom: 10px;">
                        <strong>Results:</strong>
                        <div id="success-list" style="margin-top: 5px;"></div>
                        <div id="failed-list" style="margin-top: 5px;"></div>
                    </div>
                </div>
                <div style="border-top: 1px solid #eee; padding-top: 10px;">                    <strong>Target Courses (${CONFIG.targetCourses.length}):</strong>
                    <div id="target-courses" style="max-height: 120px; overflow-y: auto; margin-top: 5px; font-size: 12px;">
                        ${CONFIG.targetCourses.map(course =>
                            `<div style="padding: 2px 0; color: #666;">• ${course.courseName} (${course.courseCode}_${course.classNumber})</div>`
                        ).join('')}
                    </div>                    <div style="margin-top: 10px; padding: 8px; background: #f0f0f0; border-radius: 4px; font-size: 11px; color: #666;">
                        ⚡ Ultra-fast version with 10ms-level checks, batch concurrent processing, and optimized event handling.
                    </div>
                    
                    <div style="margin-top: 8px; padding: 6px; background: #e3f2fd; border-radius: 4px; font-size: 10px; color: #1976d2; text-align: center;">
                        Made with ❤️ by <strong>violetctl39</strong>
                    </div>
                </div>
            </div>
        `;

        document.body.appendChild(panel);
        controlPanel = panel;        // 绑定事件
        document.getElementById('auto-select-btn').addEventListener('click', autoSelectHandler.selectAllTargetCourses);// 面板折叠功能
        const toggleBtn = document.getElementById('toggle-panel');
        const content = document.getElementById('panel-content');
        let isCollapsed = false;

        toggleBtn.addEventListener('click', () => {
            if (isCollapsed) {
                content.style.display = 'block';
                toggleBtn.textContent = '－';
            } else {
                content.style.display = 'none';
                toggleBtn.textContent = '＋';
            }
            isCollapsed = !isCollapsed;
        });

        // 面板拖动功能
        const header = document.getElementById('panel-header');
        let isDragging = false;
        let dragStartX, dragStartY, panelStartX, panelStartY;

        header.addEventListener('mousedown', (e) => {
            // 如果点击的是折叠按钮，不触发拖动
            if (e.target.id === 'toggle-panel') return;

            isDragging = true;
            dragStartX = e.clientX;
            dragStartY = e.clientY;

            const rect = panel.getBoundingClientRect();
            panelStartX = rect.left;
            panelStartY = rect.top;

            document.addEventListener('mousemove', onMouseMove);
            document.addEventListener('mouseup', onMouseUp);

            // 防止文本选择
            e.preventDefault();
        });

        function onMouseMove(e) {
            if (!isDragging) return;

            const deltaX = e.clientX - dragStartX;
            const deltaY = e.clientY - dragStartY;

            let newX = panelStartX + deltaX;
            let newY = panelStartY + deltaY;

            // 限制面板不能拖出屏幕
            const maxX = window.innerWidth - panel.offsetWidth;
            const maxY = window.innerHeight - panel.offsetHeight;

            newX = Math.max(0, Math.min(newX, maxX));
            newY = Math.max(0, Math.min(newY, maxY));

            panel.style.left = newX + 'px';
            panel.style.top = newY + 'px';
            panel.style.right = 'auto'; // 移除right定位
        }

        function onMouseUp() {
            isDragging = false;
            document.removeEventListener('mousemove', onMouseMove);
            document.removeEventListener('mouseup', onMouseUp);
        }
    };    // 更新控制面板
    const updateControlPanel = () => {
        if (!controlPanel) return;

        const selectedCountEl = document.getElementById('selected-count');
        if (selectedCountEl) selectedCountEl.textContent = selectedCourses.length;
    };

    // 高亮目标课程
    const highlightTargetCourses = () => {
        if (!CONFIG.ui.highlightTarget) return;

        const matchingCourses = courseSelector.findMatchingCourses();

        matchingCourses.forEach(course => {
            const row = course.element.closest('tr');
            if (row) {
                row.style.backgroundColor = '#e8f5e8';
                row.style.border = '2px solid #4CAF50';
                  // 添加标识
                const nameCell = row.querySelector('td:nth-child(3)');
                if (nameCell && !nameCell.querySelector('.target-mark')) {
                    const mark = document.createElement('span');
                    mark.className = 'target-mark';
                    mark.style.cssText = 'color: #4CAF50; font-weight: bold; margin-left: 5px;';
                    mark.textContent = `🎯 ${course.courseCode}_${course.classNumber}`;
                    nameCell.appendChild(mark);
                }
            }
        });
    };

    const init = () => {
        utils.log('SCU Course Auto Selector loaded successfully', 'success');

        if (document.readyState === 'loading') {
            document.addEventListener('DOMContentLoaded', () => {
                setTimeout(init, 1000);
            });
            return;
        }

        createControlPanel();

        setTimeout(() => {
            highlightTargetCourses();
        }, 2000);

        const observer = new MutationObserver(() => {
            setTimeout(highlightTargetCourses, 500);
        });

        const targetNode = document.getElementById('xirxkxkbody');
        if (targetNode) {
            observer.observe(targetNode, { childList: true, subtree: true });
        }

        utils.log(`Configured ${CONFIG.targetCourses.length} target courses`, 'info');
        CONFIG.targetCourses.forEach(course => {
            utils.log(`Target: ${course.courseName} (${course.courseCode}_${course.classNumber})`, 'info');
        });
        utils.showNotification('🎯 SCU Course Auto Selector is ready! Click "Auto Select Courses" to start.');
    };

    // 启动
    init();

})();
