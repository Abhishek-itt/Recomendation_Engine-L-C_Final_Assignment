#include "Admin.h"

bool Admin::login(std::string username, int employeeId) {
    UserDTO userDTO = usersDAO.getUserByUserName(username);
    std::cout << employeeId << userDTO.employee_id << std::endl;
    if (userDTO.employee_id == employeeId) {
        std::cout << "Admin login successful" << std::endl;
        if (userDTO.user_type == "Admin") {
            return true;
        }        
    }
    return false;
}

bool Admin::addFoodItem(FoodItemDTO foodItemDTO) {
    return foodItemDAO.addFoodItem(foodItemDTO);
}

bool Admin::removeFoodItem(unsigned int foodId) {
    return foodItemDAO.removeFoodItem(foodId);
}

