#include "View/AdminView.h"
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
    RequestType requestType;
    std::cout << "Enter choice: ";   
    std::cin >> choice;
    std::string sendBuffer;

    

}



void AdminView::addFoodItem() {
    

    std::cout << "Enter food name: ";
    std::cin >> foodItemDTO.food_name;
    std::cout << "Enter price: ";
    std::cin >> foodItemDTO.price;
    std::cout << "Enter description: ";
    std::cin >> foodItemDTO.description;
    std::cout << "Is available? (1/0): ";
    std::cin >> foodItemDTO.is_available;

    this->adminController.addFoodToMenu(foodItemDTO);
}

void AdminView::viewAllFoodItems() {
    std::vector<FoodItemDTO> foodItems = this->adminController.fetchFoodItemList();
    for (FoodItemDTO foodItem : foodItems) {
        std::cout << "Food ID: " << foodItem.food_id << ", Food Name: " << foodItem.food_name << std::endl;
    }
}

// void AdminView::removeFoodItem() {
//     int foodId;
//     this->viewAllFoodItems();
//     std::cout << "Enter food id to be removed: ";
//     std::cin >> foodId;
//     this->adminController.removeFoodItem(foodId);

//     if (this->adminController.removeFoodItem(foodId)) {
//         std::cout << "Food item removed successfully" << std::endl;
//     } else {
//         std::cout << "Failed to remove food item" << std::endl;
//     }
// }
