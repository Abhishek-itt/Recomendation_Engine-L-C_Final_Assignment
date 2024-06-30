#include "Controller/EmployeeController.h"

std::string EmployeeController::getFoodItem(unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEM)) + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

std::string EmployeeController::getFoodItemList() {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEMS)) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    
    return response;
}

std::string EmployeeController::getRolloutMenu(std::string date, std::string mealType) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_ROLLOUT_MEAL_MENU)) + "\n" + date + "\n" + mealType + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

bool EmployeeController::voteOnRollout(unsigned int rolloutId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::VOTE_ON_ROLLOUT_MENU)) + "\n" + std::to_string(rolloutId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "true";
}

std::string EmployeeController::getMealMenu(std::string date, std::string mealType) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_MEAL_MENU)) + "\n" + date + "\n" + mealType + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

bool EmployeeController::giveResponseOnMealMenu(unsigned int mealMenuId, std::string response) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::RESPONSE_ON_MEAL)) + "\n" + std::to_string(mealMenuId) + "\n" + response + "\n";
    clientSocketController.sendMessage(requestString);
    std::string responseString = clientSocketController.receiveMessage();
    return responseString == "true";
}

void EmployeeController::logout() {
    std::string requestString = "";
    clientSocketController.sendMessage(requestString);
}

bool EmployeeController::giveFeedback(unsigned int foodId, std::string username, unsigned int tasteRating, unsigned int qualityRating, std::string review) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::ADD_FOOD_FEEDBACK)) + "\n" + std::to_string(foodId) + "\n" + username + "\n" + std::to_string(tasteRating) + "\n" + std::to_string(qualityRating) + "\n" + review + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "success";
}

std::string EmployeeController::getFeedback(unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FEEDBACKS_FOR_FOOD)) + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}