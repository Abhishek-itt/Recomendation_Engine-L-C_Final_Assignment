#include "Controller/UserController.h"

#include "DTO/UserDTO.h"
#include "DTO/userPreferenceDTO.h"

std::string UserController::login(std::string userName, std::string employeeId) {
    std::string userType;
    UserDTO user = userDAO.getUser(userName);
    if (user.user_name == "NULL") {
        userType = "NULL";
    } else {
        if (user.employee_id == std::stoi(employeeId)) {
            userType = user.user_type;
        } else {
            userType = "NULL";
        }
    }

    return userType;
}

bool UserController::addUser(std::string firstName, std::string lastName, std::string userName, std::string employeeId, std::string userType) {
    UserDTO user;
    user.first_name = firstName;
    user.last_name = lastName;
    user.user_type = userType;
    user.user_name = userName;
    user.employee_id = std::stoi(employeeId);

    return userDAO.addUser(user);
}

bool UserController::updateUserDietPreference(std::string userName, std::string foodTypePreference, std::string spiceLevelPreference, std::string cuisinePreference, std::string preferSweet) {
    UserPreferenceDTO userPreference;
    userPreference.food_type_preference = foodTypePreference;
    userPreference.spice_level_preference = spiceLevelPreference;
    userPreference.cuisine_preference = cuisinePreference;
    userPreference.prefer_sweet = preferSweet;

    return userDAO.updatePreference(userName, userPreference);
}

std::vector<std::string> UserController::getUserDietPreference(std::string userName) {
    UserPreferenceDTO userPreference = userDAO.getPreference(userName);
    std::vector<std::string> preference;
    preference.push_back(userPreference.food_type_preference);
    preference.push_back(userPreference.spice_level_preference);
    preference.push_back(userPreference.cuisine_preference);
    preference.push_back(userPreference.prefer_sweet);

    std::cout << "User preference: " << preference[0] << " " << preference[1] << " " << preference[2] << " " << preference[3] << std::endl;
    return preference;
}