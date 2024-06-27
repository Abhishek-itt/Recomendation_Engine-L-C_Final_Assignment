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
        EmployeeView employeeView;
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

//   // sendBuffer ="1\nFOOD2\n45\n1\ndessc\n";
//             // sendBuffer = "2\n3\n";
//             // sendBuffer = "3\n4\n";
//             // sendBuffer = "4\n";
//             // sendBuffer = "1\nfist\nlast\nuser\n1234\nEmployee\n";
//             // sendBuffer = "6\n5\ndavid_lee\n3\n4\nnot Good Yuck\n";
//             // sendBuffer = "7\n5\n";
            
//             std::cout << "sendBuffer: " << sendBuffer << std::endl;
//             adminController.send(sendBuffer);