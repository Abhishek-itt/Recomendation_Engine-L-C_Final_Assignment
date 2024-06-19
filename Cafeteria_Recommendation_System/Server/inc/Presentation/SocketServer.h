#pragma once

#include <iostream>
#include <cstring>
#include <unistd.h>

#include <arpa/inet.h>

#include "DataAccess/Database/IDatabaseAccess.h"
#include "RequestTypes.h"

class SocketServer {
public:
    SocketServer(int port);
    ~SocketServer();
    void acceptConnection();
    void sendMessage(std::string message);
    std::string receiveMessage();

    bool sendResponse(const SocketResponse& response);
    SocketRequest receiveRequest();


private:
    int port;
    int socketAddressLength;

    int serverSocket;
    int requestSocket;

    struct sockaddr_in socketAddress;

    void createSocket();
    void bindSocket();
    void listenSocket();

};
