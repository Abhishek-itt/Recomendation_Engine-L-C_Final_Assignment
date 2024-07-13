#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "DTO/RolloutMenuDTO.h"

#include "DBAccessor/RolloutMenuDAO.h"

class RolloutController {
public:
    bool addRolloutMenu(std::string date, std::string mealType, unsigned int foodId);
    std::vector<std::string> getRolloutMenu(std::string date, std::string mealType);
    unsigned int getFoodId(unsigned int rolloutId);
    
private:
    RolloutMenuDAO rolloutMenuDAO;
};   