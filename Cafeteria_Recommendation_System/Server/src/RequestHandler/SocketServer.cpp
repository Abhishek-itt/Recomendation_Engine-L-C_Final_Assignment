#include "RequestHandler/SocketServer.h"

SocketServer::SocketServer(int port) : port(port), serverSocket(-1), requestSocket(-1) {
    createSocket();
    listenSocket();
}

SocketServer::~SocketServer() {
    if (requestSocket != -1) {
        close(requestSocket);
    }
    if (serverSocket != -1) {
        close(serverSocket);
    }
}

void SocketServer::createSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw std::runtime_error("Failed to create socket");
    }

    socketAddress.sin_family = AF_INET;
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    socketAddress.sin_port = htons(port);
    socketAddressLength = sizeof(socketAddress);

    if (bind(serverSocket, (struct sockaddr*)&socketAddress, sizeof(socketAddress)) < 0) {
        throw std::runtime_error("Failed to bind socket");
    }
}

void SocketServer::listenSocket() {
    if (listen(serverSocket, 3) < 0) {
        throw std::runtime_error("Failed to listen on socket");
    }
}

void SocketServer::acceptConnection() {
    requestSocket = accept(serverSocket, (struct sockaddr*)&socketAddress, (socklen_t*)&socketAddressLength);
    if (requestSocket < 0) {
        throw std::runtime_error("Failed to accept connection");
    }
}

void SocketServer::sendMessage(std::string message) {
    send(requestSocket, message.c_str(), message.size(), 0);
}

std::string SocketServer::receiveMessage() {
    char buffer[1024] = {0};
    memset(buffer, 0, sizeof(buffer));
    int bytesRead = read(requestSocket, buffer, 1024);
    if (bytesRead < 0) {
        throw std::runtime_error("Failed to read from socket");
    }
    std::cout << "Bytes read: " << bytesRead << std::endl;
    return std::string(buffer);
}
