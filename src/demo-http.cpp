// g++ -std=c++17 src/demo-http.cpp -o demo-http
// sudo ./demo-http 8080   (port < 1024 cần sudo trên Unix)


#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <ctime>
#include <cstring>

class HttpResponse {
public:
    std::string body;
    std::string contentType = "text/html; charset=utf-8";
    int status = 200;
    std::string statusText = "OK";

    std::string toString() const {
        std::ostringstream o;
        o << "HTTP/1.1 " << status << " " << statusText << "\r\n";
        o << "Content-Type: " << contentType << "\r\n";
        o << "Content-Length: " << body.size() << "\r\n";
        o << "Connection: close\r\n";
        o << "\r\n";
        o << body;
        return o.str();
    }
};

class HttpRequest {
public:
    std::string method;
    std::string path;
    std::string version;
};

class HttpConnection {
    int clientFd;

public:
    explicit HttpConnection(int fd) : clientFd(fd) {}
    ~HttpConnection() { close(clientFd); }

    void handle() {
        char buffer[4096];
        ssize_t n = recv(clientFd, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0) return;
        buffer[n] = '\0';

        std::string reqStr(buffer);
        HttpRequest req = parseRequest(reqStr);

        HttpResponse resp = route(req);

        std::string out = resp.toString();
        send(clientFd, out.data(), out.size(), 0);
    }

private:
    HttpRequest parseRequest(const std::string &reqStr) {
        HttpRequest req;
        std::istringstream in(reqStr);
        in >> req.method >> req.path >> req.version;
        return req;
    }

    HttpResponse route(const HttpRequest &req) {
        if (req.method != "GET") {
            return makeResponse("<h1>405 Method Not Allowed</h1>", 405, "Method Not Allowed");
        }

        if (req.path == "/" || req.path == "/index.html") {
            return makeResponse(demoPage(), 200, "OK");
        }

        if (req.path == "/time") {
            time_t t = time(nullptr);
            std::string body = "Server time: " + std::string(ctime(&t));
            HttpResponse r;
            r.body = body;
            r.contentType = "text/plain; charset=utf-8";
            return r;
        }

        return makeResponse("<h1>404 Not Found</h1>", 404, "Not Found");
    }

    HttpResponse makeResponse(const std::string &body, int status, const std::string &text) {
        HttpResponse resp;
        resp.body = body;
        resp.status = status;
        resp.statusText = text;
        return resp;
    }

    std::string demoPage() const {
        return R"HTML(
<!doctype html>
<html lang="vi">
<head>
<meta charset="utf-8">
<title>Demo HTTP Server OOP</title>
<style>
  body { font-family: sans-serif; background:#f5f6fa; padding:30px; }
  .card { background:white; padding:20px; border-radius:8px; box-shadow:0 2px 6px rgba(0,0,0,0.1); }
  button { padding:8px 12px; border:none; background:#4a90e2; color:white; border-radius:5px; cursor:pointer; }
</style>
</head>
<body>
<div class="card">
  <h1>HTTP Server (OOP - C++)</h1>
  <p>Trang này được phục vụ từ class <b>HttpServer</b>.</p>
  <button id="btn">Lấy thời gian từ server</button>
  <pre id="resp" style="background:#f0f0f0;padding:10px;margin-top:10px;border-radius:5px;"></pre>
</div>

<script>
document.getElementById('btn').addEventListener('click', async () => {
  const r = await fetch('/time');
  const txt = await r.text();
  document.getElementById('resp').textContent = txt;
});
</script>
</body>
</html>
)HTML";
    }
};

class HttpServer {
    int port;
    int serverFd;
    bool running = false;

public:
    explicit HttpServer(int p) : port(p), serverFd(-1) {}

    bool start() {
        serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverFd == -1) {
            std::cerr << "socket() failed: " << strerror(errno) << "\n";
            return false;
        }

        int opt = 1;
        setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        if (bind(serverFd, (sockaddr *)&addr, sizeof(addr)) == -1) {
            std::cerr << "bind() failed: " << strerror(errno) << "\n";
            close(serverFd);
            return false;
        }

        if (listen(serverFd, 10) == -1) {
            std::cerr << "listen() failed: " << strerror(errno) << "\n";
            close(serverFd);
            return false;
        }

        running = true;
        std::cout << "HTTP server đang chạy tại http://localhost:" << port << "\n";
        loop();
        return true;
    }

private:
    void loop() {
        while (running) {
            sockaddr_in clientAddr{};
            socklen_t len = sizeof(clientAddr);
            int clientFd = accept(serverFd, (sockaddr *)&clientAddr, &len);
            if (clientFd == -1) continue;

            // mỗi client xử lý ở luồng riêng (đơn giản)
            std::thread([clientFd]() {
                HttpConnection conn(clientFd);
                conn.handle();
            }).detach();
        }
    }
};

int main(int argc, char *argv[]) {
    int port = 8080;
    if (argc >= 2) port = std::stoi(argv[1]);

    HttpServer server(port);
    if (!server.start()) {
        std::cerr << "Không thể khởi động server.\n";
        return 1;
    }
    return 0;
}
