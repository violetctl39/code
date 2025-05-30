class Assignment {
    constructor(title, calendarName, end) {
        this.title = title;
        this.calendarName = calendarName;
        this.end = end;
    }

    display() {
        console.log(`作业: ${this.title}`);
        console.log(`课程: ${this.calendarName}`);
        console.log(`截止时间: ${new Date(this.end).toLocaleString()}`);
        console.log('---');
    }
}

async function loadAssignments(filePath) {
    try {
        const response = await fetch(filePath);
        if (!response.ok) {
            if (response.status === 500) {
                console.error("服务器错误 (HTTP 500): 无法从指定的URL加载数据。请检查服务器状态或URL是否正确。");
            } else {
                throw new Error(`HTTP error! status: ${response.status}`);
            }
            return []; // 在发生服务器错误时返回空数组
        }
        const jsonData = await response.json();
        const assignments = jsonData.map(item => new Assignment(item.title, item.calendarName, item.end));
        return assignments;
    } catch (error) {
        console.error("加载或解析JSON文件失败:", error);
        return [];
    }
}

// 主程序逻辑
async function main() {
    const assignments = await loadAssignments('http://localhost:3000/selectedCalendarEvents.json');

    if (assignments.length > 0) {
        console.log("成功加载作业：");
        assignments.forEach(assignment => assignment.display());
    } else {
        console.log("未能加载任何作业。");
    }
}

main();
