#pragma once

#include <string>

class MealMenuDTO {
public:
    unsigned int mealMenuId;
    unsigned int foodId;
    std::string date;
    std::string mealType;
};
