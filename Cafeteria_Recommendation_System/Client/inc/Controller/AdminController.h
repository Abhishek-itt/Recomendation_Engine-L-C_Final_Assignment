#pragma once 
#include <string>
#include <sstream>
#include <vector>

#include "SocketController.h"
#include "Utils/Serializer.h" 

#include "Utils/RequestTypes.h"

class AdminController
{
    ClientSocketController clientSocketController;
    Utils utils;

public:
    bool addFoodItem(std::vector<std::string> foodItemData);
    bool removeFoodItem(unsigned int foodId);
    std::string getFoodItem(unsigned int foodId);
    std::string getFoodItemList();

    bool addUser(std::vector<std::string> userData);

    void logout();
};
