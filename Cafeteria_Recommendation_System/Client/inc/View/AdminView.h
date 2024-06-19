#pragma once
#include <iostream>
#include <string>

#include "Controller/AdminController.h"

#include "DTO/FoodItemDTO.h"

class AdminView {
    AdminController adminController;
public:
    void adminLoginPage();
    void adminLandingPage();
    void addFoodItem();
    void removeFoodItem();
    void updateFoodItem();
    void viewAllFoodItems();
    void viewFoodItem(FoodItemDTO foodItemDTO);

    // void addUser();
};

