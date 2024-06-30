#include "DBAccessor/RolloutMenuDAO.h"

std::vector<RolloutMenuDTO> RolloutMenuDAO::getRollout(std::string date, std::string mealType)
{
    std::vector<RolloutMenuDTO> rolloutMenuList;
    std::string query = "SELECT * FROM rollout_menu WHERE date = '" + date + "' AND meal_type = '" + mealType + "'";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : result)
    {
        RolloutMenuDTO rolloutMenu;
        rolloutMenu.rolloutId = std::stoi(row[0]);
        rolloutMenu.date = row[1];
        rolloutMenu.mealType = row[2];
        rolloutMenu.foodId = std::stoi(row[3]);
        rolloutMenuList.push_back(rolloutMenu);
    }
    return rolloutMenuList;
}

bool RolloutMenuDAO::addRollout(RolloutMenuDTO rollout)
{
    std::string query = "INSERT INTO rollout_menu (date, meal_type, food_id) VALUES ('" + rollout.date + "', '" + rollout.mealType + "', " + std::to_string(rollout.foodId) + ")";
    return mySqlDBAccess.executeQuery(query);
}