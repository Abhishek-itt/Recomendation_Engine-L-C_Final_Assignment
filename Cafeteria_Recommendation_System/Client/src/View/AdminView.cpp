#include "View/AdminView.h"
#include "Utils/RequestTypes.h"

void AdminView::adminLandingPage() {
    std::cout << "Admin Home" << std::endl;
    std::cout << "1. Add Food Item" << std::endl;
    std::cout << "2. Remove Food Item" << std::endl;
    std::cout << "3. Update Food Item" << std::endl;
    std::cout << "4. View All Food Items" << std::endl;
    std::cout << "5. View All Users" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "Enter your choice: ";

    int choice;
    std::cout << "Enter choice: ";   
    std::cin >> choice;
    std::string sendBuffer;
}


void AdminView::addFoodItem() {
    std::string foodName;
    double price;
    int isAvailable;
    std::string description;

    std::cout << "Enter food name: ";
    std::cin >> foodName;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter availability: ";
    std::cin >> isAvailable;
    std::cout << "Enter description: ";
    std::cin >> description;

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
    std::vector<std::string> foodItems = this->adminController.getFoodItemList();

    for (std::string foodItem : foodItems) {
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);

        std::cout << "Food Id: " << foodItemData[0] << std::endl;
        std::cout << "Food Name: " << foodItemData[1] << std::endl;
        std::cout << "Price: " << foodItemData[2] << std::endl;
        std::cout << "Availability: " << foodItemData[3] << std::endl;
        std::cout << "Description: " << foodItemData[4] << std::endl;
        
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
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string role;
    std::string employeeId;

    std::cout << "Enter first Name: ";
    std::cin >> firstName;
    std::cout << "Enter last Name: ";
    std::cin >> lastName;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter role: ";
    std::cin >> role;
    std::cout << "Enter employee id: ";
    std::cin >> employeeId;

    std::vector<std::string> userData = {username, role, employeeId, firstName, lastName};
    if (this->adminController.addUser(userData)) {
        std::cout << "User added successfully" << std::endl;
    } else {
        std::cout << "Failed to add user" << std::endl;
    }
}
