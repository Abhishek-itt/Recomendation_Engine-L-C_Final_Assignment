#include "DBAccessor/MealMenuDAO.h"

MealMenuDTO MealMenuDAO::getMealMenu(std::string date, std::string mealType)
{
    std::string query = "SELECT * FROM meal_menu WHERE date = '" + date + "' AND meal_type = '" + mealType + "'";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    MealMenuDTO mealMenu;
    if (result.size() > 0)
    {
        mealMenu.date = result[0][0];
        mealMenu.mealType = result[0][1];
        mealMenu.foodId = std::stoi(result[0][2]);
    }
    return mealMenu;
}

bool MealMenuDAO::addMealMenu(MealMenuDTO mealMenu)
{
    std::string query = "INSERT INTO meal_menu (date, meal_type, food_id) VALUES ('" + mealMenu.date + "', '" + mealMenu.mealType + "', " + std::to_string(mealMenu.foodId) + ")";
    return mySqlDBAccess.executeQuery(query);
}

unsigned int MealMenuDAO::getMealMenuCount(unsigned int foodId)
{
    std::string query = "SELECT COUNT(*) FROM meal_menu WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);
    return std::stoi(result[0][0]);
}
