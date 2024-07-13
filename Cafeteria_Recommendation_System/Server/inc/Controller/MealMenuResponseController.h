#pragma once

#include <string>
#include <vector>

#include "DTO/MealMenuResponseDTO.h"
#include "DBAccessor/MealMenuResponseDAO.h"

class MealMenuResponseController
{
public:
    std::string getMealMenuResponse(unsigned int mealMenuId, std::string userName);
    std::vector<std::string> getMealMenuResponses(unsigned int mealMenuId);
    bool addMealMenuResponse(int mealMenuId, std::string userName, std::string response);

private:
    MealMenuResponseDAO mealMenuResponseDAO;
};