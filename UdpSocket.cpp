#include "UdpSocket.h"
#include <iostream>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

UdpSocket::UdpSocket() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    u_long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);
}

UdpSocket::~UdpSocket() {
    closesocket(sock);
    WSACleanup();
}

bool UdpSocket::bindPort(int port) {
    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = INADDR_ANY;
    localAddr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&localAddr, sizeof(localAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed for port " << port << "\n";
        return false;
    }
    return true;
}

void UdpSocket::sendTo(const void* data, int len, const std::string& ip, int port) {
    sockaddr_in destAddr;
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &destAddr.sin_addr);

    sendto(sock, (const char*)data, len, 0, (struct sockaddr*)&destAddr, sizeof(destAddr));
}

int UdpSocket::receive(void* buffer, int maxLen) {
    sockaddr_in sender;
    socklen_t senderLen = sizeof(sender);
    return recvfrom(sock, (char*)buffer, maxLen, 0, (struct sockaddr*)&sender, &senderLen);
}