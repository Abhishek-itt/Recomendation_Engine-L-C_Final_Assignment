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

void ChefController::logout() {
    std::string requestString = "";
    clientSocketController.sendMessage(requestString);
}