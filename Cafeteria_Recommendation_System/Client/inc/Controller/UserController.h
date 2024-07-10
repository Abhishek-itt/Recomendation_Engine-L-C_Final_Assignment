#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Controller/SocketController.h"
#include "Utils/Serializer.h"

class UserController
{
public:
        std::string userLogin(std::string username, std::string employeeId);

private:
        ClientSocketController clientSocketController;
        Utils utils;
};
