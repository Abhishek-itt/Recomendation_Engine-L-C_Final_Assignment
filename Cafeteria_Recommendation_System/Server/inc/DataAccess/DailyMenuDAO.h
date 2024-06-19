#pragma once

#include <vector>

#include "DailyMenuDTO.h"
#include "IDatabaseAccess.h"
#include "DataAccess/Database/MySql/MySqlDBAccess.h"

class DailyMenuDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addDailyMenu(DailyMenuDTO dailyMenuDTO);
    bool removeDailyMenu(unsigned int dailyMenuId);
    void updateDailyMenu(DailyMenuDTO dailyMenuDTO);
    DailyMenuDTO getDailyMenu(unsigned int dailyMenuId);
    std::vector<DailyMenuDTO> getDailyMenus();
};