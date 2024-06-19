#include "User.h"

std::vector<FoodItemDTO> User::getFoodItems() {
    return foodItemDAO.getFoodItems();
}