#include "Controller/MealMenuController.h"

bool MealMenuController::addMealMenu(std::string date, std::string mealType, unsigned int foodId)
{
    MealMenuDTO mealMenu;
    mealMenu.date = date;
    mealMenu.mealType = mealType;
    mealMenu.foodId = foodId;

    return mealMenuDAO.addMealMenu(mealMenu);
}

std::string MealMenuController::getMealMenu(std::string date, std::string mealType)
{
    MealMenuDTO mealMenu = mealMenuDAO.getMealMenu(date, mealType);
    return std::to_string(mealMenu.foodId);
}
