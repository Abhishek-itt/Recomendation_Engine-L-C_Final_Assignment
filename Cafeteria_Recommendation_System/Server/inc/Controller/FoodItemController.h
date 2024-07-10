#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "DTO/FoodItemDTO.h"
#include "DTO/FoodFeedbackDTO.h"

#include "DBAccessor/FoodItemDAO.h"
#include "DBAccessor/FoodFeedbackDAO.h"

#include "RecommendationEngine/RecommendationEngine.h"

class CRUDController {
public:
    bool addFoodItem(std::vector<std::string> foodItemData);
    bool updateFoodItem(FoodItemDTO foodItem);
    bool deleteFoodItem(int foodItemId);
    std::string getFoodItem(int foodItemId);
    std::vector<std::string> getFoodItems();

    bool addFoodFeedback(std::vector<std::string> foodFeedbackData);
    std::vector<std::string> getFoodFeedbacks(int foodId);

    std::vector<std::string> getRecommendationList(int count);

    
private:
    FoodItemDAO foodItemDAO;
    FoodFeedbackDAO foodFeedbackDAO;
    RecommendationEngine recommendationEngine;
};