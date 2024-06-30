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

    std::string getRolloutMenu(std::string date, std::string mealType);
    bool voteOnRollout(unsigned int rolloutId);

    std::string getMealMenu(std::string date, std::string mealType);

    bool giveResponseOnMealMenu(unsigned int mealMenuId, std::string response);
    void logout();
private:
    ClientSocketController clientSocketController;
    Utils utils;
};