#include "View/EmployeeView.h"

void EmployeeView::employeeLandingPage() {
    std::cout << "Welcome to Cafeteria" << std::endl;
    std::cout << "1. View all food items" << std::endl;
    std::cout << "2. View food item" << std::endl;
    std::cout << "3. Give feedback" << std::endl;
    std::cout << "4. View food feedback" << std::endl;
    std::cout << "5. Logout" << std::endl;

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            viewAllFoodItems();
            break;
        case 2:
            viewFoodItem();
            break;
        case 3:
            giveFeedback();
            break;
        case 4:
            viewFoodFeedback();
            break;
        case 5:
            logout();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}

void EmployeeView::viewAllFoodItems() {
    std::string foodItems = this->employeeController.getFoodItemList();

    std::vector<std::string> foodItemsData = utils.lineDeserializer(foodItems);
    // Print table header
    std::cout << "Food Id\tFood Name\tPrice\tAvailability\tDescription" << std::endl;

    // Print table rows
    for (std::string foodItem : foodItemsData) {
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);
        std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
    }
}

void EmployeeView::viewFoodItem() {
    unsigned int foodId;
    std::cout << "Enter food id: ";
    std::cin >> foodId;
    std::string foodItem = this->employeeController.getFoodItem(foodId);
    std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);
    
    std::cout << "Food Id: " << foodItemData[0] << std::endl;
    std::cout << "Food Name: " << foodItemData[1] << std::endl;
    std::cout << "Price: " << foodItemData[2] << std::endl;
    std::cout << "Availability: " << foodItemData[3] << std::endl;
    std::cout << "Description: " << foodItemData[4] << std::endl;
}

void EmployeeView::giveFeedback() {
    std::cout << "Enter food ID: ";
    unsigned int foodId;
    std::cin >> foodId;

    std::cout << "Enter taste rating: ";
    unsigned int tasteRating;
    std::cin >> tasteRating;

    std::cout << "Enter quality rating: ";
    unsigned int qualityRating;
    std::cin >> qualityRating;

    std::cout << "Enter review: ";
    std::string review;
    std::getline(std::cin, review);

    bool success = employeeController.giveFeedback(foodId, "david_lee", tasteRating, qualityRating, review);
    if (success) {
        std::cout << "Feedback added successfully" << std::endl;
    } else {
        std::cout << "Failed to add feedback" << std::endl;
    }
}

void EmployeeView::viewFoodFeedback() {
    std::cout << "Enter food ID: ";
    unsigned int foodId;
    std::cin >> foodId;

    std::string response = employeeController.getFeedback(foodId);

    std::vector<std::string> feedbackData = utils.lineDeserializer(response);

    std::cout << "Username\tTaste Rating\tQuality Rating\tReview" << std::endl;
    for (std::string feedback : feedbackData) {
        std::vector<std::string> feedbackItem = utils.wordDeserializer(feedback);
        std::cout << feedbackItem[0] << "\t" << feedbackItem[1] << "\t" << feedbackItem[2] << "\t" << feedbackItem[3] << std::endl;
    }
}

void EmployeeView::logout() {
     std::cout << "Logging out" << std::endl;
    employeeController.logout();
}