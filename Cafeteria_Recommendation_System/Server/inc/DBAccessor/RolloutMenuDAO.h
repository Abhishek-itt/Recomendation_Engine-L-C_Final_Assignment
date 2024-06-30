#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/RolloutMenuDTO.h"

class RolloutMenuDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    std::vector<RolloutMenuDTO> getRollout(std::string date, std::string mealType);
    bool addRollout(RolloutMenuDTO rollout);

    unsigned int getRolloutCount(unsigned int foodId);
};