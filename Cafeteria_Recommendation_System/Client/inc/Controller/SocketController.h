#ifndef SOCKETCONTROLLER_H
#define SOCKETCONTROLLER_H

#include <iostream>
#include <cstring>
#include <unistd.h>

#include <arpa/inet.h>

#include "RequestTypes.h"




class ClientSocketController {
public:
    ClientSocketController();
    ~ClientSocketController();
    void sendMessage(std::string message);
    std::string receiveMessage();

    bool sendRequest(const SocketRequest& request);
    SocketResponse receiveResponse();


private:
    int clientSocket;
    struct sockaddr_in serverAddress;
    const char* ipAddress;
    int port;

    void createSocket();
    void connectToServer();
};

#endif // SOCKETCONTROLLER_H