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

    string server_ip = "127.0.0.1"; // ������IP��ַ
    uint16_t server_port = 5566;     // �������˿ں�

    // �����׽���
    SOCKET s_client = socket(AF_INET, SOCK_STREAM, 0);
    if (s_client == INVALID_SOCKET) {
        cerr << "socket failed: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // ���÷�������ַ��Ϣ
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip.c_str(), &(server_addr.sin_addr));
    server_addr.sin_port = htons(server_port);

    // ���ӵ�������
    if (connect(s_client, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cerr << "connect failed: " << WSAGetLastError() << endl;
        closesocket(s_client);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    cout << "Connected to server." << endl;

    // ��������
    string message = "Hello, server!";
    if (send(s_client, message.c_str(), message.size(), 0) == SOCKET_ERROR) {
        cerr << "send failed: " << WSAGetLastError() << endl;
    }

    // ������Ӧ
    char buffer[1024] = { 0 };
    int recv_len = recv(s_client, buffer, sizeof(buffer) - 1, 0);
    if (recv_len > 0) {
        cout << "Server response: " << buffer << endl;
    }
    else {
        cerr << "recv failed: " << WSAGetLastError() << endl;
    }

    // �ر��׽���
    closesocket(s_client);

    // ����Winsock��
    WSACleanup();

    return 0;
}