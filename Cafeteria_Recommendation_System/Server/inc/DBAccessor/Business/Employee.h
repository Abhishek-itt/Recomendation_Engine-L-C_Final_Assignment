#pragma once

#include "DTO/UserDTO.h"
#include "DataAccess/UsersDAO.h"

class Employee {
public:
    bool login(std::string username, int employeeId);

private:
    UsersDAO usersDAO;
    UserDTO userDTO;
};