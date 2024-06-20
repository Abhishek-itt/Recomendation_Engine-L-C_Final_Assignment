#include <iostream>
#include <string>
#include <vector>

#include "Controller/SocketController.h"
#include "Utils/Serializer.h"

class UserController {
    public:
        bool userLogin(std::vector<std::string> userData);

private:
        ClientSocketController clientSocketController;
        Utils utils;
};

#include "Model/RequestType.h"

void AdminView::adminLoginPage() {
    std::string username;
    int employeeId;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter employee id: ";
    std::cin >> employeeId;

    if (adminController.adminLogin(username, employeeId))   
    {
        // this->adminLandingPage();
        std::cout << "Login successful" << std::endl;
        this->adminLandingPage();
        
    } else {
        std::cout << "Invalid credentials" << std::endl;
        this->adminLoginPage();
    }
    
}
