#include <iostream>

#include "Controller/UserController.h"
#include "View/AdminView.h"
#include "View/EmployeeView.h"
#include "View/ChefView.h"
#include "Controller/SocketController.h"

int main()
{
    UserController* userController = new UserController();


    std::cout << "Welcome to Cafeteria. please login" << std::endl;

    std::string username;
    std::string employeeId;
    std::string userType;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter Employee ID: ";
    std::cin >> employeeId;

    userType = userController->userLogin(username, employeeId);

    if (userType == "Admin") {
        delete userController;
        AdminView adminView;    
        adminView.adminLandingPage();
    } else if (userType == "Employee") {
        delete userController;
        EmployeeView employeeView(username);
        employeeView.employeeLandingPage();
    } else if (userType == "Chef") {
        delete userController;
        ChefView chefView;
        chefView.chefLandingPage();
    } else {
        std::cout << "Invalid user" << std::endl;
    }

    return 0;
}