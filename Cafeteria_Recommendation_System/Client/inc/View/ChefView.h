#pragma once
#include <iostream>
#include <string>

#include "Controller/ChefController.h"

#include "Utils/Serializer.h"
#include "Utils/RequestTypes.h"

class ChefView {
    ChefController chefController;
    Utils utils;
public:
    void chefLandingPage();
    void logout();
    
    void viewAllFoodItems();
    void viewFoodItem();
    void getRecommendedList();
    
};