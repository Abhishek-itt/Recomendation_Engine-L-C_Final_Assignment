#include "Controller/AdminController.h"

bool AdminController::adminLogin(std::string username, int employeeId) {
std::string requestString = std::to_string(0) + "\n" + username + "\n" + std::to_string(employeeId) + "\n";

clientSocketController.sendMessage(requestString);
}

void AdminController::send(std::string sendBuffer) {
    clientSocketController.sendMessage(sendBuffer);
}

// bool AdminController::addFoodToMenu(FoodItemDTO foodItemDTO) {
//     std::string serializedData = foodItemDTO.serializeDataAsNSV();

//     std::string requestString = std::to_string(static_cast<int>(RequestType::ADD_FOOD_ITEM)) + "\n" + serializedData + "\n";

//     clientSocketController.sendMessage(requestString);

//     std::string response = clientSocketController.receiveMessage();
//     std::vector<std::string> responseVector;
//     std::istringstream iss(response);
//     std::string line;
//     while (std::getline(iss, line, '\n')) {
//         responseVector.push_back(line);
//     }

//     if (responseVector.size() == 1) {
//         if (responseVector[0] == "1") {
//             return true;
//         }
//     }
//     return false;
// }

// std::vector<FoodItemDTO> AdminController::fetchFoodItemList() {
//     std::string requestString = std::to_string(static_cast<int>(RequestType::FETCH_FOOD_ITEM_LIST)) + "\n";

//     clientSocketController.sendMessage(requestString);

//     std::string response = clientSocketController.receiveMessage();
//     std::vector<std::string> responseVector;
//     std::istringstream iss(response);
//     std::string line;
//     while (std::getline(iss, line, '\n')) {
//         responseVector.push_back(line);
//     }

//     std::vector<FoodItemDTO> foodItemDTOList;
//     std::cout << responseVector.size() << std::endl;
//     for (int i = 0; i < responseVector.size(); i += 5) {
//         FoodItemDTO foodItemDTO;

//         if (responseVector.size() - i < 5)
//         {
//             break;
//         }
        

//         std::cout << responseVector[i + 1] << "id" << std::endl;
//         std::cout << responseVector[i + 2] << std::endl;
//         std::cout << responseVector[i + 3] << std::endl;
//         std::cout << responseVector[i + 4] << std::endl;
//         std::cout << responseVector[i + 5] << std::endl;
      
//         foodItemDTO.food_id = std::stoi(responseVector[i + 1]);
//         foodItemDTO.food_name = responseVector[i + 2];
//         foodItemDTO.price = std::stoi(responseVector[i + 3]);
//         foodItemDTO.is_available = std::stoi(responseVector[i + 4]);
//         foodItemDTO.description = responseVector[i + 5];

      
//         foodItemDTOList.push_back(foodItemDTO);

//         {
//             /* code */
//         }
        
//     }

//     return foodItemDTOList;
// }

// bool AdminController::removeFoodItem(unsigned int foodId) {
//     std::string requestString = std::to_string(static_cast<int>(RequestType::REMOVE_FOOD_ITEM)) + "\n" + std::to_string(foodId) + "\n";

//     clientSocketController.sendMessage(requestString);

//     std::string response = clientSocketController.receiveMessage();
//     std::vector<std::string> responseVector;
//     std::istringstream iss(response);
//     std::string line;
//     while (std::getline(iss, line, '\n')) {
//         responseVector.push_back(line);
//     }

//     if (responseVector.size() == 1) {
//         if (responseVector[0] == "1") {
//             return true;
//         }
//     }
//     return false;
// }