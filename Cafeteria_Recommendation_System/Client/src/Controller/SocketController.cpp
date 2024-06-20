#include "Controller/SocketController.h"


ClientSocketController::ClientSocketController() {
    this->ipAddress = "127.0.0.1";
    this->port = 8080;
    createSocket();
    connectToServer();
}

// Destructor
ClientSocketController::~ClientSocketController() {
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

// Create socket
void ClientSocketController::createSocket() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw std::runtime_error("Failed to create socket");
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, ipAddress, &serverAddress.sin_addr) <= 0) {
        throw std::runtime_error("Invalid address/ Address not supported");
    }
}

// Connect to server
void ClientSocketController::connectToServer() {
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        throw std::runtime_error("Connection failed");
    }
}

// Send message
void ClientSocketController::sendMessage(std::string message) {
    send(clientSocket, message.c_str(), message.size(), 0);
}

// Receive message
std::string ClientSocketController::receiveMessage() {
    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Bytes read: " << buffer << std::endl;
    return std::string(buffer);
}
