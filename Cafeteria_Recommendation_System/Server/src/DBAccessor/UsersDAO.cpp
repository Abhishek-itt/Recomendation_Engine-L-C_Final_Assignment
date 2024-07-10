#include "DBAccessor/UsersDAO.h"

UserDTO UsersDAO::getUser(std::string userName) {
    UserDTO user;
    std::string query = "SELECT * FROM Users WHERE user_name = '" + userName + "'";
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0) {
        user.user_name = "NULL";
        return user;
    }
    std::cout << data[0][0] << std::endl;
    std::cout << data[0][1] << std::endl;
    std::cout << data[0][2] << std::endl;
    std::cout << data[0][3] << std::endl;
    std::cout << data[0][4] << std::endl;
    

    user.user_name = data[0][0];
    user.employee_id = std::stoi(data[0][1]);
    user.user_type = data[0][2];
    user.first_name = data[0][3];
    user.last_name = data[0][4];
    return user;
}

bool UsersDAO::addUser(UserDTO user) {
    std::string query = "INSERT INTO Users () VALUES ('" + user.user_name + "', " + std::to_string(user.employee_id) + ", '" + user.user_type + "', '" + user.first_name + "', '" + user.last_name + "')";
    return mySqlDBAccess.executeUpdate(query);
}

bool UsersDAO::updateUser(UserDTO user) {
    std::string query = "UPDATE Users SET employee_id = " + std::to_string(user.employee_id) + ", user_type = '" + user.user_type + "', first_name = '" + user.first_name + "', last_name = '" + user.last_name + "' WHERE user_name = '" + user.user_name + "'";
    return mySqlDBAccess.executeUpdate(query);
}

bool UsersDAO::deleteUser(std::string userName) {
    std::string query = "DELETE FROM Users WHERE user_name = '" + userName + "'";
    return mySqlDBAccess.executeUpdate(query);
}

bool UsersDAO::updatePreference(std::string userName, UserPreferenceDTO userPreference) {
    std::string query = "UPDATE Users SET food_type_preference = '" + userPreference.food_type_preference + "', spice_level_preference = '" + userPreference.spice_level_preference + "',cuisine_preference = '" + userPreference.cuisine_preference + "',prefer_sweet = '" + userPreference.prefer_sweet + "' WHERE user_name = '" + userName + "'";

    return mySqlDBAccess.executeUpdate(query);
}

UserPreferenceDTO UsersDAO::getPreference(std::string userName) {
    UserPreferenceDTO userPreference;
    std::string query = "SELECT food_type_preference, spice_level_preference, cuisine_preference, prefer_sweet FROM Users WHERE user_name = '" + userName + "'";

    std::cout << query << std::endl;
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    if (data.size() == 0) {
        return userPreference;
    }
    userPreference.food_type_preference = data[0][0];
    userPreference.spice_level_preference = data[0][1];
    userPreference.cuisine_preference = data[0][2];
    userPreference.prefer_sweet = data[0][3];
    return userPreference;
}