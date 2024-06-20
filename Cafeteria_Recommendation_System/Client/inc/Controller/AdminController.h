#pragma once 
#include <string>
#include <sstream>
#include <vector>

#include "SocketController.h"

class AdminController
{
    ClientSocketController clientSocketController;

public:
    // std::vector<FoodItemDTO> fetchFoodItemList();
    // FoodItemDTO fetchFoodItem(unsigned int foodId);
    // bool addFoodToMenu(FoodItemDTO FoodItemDTO);
    // bool removeFoodItem(unsigned int foodId);
    // void updateFoodItem(unsigned int foodId, FoodItemDTO FoodItemDTO);
    bool adminLogin(std::string username, int employeeId);
    void send (std::string sendBuffer);

    
};
