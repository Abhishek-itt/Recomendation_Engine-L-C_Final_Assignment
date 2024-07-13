#include "DBAccessor/MealMenuResponseDAO.h"

MealMenuResponseDTO MealMenuResponseDAO::getMealMenuResponse(unsigned int mealMenuId, std::string userName)
{
    MealMenuResponseDTO mealMenuResponse;
    std::string query = "SELECT * FROM Meal_Menu_Response WHERE meal_menu_id = " + std::to_string(mealMenuId) + " AND userName = '" + userName + "'";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    if (result.size() > 0)
    {
        mealMenuResponse.mealMenuId = std::stoi(result[0][0]);
        mealMenuResponse.userName = result[0][1];
        mealMenuResponse.response = result[0][2];
    }

    return mealMenuResponse;
}

std::vector<MealMenuResponseDTO> MealMenuResponseDAO::getMealMenuResponses(unsigned int mealMenuId)
{
    std::vector<MealMenuResponseDTO> mealMenuResponses;
    std::string query = "SELECT * FROM Meal_Menu_Response WHERE meal_menu_id = " + std::to_string(mealMenuId);
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    for (std::vector<std::string> row : result)
    {
        MealMenuResponseDTO mealMenuResponse;
        mealMenuResponse.mealMenuId = std::stoi(row[0]);
        mealMenuResponse.userName = row[1];
        mealMenuResponse.response = row[2];
    }

    return mealMenuResponses;
}

bool MealMenuResponseDAO::addMealMenuResponse(MealMenuResponseDTO mealMenuResponse)
{
    std::string query = "INSERT INTO Meal_Menu_Response (meal_menu_id, user_name, response) VALUES ("
                        + std::to_string(mealMenuResponse.mealMenuId) + ", '"
                        + mealMenuResponse.userName + "', '"
                        + mealMenuResponse.response + "')";
    return mySqlDBAccess.executeQuery(query);
}