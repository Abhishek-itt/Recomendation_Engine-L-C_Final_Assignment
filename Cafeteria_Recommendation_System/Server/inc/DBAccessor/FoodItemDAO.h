#pragma once 

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/FoodItemDTO.h"


class FoodItemDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addFoodItem(FoodItemDTO foodItemDTO);
    bool removeFoodItem(unsigned int foodItemI);
    bool updateFoodItem(FoodItemDTO foodItemDTO);
    FoodItemDTO getFoodItem(unsigned int foodItemId);
    std::vector<FoodItemDTO> getFoodItems();
};
