#include "View/UserView.h"

void UserView::userLandingPage() {
    std::cout << "Welcome to Cafeteria. please login" << std::endl;
}

bool UserView::userLoginPage() {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    std::vector<std::string> userData = {username, password};
    if (this->userController.userLogin(userData)) {
        return true;
    } else {
        return false;
    }
}
