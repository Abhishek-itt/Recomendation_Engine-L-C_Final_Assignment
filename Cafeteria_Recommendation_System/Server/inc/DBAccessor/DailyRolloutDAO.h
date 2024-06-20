#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/DailyRolloutDTO.h"

class DailyRolloutDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addDailyRollout(DailyRolloutDTO dailyRolloutDTO);
    DailyRolloutDTO getDailyRollout(unsigned int dailyRolloutId);
    std::vector<DailyRolloutDTO> getDailyRollouts(unsigned int dailyMenuId);
    std::vector<DailyRolloutDTO> getDailyRollouts(std::string userName);
    std::vector<DailyRolloutDTO> getDailyRollouts(unsigned int dailyMenuId, std::string userName);
};