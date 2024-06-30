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
    bool addMealMenu(MealMenuDTO mealMenuDTO);
    MealMenuDTO getMealMenu(unsigned int mealMenuId);
    std::vector<MealMenuDTO> getMealMenus(unsigned int foodId);
};
