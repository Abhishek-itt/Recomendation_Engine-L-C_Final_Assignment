#include "SocketServer.h"

// Constructor
SocketServer::SocketServer(int port) : port(port), serverSocket(-1), requestSocket(-1) {
    createSocket();
    bindSocket();
    listenSocket();
}

// Destructor
SocketServer::~SocketServer() {
    if (requestSocket != -1) {
        close(requestSocket);
    }
    if (serverSocket != -1) {
        close(serverSocket);
    }
}

// Create socket
void SocketServer::createSocket() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw std::runtime_error("Failed to create socket");
    }

    socketAddress.sin_family = AF_INET;
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    socketAddress.sin_port = htons(port);
    socketAddressLength = sizeof(socketAddress);
}

// Bind socket
void SocketServer::bindSocket() {
    if (bind(serverSocket, (struct sockaddr*)&socketAddress, sizeof(socketAddress)) < 0) {
        throw std::runtime_error("Failed to bind socket");
    }
}

// Listen for connections
void SocketServer::listenSocket() {
    if (listen(serverSocket, 3) < 0) {
        throw std::runtime_error("Failed to listen on socket");
    }
}

// Accept connection
void SocketServer::acceptConnection() {
    requestSocket = accept(serverSocket, (struct sockaddr*)&socketAddress, (socklen_t*)&socketAddressLength);
    if (requestSocket < 0) {
        throw std::runtime_error("Failed to accept connection");
    }
}

// Send message
void SocketServer::sendMessage(std::string message) {
    send(requestSocket, message.c_str(), message.size(), 0);
}

// Receive message
std::string SocketServer::receiveMessage() {
    char buffer[1024] = {0};
    memset(buffer, 0, sizeof(buffer));
    recv(requestSocket, buffer, 1024, 0);
    return std::string(buffer);
}

// Send response using msghdr
bool SocketServer::sendResponse(const SocketResponse& response) {
    std::cout << "sending response\n";
    std::string header = std::to_string(static_cast<int>(response.responseType));
    std::string message = response.responseData.c_str();

    struct iovec iov[2];
    iov[0].iov_base = (char*)header.c_str();
    iov[0].iov_len = header.size();
    iov[1].iov_base = (char*)message.c_str();
    iov[1].iov_len = message.size();

    struct msghdr msg = {0};
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;

    if (sendmsg(requestSocket, &msg, 0) == -1) {
        return false;
    }
    return true;
}

// Receive request using msghdr
SocketRequest SocketServer::receiveRequest() {
    char headerBuffer[10];
    char messageBuffer[1024];

    struct iovec iov[2];
    iov[0].iov_base = headerBuffer;
    iov[0].iov_len = sizeof(headerBuffer);
    iov[1].iov_base = messageBuffer;
    iov[1].iov_len = sizeof(messageBuffer);

    struct msghdr msg = {0};
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;

    if (recvmsg(requestSocket, &msg, 0) == -1) {
        throw std::runtime_error("Failed to receive message");
    }

    std::string header(headerBuffer, iov[0].iov_len);
    std::string message(messageBuffer, iov[1].iov_len);

    SocketRequest request;
    request.requestType = static_cast<RequestType>(std::stoi(header));
    request.requestData = message;
    return request;
}
