#pragma once
#include <string>

class FoodFeedbackDTO {
public:
    unsigned int feedback_id;
    unsigned int food_id;
    std::string user_name;
    unsigned int taste_rating;
    unsigned int quality_rating;
    std::string review;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};