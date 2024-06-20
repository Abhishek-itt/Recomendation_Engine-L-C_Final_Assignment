#pragma once

#include <iostream>
#include <cstring>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

class SocketServer {
public:
    SocketServer(int port);
    ~SocketServer();
    void acceptConnection();
    void sendMessage(std::string message);
    std::string receiveMessage();

private:
    int port;
    int socketAddressLength;
    struct sockaddr_in socketAddress;

    int serverSocket;
    int requestSocket;


    void createSocket();
    void listenSocket();

};
