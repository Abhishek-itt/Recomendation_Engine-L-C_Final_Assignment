#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/MealMenuDTO.h"

class MealMenuDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    MealMenuDTO getMealMenu(std::string date, std::string mealType);
    bool addMealMenu(MealMenuDTO mealMenu);

    unsigned int getMealMenuCount(unsigned int foodId);
};
