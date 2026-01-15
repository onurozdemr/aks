#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <string>
#include <winsock2.h>
typedef int socklen_t;

class UdpSocket {
public:
    UdpSocket();
    ~UdpSocket();

    UdpSocket(const UdpSocket&) = delete;
    UdpSocket& operator=(const UdpSocket&) = delete;

    bool bindPort(int port);
    void sendTo(const void* data, int len, const std::string& ip, int port);
    int receive(void* buffer, int maxLen);

private:
    SOCKET sock;
};

#endif 