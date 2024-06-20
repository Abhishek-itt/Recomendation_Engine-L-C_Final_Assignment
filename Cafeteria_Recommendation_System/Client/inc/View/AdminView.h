#pragma once
#include <iostream>
#include <string>

#include "Controller/AdminController.h"
#include "Model/FoodItemDTO.h"


class AdminView {
    AdminController adminController;
public:
    void adminLandingPage();
    void addFoodItem();

    void addUser();
};

