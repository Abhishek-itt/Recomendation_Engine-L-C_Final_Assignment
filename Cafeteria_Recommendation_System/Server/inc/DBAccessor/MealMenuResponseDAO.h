#pragma once

#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/MealMenuResponseDTO.h"

class MealMenuResponseDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    MealMenuResponseDTO getMealMenuResponse(unsigned int mealMenuId, std::string userName);
    std::vector<MealMenuResponseDTO> getMealMenuResponses(unsigned int mealMenuId);
    bool addMealMenuResponse(MealMenuResponseDTO mealMenuResponse);
};
