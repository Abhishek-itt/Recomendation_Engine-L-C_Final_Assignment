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
    std::string getRecommendationList(int count);
    bool rolloutMealMenu(std::string date, std::string mealType, unsigned int foodId);
    std::string getVotesOnRollout(std::string date, std::string mealType);
    bool rolloutMeal(std::string date, std::string mealType, unsigned int foodId);
    void logout();
};