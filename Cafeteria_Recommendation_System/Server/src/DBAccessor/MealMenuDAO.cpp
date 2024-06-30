#include "DBAccessor/MealMenuDAO.h"

bool MealMenuDAO::addMealMenu(MealMenuDTO mealMenuDTO)
{
    std::string query = "INSERT INTO meal_menu (food_id, date, meal_type) VALUES (";
    query += std::to_string(mealMenuDTO.foodId) + ", '" + mealMenuDTO.date + "', '" + mealMenuDTO.mealType + "');";

    return mySqlDBAccess.execute(query);
}

MealMenuDTO MealMenuDAO::getMealMenu(unsigned int mealMenuId)
{
    std::string query = "SELECT * FROM meal_menu WHERE meal_menu_id = " + std::to_string(mealMenuId) + ";";

    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    MealMenuDTO mealMenuDTO;
    if (result.size() > 0)
    {
        mealMenuDTO.mealMenuId = std::stoi(result[0][0]);
        mealMenuDTO.foodId = std::stoi(result[0][1]);
        mealMenuDTO.date = result[0][2];
        mealMenuDTO.mealType = result[0][3];
    }

    return mealMenuDTO;
}

std::vector<MealMenuDTO> MealMenuDAO::getMealMenus(unsigned int foodId)
{
    std::string query = "SELECT * FROM meal_menu WHERE food_id = " + std::to_string(foodId) + ";";

    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    std::vector<MealMenuDTO> mealMenus;
    for (int i = 0; i < result.size(); i++)
    {
        MealMenuDTO mealMenuDTO;
        mealMenuDTO.mealMenuId = std::stoi(result[i][0]);
        mealMenuDTO.foodId = std::stoi(result[i][1]);
        mealMenuDTO.date = result[i][2];
        mealMenuDTO.mealType = result[i][3];

        mealMenus.push_back(mealMenuDTO);
    }

    return mealMenus;
}

