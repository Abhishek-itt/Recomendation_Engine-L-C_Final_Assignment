#include "Controller/CRUDController.h"

bool CRUDController::addFoodItem(std::vector<std::string> foodItemData) {

    FoodItemDTO foodItem;
    std::cout << foodItemData[0] << std::endl;
    std::cout << foodItemData[1] << std::endl;
    std::cout << foodItemData[2] << std::endl;
    std::cout << foodItemData[3] << std::endl;

    foodItem.food_name = foodItemData[0];
    foodItem.price = std::stod(foodItemData[1]);
    foodItem.is_available =std::stod(foodItemData[2]);
    foodItem.description = foodItemData[3];

    std::cout << "Food Item Name: " << foodItem.food_name << std::endl;
    std::cout << "Food Item Price: " << foodItem.price << std::endl;
    std::cout << "Food Item Category: " << foodItem.is_available << std::endl;
    std::cout << "Food Item Description: " << foodItem.description << std::endl;

    return foodItemDAO.addFoodItem(foodItem);
}

bool CRUDController::updateFoodItem(FoodItemDTO foodItem) {
    return foodItemDAO.updateFoodItem(foodItem);
}

bool CRUDController::deleteFoodItem(int foodItemId) {
    return foodItemDAO.removeFoodItem(foodItemId);
}

std::string CRUDController::getFoodItem(int foodItemId) {
    FoodItemDTO foodItemDTO = foodItemDAO.getFoodItem(foodItemId);
    std::cout << foodItemDTO.Deserializer();
    return foodItemDTO.Deserializer();
}

std::vector<std::string> CRUDController::getFoodItems() {
    std::vector<std::string> foodItems;
    for (FoodItemDTO foodItem : foodItemDAO.getFoodItems())
    {
        std::cout << foodItem.food_id << std::endl;
        std::cout << foodItem.food_name << std::endl;
        std::cout << foodItem.price << std::endl;
        std::cout << foodItem.is_available << std::endl;
        std::cout << foodItem.description << std::endl;
        foodItems.push_back(foodItem.Deserializer());
    }
    return foodItems;
}

bool CRUDController::addFoodFeedback(std::vector<std::string> foodFeedbackData) {
    FoodFeedbackDTO foodFeedback;
    foodFeedback.food_id = std::stoi(foodFeedbackData[0]);
    foodFeedback.user_name = foodFeedbackData[1];
    foodFeedback.taste_rating = std::stoi(foodFeedbackData[2]);
    foodFeedback.quality_rating = std::stoi(foodFeedbackData[3]);
    foodFeedback.review = foodFeedbackData[4];

    return foodFeedbackDAO.addFoodFeedback(foodFeedback);
}

std::vector<std::string> CRUDController::getFoodFeedbacks(int foodId)
{
    std::vector<std::string> foodFeedbacks;

    for (FoodFeedbackDTO foodFeedback : foodFeedbackDAO.getFoodFeedbacks(foodId))
    {
        std::cout << foodFeedback.food_id << std::endl;
        std::cout << foodFeedback.user_name << std::endl;
        std::cout << foodFeedback.taste_rating << std::endl;
        std::cout << foodFeedback.quality_rating << std::endl;
        std::cout << foodFeedback.review << std::endl;

        foodFeedbacks.push_back(foodFeedback.Deserializer());
    }

    return foodFeedbacks;
} 