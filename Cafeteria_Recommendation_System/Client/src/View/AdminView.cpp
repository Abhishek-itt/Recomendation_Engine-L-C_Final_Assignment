#include "View/AdminView.h"
#include "Utils/RequestTypes.h"

void AdminView::adminLandingPage() {
    std::cout << "Admin Home" << std::endl;
    std::cout << "2. Add Food Item" << std::endl;
    std::cout << "3. Remove Food Item" << std::endl;
    std::cout << "5. View All Food Items" << std::endl;
    std::cout << "1. Add User" << std::endl;
    std::cout << "8. Logout" << std::endl;
    std::cout << "Enter your choice: ";

    RequestType requestType;
    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    requestType = static_cast<RequestType>(choice);

    switch (requestType) {
        case RequestType::ADD_FOOD_ITEM:
            this->addFoodItem();
            break;
        case RequestType::DELETE_FOOD_ITEM:
            this->removeFoodItem();
            break;
        case RequestType::GET_FOOD_ITEMS:
            this->viewAllFoodItems();
            break;
        case RequestType::ADD_USER:
            this->addUser();
            break;
        case RequestType::LOGOUT:
            this->logout();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
}

void AdminView::addFoodItem() {
    std::string foodName;
    int price;
    int isAvailable;
    std::string description;

    std::cout << "Enter food name: ";
    std::getline(std::cin, foodName);
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter availability: ";
    std::cin >> isAvailable;
    std::cout << "Enter description: ";
    std::getline(std::cin, description);

    std::vector<std::string> foodItemData = {foodName, std::to_string(price), std::to_string(isAvailable), description};
    if (this->adminController.addFoodItem(foodItemData)) {
        std::cout << "Food item added successfully" << std::endl;
    } else {
        std::cout << "Failed to add food item" << std::endl;
    }
}

void AdminView::removeFoodItem() {
    int foodId;
    this->viewAllFoodItems();
    std::cout << "Enter food id to be removed: ";
    std::cin >> foodId;
    this->adminController.removeFoodItem(foodId);

    if (this->adminController.removeFoodItem(foodId)) {
        std::cout << "Food item removed successfully" << std::endl;
    } else {
        std::cout << "Failed to remove food item" << std::endl;
    }
}

void AdminView::viewAllFoodItems() {
    std::string foodItems = this->adminController.getFoodItemList();

    std::vector<std::string> foodItemsData = utils.lineDeserializer(foodItems);
    // Print table header
    std::cout << "Food Id\tFood Name\tPrice\tAvailability\tDescription" << std::endl;

    // Print table rows
    for (std::string foodItem : foodItemsData) {
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);
        std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
    }
}

void AdminView::viewFoodItem() {
    unsigned int foodId;
    std::cout << "Enter food id: ";
    std::cin >> foodId;
    std::string foodItem = this->adminController.getFoodItem(foodId);
    std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);

    std::cout << "Food Id: " << foodItemData[0] << std::endl;
    std::cout << "Food Name: " << foodItemData[1] << std::endl;
    std::cout << "Price: " << foodItemData[2] << std::endl;
    std::cout << "Availability: " << foodItemData[3] << std::endl;
    std::cout << "Description: " << foodItemData[4] << std::endl;
}

void AdminView::addUser() {
    std::cin.ignore();
    std::cin.clear();
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string role;
    std::string employeeId;

    std::cout << "Enter first Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter role: ";
    std::getline(std::cin, role);
    std::cout << "Enter employee id: ";
    std::getline(std::cin, employeeId);

    std::vector<std::string> userData = {username, role, employeeId, firstName, lastName};
    if (this->adminController.addUser(userData)) {
        std::cout << "User added successfully" << std::endl;
    } else {
        std::cout << "Failed to add user" << std::endl;
    }
}

void AdminView::logout() {
    std::cout << "Logging out" << std::endl;
    this->adminController.logout();
}
