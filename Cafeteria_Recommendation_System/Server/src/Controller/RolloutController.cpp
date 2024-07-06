#include "Controller/RolloutController.h"

bool RolloutController::addRolloutMenu(std::string date, std::string mealType, unsigned int foodId) {
    RolloutMenuDTO rolloutMenu;
    rolloutMenu.date = date;
    rolloutMenu.mealType = mealType;
    rolloutMenu.foodId = foodId;

    return rolloutMenuDAO.addRollout(rolloutMenu);
}

std::vector<std::string> RolloutController::getRolloutMenu(std::string date, std::string mealType) {
    std::vector<RolloutMenuDTO> rolloutMenuList = rolloutMenuDAO.getRollout(date, mealType);
    std::vector<std::string> foodList;

    for (RolloutMenuDTO rolloutMenu : rolloutMenuList) {
        foodList.push_back(std::to_string(rolloutMenu.rolloutId));
    }

    return foodList;
}

unsigned int RolloutController::getFoodId(unsigned int rolloutId) {
    return rolloutMenuDAO.getFoodId(rolloutId);
}

