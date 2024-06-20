#include "Controller/UserController.h"

#include "DTO/UserDTO.h"

std::string UserController::login(std::string userName, std::string employeeId) {
    std::string userType;
    UserDTO user = userDAO.getUser(userName);
    if (user.user_name == "NULL") {
        userType = "NULL";
    } else {
        if (user.employee_id == std::stoi(employeeId)) {
            userType = user.user_type;
        } else {
            userType = "NULL";
        }
    }

    return userType;
}

bool UserController::addUser(std::string firstName, std::string lastName, std::string userName, std::string employeeId, std::string userType) {
    UserDTO user;
    user.first_name = firstName;
    user.last_name = lastName;
    user.user_type = userType;
    user.user_name = userName;
    user.employee_id = std::stoi(employeeId);

    return userDAO.addUser(user);
}