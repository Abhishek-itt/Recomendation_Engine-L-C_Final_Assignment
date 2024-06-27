#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "SocketController.h"

#include "Utils/Serializer.h"
#include "Utils/RequestTypes.h"

class ChefController
{
    ClientSocketController clientSocketController;
    Utils utils;
public:
    std::string getFoodItemList();
    std::string getFoodItem(unsigned int foodId);
    void logout();
};