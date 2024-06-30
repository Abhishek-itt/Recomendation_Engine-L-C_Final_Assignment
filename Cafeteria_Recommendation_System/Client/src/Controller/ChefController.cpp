#include "Controller/ChefController.h"

std::string ChefController::getFoodItemList() {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEMS)) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    
    return response;
}

std::string ChefController::getFoodItem(unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEM)) + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

std::string ChefController::getRecommendationList() {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_RECOMMENDATION_LIST)) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

bool ChefController::rolloutMealMenu(std::string date, std::string mealType, unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::ROLLOUT_MEAL_MENU)) + "\n" + date + "\n" + mealType + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "true";
}

bool ChefController::rolloutMeal(std::string date, std::string mealType, unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::ROLLOUT_MEAL)) + "\n" + date + "\n" + mealType + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "true";
}

std::string ChefController::getVotesOnRollout(std::string date, std::string mealType) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_VOTES_ON_ROLLOUT)) + "\n" + date + "\n" + mealType + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

void ChefController::logout() {
    std::string requestString = "";
    clientSocketController.sendMessage(requestString);
}