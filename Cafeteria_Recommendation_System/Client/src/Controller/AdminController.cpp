#include "Controller/AdminController.h"


std::string AdminController::getFoodItem(unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEM)) + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response;
}

std::string AdminController::getFoodItemList() {
    std::string requestString = std::to_string(static_cast<int>(RequestType::GET_FOOD_ITEMS)) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    
    return response;
}

bool AdminController::addFoodItem(std::vector<std::string> foodItemData) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::ADD_FOOD_ITEM)) + "\n" + utils.wordSerializer(foodItemData) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "success";
}

bool AdminController::removeFoodItem(unsigned int foodId) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::DELETE_FOOD_ITEM)) + "\n" + std::to_string(foodId) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "true";
}

bool AdminController::addUser(std::vector<std::string> userData) {
    std::string requestString = std::to_string(static_cast<int>(RequestType::ADD_USER)) + "\n" + utils.wordSerializer(userData) + "\n";
    clientSocketController.sendMessage(requestString);
    std::string response = clientSocketController.receiveMessage();
    return response == "true";
}

void AdminController::logout() {
    std::string requestString = "";
    clientSocketController.sendMessage(requestString);
    exit(EXIT_SUCCESS);
}