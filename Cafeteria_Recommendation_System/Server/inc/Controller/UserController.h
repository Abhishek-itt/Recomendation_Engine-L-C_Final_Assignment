#include <iostream>
#include <string>

#include "DBAccessor/UsersDAO.h"

class UserController {
public:
    std::string login(std::string userName, std::string employeeId);
    bool addUser(std::string firstName, std::string lastName, std::string userName, std::string employeeId, std::string userType);

    std::vector<std::string> getUserDietPreference(std::string userName);
    bool updateUserDietPreference(std::string userName, std::string foodTypePreference, std::string spiceLevelPreference, std::string cuisinePreference, std::string preferSweet);

private:
    UsersDAO userDAO;
};