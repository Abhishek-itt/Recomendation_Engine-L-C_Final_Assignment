#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/FoodFeedbackDTO.h"

class FoodFeedbackDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addFoodFeedback(FoodFeedbackDTO foodFeedbackDTO);
    FoodFeedbackDTO getFoodFeedback(unsigned int foodFeedbackId);
    std::vector<FoodFeedbackDTO> getFoodFeedbacks(unsigned int foodId);
    std::vector<FoodFeedbackDTO> getFoodFeedbacks(std::string userName);
    std::vector<FoodFeedbackDTO> getFoodFeedbacks(unsigned int foodId, std::string userName);

    float getAverageTasteRating(unsigned int foodId);
    float getAverageQualityRating(unsigned int foodId);
}; 