#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/DailyMenuDTO.h"

class DailyMenuDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addDailyMenu(DailyMenuDTO dailyMenuDTO);
    DailyMenuDTO getDailyMenu(unsigned int dailyMenuId);
};
