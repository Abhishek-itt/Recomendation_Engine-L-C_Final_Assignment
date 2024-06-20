#include <iostream>
#include <string>

#include "DBAccessor/UsersDAO.h"

class UserController {
public:
    std::string login(std::string userName, std::string employeeId);
    bool addUser(std::string firstName, std::string lastName, std::string userName, std::string employeeId, std::string userType);

private:
    UsersDAO userDAO;
};