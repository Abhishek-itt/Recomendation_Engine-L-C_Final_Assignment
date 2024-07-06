#include "DBAccessor/RolloutMenuDAO.h"

std::vector<RolloutMenuDTO> RolloutMenuDAO::getRollout(std::string date, std::string mealType)
{
    std::vector<RolloutMenuDTO> rolloutMenuList;
    std::string query = "SELECT * FROM Rollout_Menu WHERE date = '" + date + "' AND meal_type = '" + mealType + "'";
    std::cout << "Query: " << query << std::endl;
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
    std::string query = "INSERT INTO Rollout_Menu (date, meal_type, food_id) VALUES ('" + rollout.date + "', '" + rollout.mealType + "', " + std::to_string(rollout.foodId) + ")";
    std::cout << "Query: " << query << std::endl;
    return mySqlDBAccess.executeQuery(query);
}

unsigned int RolloutMenuDAO::getFoodId(unsigned int rolloutId)
{
    std::string query = "SELECT food_id FROM Rollout_Menu WHERE rollout_id = " + std::to_string(rolloutId);
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);
    if (result.empty() || result[0].empty()) {
        return 0;
    }
    return std::stoi(result[0][0]);
}

unsigned int RolloutMenuDAO::getRolloutCount(unsigned int foodId)
{
    std::string query = "SELECT COUNT(*) FROM Rollout_Menu WHERE food_id = " + std::to_string(foodId);
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);
    if (result.empty() || result[0].empty()) {
        return 0;
    }
    return std::stoi(result[0][0]);
}

