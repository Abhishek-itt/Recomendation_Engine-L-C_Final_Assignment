#pragma once 
#include <string>
#include <sstream>
#include <vector>

#include "SocketController.h"
#include "Utils/Serializer.h" 

#include "Utils/RequestTypes.h"

class EmployeeController
{
public:
    std::string getFoodItem(unsigned int foodId);
    std::string getFoodItemList();
    bool giveFeedback(unsigned int foodId, std::string username, unsigned int tasteRating, unsigned int qualityRating, std::string review);
    std::string getFeedback(unsigned int foodId);
    void logout();
private:
    ClientSocketController clientSocketController;
    Utils utils;
};