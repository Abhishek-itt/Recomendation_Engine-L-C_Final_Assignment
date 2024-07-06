#pragma once
#include <iostream>
#include <cstring>
#include <unistd.h>

#include <arpa/inet.h>

#define IP_ADDRESS "127.0.0.1"
#define PORT 8080

class ClientSocketController {
public:
    ClientSocketController();
    ~ClientSocketController();
    void sendMessage(std::string message);
    std::string receiveMessage();

private:
    int clientSocket;
    struct sockaddr_in serverAddress;
    const char* ipAddress;
    int port;

    void createSocket();
    void connectToServer();
    
};
