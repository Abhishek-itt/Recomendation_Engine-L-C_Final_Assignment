#pragma once
#include "DTO/FoodItemDTO.h"
#include "DataAccess/FoodItemDAO.h"

class User {
public:
    std::vector<FoodItemDTO> getFoodItems();
private:
    FoodItemDAO foodItemDAO;
};