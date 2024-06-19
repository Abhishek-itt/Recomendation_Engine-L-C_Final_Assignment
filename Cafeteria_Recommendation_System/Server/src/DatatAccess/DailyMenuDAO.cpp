#include "DataAccess/DailyMenuDAO.h"

bool DailyMenuDAO::addDailyMenu(DailyMenuDTO dailyMenuDTO) {
    std::string Query = "INSERT INTO Daily_Menu (food_id, date) VALUES (" + std::to_string(dailyMenuDTO.getFoodId()) + ", '" + dailyMenuDTO.getDate() + "')";

    return mySqlDBAccess.executeUpdate(Query);  
}

bool DailyMenuDAO::removeDailyMenu(unsigned int dailyMenuId) {
    std::string Query = "DELETE FROM Daily_Menu WHERE daily_menu_id = " + std::to_string(dailyMenuId);

    return mySqlDBAccess.executeUpdate(Query);
}

void DailyMenuDAO::updateDailyMenu(DailyMenuDTO dailyMenuDTO) {
    std::string Query = "UPDATE Daily_Menu SET food_id = " + std::to_string(dailyMenuDTO.getFoodId()) + ", date = '" + dailyMenuDTO.getDate() + "' WHERE daily_menu_id = " + std::to_string(dailyMenuDTO.getDailyMenuId());

    mySqlDBAccess.executeUpdate(Query);
}

DailyMenuDTO 