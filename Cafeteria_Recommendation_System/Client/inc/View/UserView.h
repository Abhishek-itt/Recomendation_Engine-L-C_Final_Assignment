#pragma once
#include <iostream>
#include <string>

#include "Controller/UserController.h"

#include "Utils/RequestTypes.h"

#include "Utils/Serializer.h"

class UserView {
    UserController userController;
    Utils utils;

public:
    void userLandingPage();
    bool userLoginPage();
};