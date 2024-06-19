#pragma once
#include <iostream>
#include <string>
#include <vector>


#include "DataAccess/Database/IDatabaseAccess.h"
#include "DataAccess/Database/MySql/MySqlDBAccess.h"
#include "DTO/UserDTO.h"

class UsersDAO {
private:
    MySqlDBAccess mySqlDBAccess;
public:
    UserDTO getUserByUserName(std::string userName);
};

