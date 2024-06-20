#pragma once
#include <iostream>
#include <string>

#include "Controller/AdminController.h"
#include "Model/FoodItemDTO.h"

#include "Utils/Serializer.h"   


class AdminView {
    AdminController adminController;
    Utils utils;
public:
    void adminLandingPage();
    void addFoodItem();
    void removeFoodItem();
    void viewAllFoodItems();
    void viewFoodItem();


    void addUser();
};

