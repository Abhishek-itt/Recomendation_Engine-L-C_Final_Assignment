#pragma once
#include <iostream>
#include <string>

#include "Controller/EmployeeController.h"
#include "Utils/Serializer.h"
#include "Utils/RequestTypes.h"

class EmployeeView {
public:
    EmployeeView(std::string username);

    void employeeLandingPage();
    void viewAllFoodItems();
    void viewFoodItem();
    void giveFeedback();
    void viewFoodFeedback();
    void viewRolloutMenu();
    void voteOnRolloutMenu();
    void viewMealMenu();
    void viewDietPreference();
    void updateDietPreference();
    void getNotifications();
    void sendReadReceipt();
    void logout();

private:
    std::string username;
    EmployeeController employeeController;
    Utils utils;
};
