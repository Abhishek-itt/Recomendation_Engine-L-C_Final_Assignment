#include "DBAccessor/MealMenuDAO.h"

MealMenuDTO MealMenuDAO::getMealMenu(std::string date, std::string mealType)
{
    std::string query = "SELECT food_id FROM Meal_Menu WHERE date = '" + date + "' AND meal_type = '" + mealType + "'";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    MealMenuDTO mealMenu;
    if (result.size() > 0)
    {
        mealMenu.foodId = std::stoi(result[0][0]);
    }
    return mealMenu;
}

bool MealMenuDAO::addMealMenu(MealMenuDTO mealMenu)
{
    std::string query = "INSERT INTO Meal_Menu (date, meal_type, food_id) VALUES ('" + mealMenu.date + "', '" + mealMenu.mealType + "', " + std::to_string(mealMenu.foodId) + ")";
    return mySqlDBAccess.executeQuery(query);
}

unsigned int MealMenuDAO::getMealMenuCount(unsigned int foodId)
{
    std::string query = "SELECT COUNT(*) FROM Meal_Menu WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);
    if (result.empty() || result[0].empty()) {
        return 0;
    }
    return std::stoi(result[0][0]);
}
