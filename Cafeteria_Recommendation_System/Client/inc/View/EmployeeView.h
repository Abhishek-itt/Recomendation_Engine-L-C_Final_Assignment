#pragma once
#include <iostream>
#include <string>

#include "Controller/EmployeeController.h"

#include "Utils/Serializer.h"   
#include "Utils/RequestTypes.h"

class EmployeeView {
public:
    void employeeLandingPage();
    void viewAllFoodItems();
    void viewFoodItem();
    void giveFeedback();
    void viewFoodFeedback();
    void logout();

private:
    EmployeeController employeeController;
    Utils utils;
};
