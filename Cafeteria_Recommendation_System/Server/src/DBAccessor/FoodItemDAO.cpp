#include "DBAccessor/FoodItemDAO.h"

bool FoodItemDAO::addFoodItem(FoodItemDTO foodItemDTO)
{
    std::string query = "INSERT INTO Food_Items (food_name, price, is_available, description) VALUES ('" + foodItemDTO.food_name + "', " + std::to_string(foodItemDTO.price) + ", " + std::to_string(foodItemDTO.is_available) + ", '" + foodItemDTO.description + "')";
    return mySqlDBAccess.executeUpdate(query);
}

bool FoodItemDAO::removeFoodItem(unsigned int foodItemId)
{
    std::string query = "DELETE FROM Food_Items WHERE food_id = " + std::to_string(foodItemId);
    std::cout << mySqlDBAccess.executeUpdate(query) << std::endl;
    return true;
}

bool FoodItemDAO::updateFoodItem(FoodItemDTO foodItemDTO)
{
    std::string query = "UPDATE Food_Items SET food_name = '" + foodItemDTO.food_name + "', price = " + std::to_string(foodItemDTO.price) + ", is_available = " + std::to_string(foodItemDTO.is_available) + ", description = '" + foodItemDTO.description + "' WHERE food_id = " + std::to_string(foodItemDTO.food_id);
    return mySqlDBAccess.executeUpdate(query);
}

FoodItemDTO FoodItemDAO::getFoodItem(unsigned int foodItemId)
{
    FoodItemDTO foodItem;
    std::string query = "SELECT * FROM Food_Items WHERE food_id = " + std::to_string(foodItemId);
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0)
    {
        foodItem.food_id = 0;
        return foodItem;
    }
    foodItem.food_id = std::stoi(data[0][0]);
    foodItem.food_name = data[0][1];
    foodItem.price = std::stoi(data[0][2]);
    foodItem.is_available = std::stoi(data[0][3]);
    foodItem.description = data[0][4];
    return foodItem;
}

std::vector<FoodItemDTO> FoodItemDAO::getFoodItems()
{
    std::vector<FoodItemDTO> foodItems;
    std::string query = "SELECT * FROM Food_Items";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : data)
    {
        FoodItemDTO foodItem;
        foodItem.food_id = std::stoi(row[0]);
        foodItem.food_name = row[1];
        foodItem.price = std::stoi(row[2]);
        foodItem.is_available = std::stoi(row[3]);
        foodItem.description = row[4];
        foodItems.push_back(foodItem);
    }
    return foodItems;
}

