#include "SocketController.h"


ClientSocketController::ClientSocketController() {
    this->ipAddress = "127.0.0.1";
    this->port = 8888;
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
    return std::string(buffer);
}

// Send request using msghdr
bool ClientSocketController::sendRequest(const SocketRequest& request) {
    std::string header = std::to_string(static_cast<int>(request.requestType));
    std::string message = request.requestData.c_str();

    struct iovec iov[2];
    iov[0].iov_base = (char*)header.c_str();
    iov[0].iov_len = header.size();
    iov[1].iov_base = (char*)message.c_str();
    iov[1].iov_len = message.size();

    struct msghdr msg = {0};
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;

    if (sendmsg(clientSocket, &msg, 0) == -1) {
        return false;
    }
    return true;
}

// Receive response using msghdr
SocketResponse ClientSocketController::receiveResponse() {
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

    if (recvmsg(clientSocket, &msg, 0) == -1) {
        throw std::runtime_error("Failed to receive message");
    }

    std::string header(headerBuffer, iov[0].iov_len);
    std::string message(messageBuffer, iov[1].iov_len);

    SocketResponse response;
    response.responseType = static_cast<ResponseType>(std::stoi(header));
    response.responseData = message;

    return response;
}
