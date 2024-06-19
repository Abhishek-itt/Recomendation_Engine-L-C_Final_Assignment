#pragma once 
#include <string>
#include <sstream>
#include <vector>

#include "DTO/FoodItemDTO.h"
#include "SocketController.h"

#include "RequestTypes.h"

class AdminController
{
    ClientSocketController clientSocketController;
    SocketRequest socketRequest;
    SocketResponse socketResponse;

public:
    std::vector<FoodItemDTO> fetchFoodItemList();
    FoodItemDTO fetchFoodItem(unsigned int foodId);
    bool addFoodToMenu(FoodItemDTO FoodItemDTO);
    bool removeFoodItem(unsigned int foodId);
    void updateFoodItem(unsigned int foodId, FoodItemDTO FoodItemDTO);
    bool adminLogin(std::string username, int employeeId);
};
