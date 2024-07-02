#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void initialization() {
    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (err != 0) {
        cerr << "WSAStartup failed: " << err << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    initialization();

    string server_ip = "127.0.0.1"; // 服务器IP地址
    uint16_t server_port = 5566;     // 服务器端口号

    // 创建套接字
    SOCKET s_client = socket(AF_INET, SOCK_STREAM, 0);
    if (s_client == INVALID_SOCKET) {
        cerr << "socket failed: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip.c_str(), &(server_addr.sin_addr));
    server_addr.sin_port = htons(server_port);

    // 连接到服务器
    if (connect(s_client, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cerr << "connect failed: " << WSAGetLastError() << endl;
        closesocket(s_client);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    cout << "Connected to server." << endl;

    // 发送数据
    string message = "Hello, server!";
    if (send(s_client, message.c_str(), message.size(), 0) == SOCKET_ERROR) {
        cerr << "send failed: " << WSAGetLastError() << endl;
    }

    // 接收响应
    char buffer[1024] = { 0 };
    int recv_len = recv(s_client, buffer, sizeof(buffer) - 1, 0);
    if (recv_len > 0) {
        cout << "Server response: " << buffer << endl;
    }
    else {
        cerr << "recv failed: " << WSAGetLastError() << endl;
    }

    // 关闭套接字
    closesocket(s_client);

    // 清理Winsock库
    WSACleanup();

    return 0;
}