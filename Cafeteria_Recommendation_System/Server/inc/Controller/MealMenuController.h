#pragma once

#include <string>
#include <vector>

#include "DBAccessor/MealMenuDAO.h"

class MealMenuController {
public:
    bool addMealMenu(std::string date, std::string mealType, unsigned int foodId);
    std::string getMealMenu(std::string date, std::string mealType);

private:
    MealMenuDAO mealMenuDAO;
};