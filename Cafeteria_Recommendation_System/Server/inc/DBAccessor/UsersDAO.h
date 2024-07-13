#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/UserDTO.h"
#include "DTO/userPreferenceDTO.h"


class UsersDAO {
private:
    MySqlDBAccess mySqlDBAccess;
public:
    UserDTO getUser(std::string userName);
    bool addUser(UserDTO user);
    bool updateUser(UserDTO user);
    bool deleteUser(std::string userName);

    bool updatePreference(std::string userName, UserPreferenceDTO userPreference);

    UserPreferenceDTO getPreference(std::string userName);
};

