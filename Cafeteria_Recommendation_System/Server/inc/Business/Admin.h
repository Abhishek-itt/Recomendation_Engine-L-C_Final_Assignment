#pragma once

#include "DTO/UserDTO.h"
#include "DTO/FoodItemDTO.h"
#include "DataAccess/UsersDAO.h"
#include "DataAccess/FoodItemDAO.h"

class Admin
{
public:
    bool login(std::string username, int employeeId);
    bool addFoodItem(FoodItemDTO foodItemDTO);
    bool removeFoodItem(unsigned int foodId);

private:
    UserDTO userDTO;

    UsersDAO usersDAO;
    FoodItemDAO foodItemDAO;
};