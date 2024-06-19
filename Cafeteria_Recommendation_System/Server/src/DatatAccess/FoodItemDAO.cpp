#include "FoodItemDAO.h"

bool FoodItemDAO::addFoodItem(FoodItemDTO foodItemDTO) {
    std::string query = "INSERT INTO Food_Items (food_name, price, is_available, description) VALUES \
    ('" + foodItemDTO.food_name + "', " + std::to_string(foodItemDTO.price) + ", " + \
    std::to_string(foodItemDTO.is_available) + ", '" + foodItemDTO.description + "');";

    std::cout << query << std::endl;

    return mySqlDBAccess.executeUpdate(query);
}

std::vector<FoodItemDTO> FoodItemDAO::getFoodItems() {
    std::vector<FoodItemDTO> foodItems;
    std::string query = "SELECT * FROM Food_Items;";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);

    for (std::vector<std::string> row : data) {
        FoodItemDTO foodItemDTO;
        foodItemDTO.food_id = std::stoi(row[0]);
        foodItemDTO.food_name = row[1];
        foodItemDTO.price = std::stod(row[2]);
        foodItemDTO.is_available = std::stoi(row[3]);
        foodItemDTO.description = row[4];

        foodItems.push_back(foodItemDTO);
    }

    return foodItems;
}

bool FoodItemDAO::removeFoodItem(unsigned int foodId) {
    std::string query = "DELETE FROM Food_Items WHERE food_id = " + std::to_string(foodId) + ";";
    return mySqlDBAccess.executeUpdate(query);
}

FoodItemDTO FoodItemDAO::getFoodItem(unsigned int foodItemId) {
    FoodItemDTO foodItemDTO;
    std::string query = "SELECT * FROM Food_Items WHERE food_id = " + std::to_string(foodItemId) + ";";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);

    if (data.size() == 0) {
        return foodItemDTO;
    }

    foodItemDTO.food_id = std::stoi(data[0][0]);
    foodItemDTO.food_name = data[0][1];
    foodItemDTO.price = std::stod(data[0][2]);
    foodItemDTO.is_available = std::stoi(data[0][3]);
    foodItemDTO.description = data[0][4];

    return foodItemDTO;
}