#include "Controller/UserController.h"

#include "Utils/RequestTypes.h"


std::string UserController::userLogin(std::string username, std::string employeeId) {
    std::string sendBuffer = std::to_string(static_cast<int>(RequestType::USER_LOGIN)) + "\n" + username + "\n" + employeeId + "\n";
    this->clientSocketController.sendMessage(sendBuffer);
    std::string response = this->clientSocketController.receiveMessage();

    return response;
}

