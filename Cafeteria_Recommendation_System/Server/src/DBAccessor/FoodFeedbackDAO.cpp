#include "DBAccessor/FoodFeedbackDAO.h"

bool FoodFeedbackDAO::addFoodFeedback(FoodFeedbackDTO foodFeedbackDTO)
{


    std::string query = "INSERT INTO Food_Feedback (food_id, user_name, taste_rating, quality_rating, review) VALUES (" + std::to_string(foodFeedbackDTO.food_id) + ", '" + foodFeedbackDTO.user_name + "', " + std::to_string(foodFeedbackDTO.taste_rating) + ", " + std::to_string(foodFeedbackDTO.quality_rating) + ", '" + foodFeedbackDTO.review + "')";

    std::cout << query << std::endl;
    return mySqlDBAccess.executeUpdate(query);
}

FoodFeedbackDTO FoodFeedbackDAO::getFoodFeedback(unsigned int foodFeedbackId)
{
    FoodFeedbackDTO foodFeedback;
    std::string query = "SELECT * FROM Food_Feedback WHERE feedback_id = " + std::to_string(foodFeedbackId);
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0)
    {
        foodFeedback.feedback_id = 0;
        return foodFeedback;
    }
    foodFeedback.feedback_id = std::stoi(data[0][0]);
    foodFeedback.food_id = std::stoi(data[0][1]);
    foodFeedback.user_name = data[0][2];
    foodFeedback.taste_rating = std::stoi(data[0][3]);
    foodFeedback.quality_rating = std::stoi(data[0][4]);
    foodFeedback.review = data[0][5];
    return foodFeedback;
}

std::vector<FoodFeedbackDTO> FoodFeedbackDAO::getFoodFeedbacks(unsigned int foodId)
{
    std::vector<FoodFeedbackDTO> foodFeedbacks;
    std::string query = "SELECT * FROM Food_Feedback WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : data)
    {
        FoodFeedbackDTO foodFeedback;
        foodFeedback.feedback_id = std::stoi(row[0]);
        foodFeedback.food_id = std::stoi(row[1]);
        foodFeedback.user_name = row[2];
        foodFeedback.taste_rating = std::stoi(row[3]);
        foodFeedback.quality_rating = std::stoi(row[4]);
        foodFeedback.review = row[5];
        foodFeedbacks.push_back(foodFeedback);
    }
    return foodFeedbacks;
}

std::vector<FoodFeedbackDTO> FoodFeedbackDAO::getFoodFeedbacks(std::string userName)
{
    std::vector<FoodFeedbackDTO> foodFeedbacks;
    std::string query = "SELECT * FROM Food_Feedback WHERE user_name = '" + userName + "'";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : data)
    {
        FoodFeedbackDTO foodFeedback;
        foodFeedback.feedback_id = std::stoi(row[0]);
        foodFeedback.food_id = std::stoi(row[1]);
        foodFeedback.user_name = row[2];
        foodFeedback.taste_rating = std::stoi(row[3]);
        foodFeedback.quality_rating = std::stoi(row[4]);
        foodFeedback.review = row[5];
        foodFeedbacks.push_back(foodFeedback);
    }
    return foodFeedbacks;
}

std::vector<FoodFeedbackDTO> FoodFeedbackDAO::getFoodFeedbacks(unsigned int foodId, std::string userName)
{
    std::vector<FoodFeedbackDTO> foodFeedbacks;
    std::string query = "SELECT * FROM Food_Feedback WHERE food_id = " + std::to_string(foodId) + " AND user_name = '" + userName + "'";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : data)
    {
        FoodFeedbackDTO foodFeedback;
        foodFeedback.feedback_id = std::stoi(row[0]);
        foodFeedback.food_id = std::stoi(row[1]);
        foodFeedback.user_name = row[2];
        foodFeedback.taste_rating = std::stoi(row[3]);
        foodFeedback.quality_rating = std::stoi(row[4]);
        foodFeedback.review = row[5];
        foodFeedbacks.push_back(foodFeedback);
    }
    return foodFeedbacks;
}

float FoodFeedbackDAO::getAverageTasteRating(unsigned int foodId)
{
    std::string query = "SELECT AVG(taste_rating) FROM Food_Feedback WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0)
    {
        return 0;
    }
    return std::stof(data[0][0]);
}

float FoodFeedbackDAO::getAverageQualityRating(unsigned int foodId)
{
    std::string query = "SELECT AVG(quality_rating) FROM Food_Feedback WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0)
    {
        return 0;
    }
    return std::stof(data[0][0]);
}

