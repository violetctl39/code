const http = require('http');

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end(' RUNOOB Node Test ~ Hello, Node.js!\n');
});

const port = 3000;
server.listen(port, () => {
  console.log(`服务器运行地址：http://localhost:${port}/`);
});
