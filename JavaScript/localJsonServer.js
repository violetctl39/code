const http = require('http');
const fs = require('fs');
const path = require('path');

const PORT = 3000; // 你可以根据需要更改端口号
const JSON_FILE_PATH = path.join(__dirname, 'selectedCalendarEvents.json'); // 确保json文件与此脚本在同一目录

const server = http.createServer((req, res) => {
    // 只响应对 /selectedCalendarEvents.json 的GET请求
    if (req.method === 'GET' && req.url === '/selectedCalendarEvents.json') {
        fs.readFile(JSON_FILE_PATH, 'utf8', (err, data) => {
            if (err) {
                console.error("读取JSON文件失败:", err);
                res.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
                res.end('服务器内部错误: 无法读取JSON文件。');
                return;
            }
            res.writeHead(200, { 
                'Content-Type': 'application/json; charset=utf-8',
                'Access-Control-Allow-Origin': '*' // 允许所有来源的跨域请求
            });
            res.end(data);
        });
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end('未找到资源。请访问 /selectedCalendarEvents.json');
    }
});

server.listen(PORT, () => {
    console.log(`本地JSON服务器正在运行在 http://localhost:${PORT}/selectedCalendarEvents.json`);
    console.log(`请确保 'selectedCalendarEvents.json' 文件与服务器脚本在同一目录下: ${__dirname}`);
});

// 错误处理
server.on('error', (err) => {
    if (err.code === 'EADDRINUSE') {
        console.error(`端口 ${PORT} 已被占用。请尝试使用其他端口。`);
    } else {
        console.error('服务器发生错误:', err);
    }
});
