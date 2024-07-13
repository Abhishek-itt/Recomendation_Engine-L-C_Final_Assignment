#pragma once
#include <iostream>
#include <string>

#include "Controller/AdminController.h"
#include "Utils/Serializer.h"
#include "Utils/RequestTypes.h"

class AdminView {
public:
    void adminLandingPage();
    void addFoodItem();
    void removeFoodItem();
    void viewAllFoodItems();
    void viewFoodItem();
    void logout();
    void addUser();
private:
    AdminController adminController;
    Utils utils;
};
