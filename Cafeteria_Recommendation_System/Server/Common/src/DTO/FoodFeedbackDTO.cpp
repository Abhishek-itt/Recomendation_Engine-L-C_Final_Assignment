#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/FoodFeedbackDTO.h"

std::string FoodFeedbackDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (feedback_id != 0) ? std::to_string(feedback_id) + "\n" : "\n";
    serializedData += (food_id != 0) ? std::to_string(food_id) + "\n" : "\n";
    serializedData += (!user_name.empty()) ? user_name + "\n" : "\n";
    serializedData += (taste_rating != 0) ? std::to_string(taste_rating) + "\n" : "\n";
    serializedData += (quality_rating != 0) ? std::to_string(quality_rating) + "\n" : "\n";
    serializedData += (!review.empty()) ? review + "\n" : "\n";

    return serializedData;
}

void FoodFeedbackDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
{
    std::vector<std::string> values;
    std::istringstream iss(NewlineSeparatedValues);
    std::string line;

    while (std::getline(iss, line))
    {
        values.push_back(line.empty() ? "null" : line);
    }

    if (values.size() >= 6)
    {
        feedback_id = (values[0] != "null") ? std::stoi(values[0]) : 0;
        food_id = (values[1] != "null") ? std::stoi(values[1]) : 0;
        user_name = (values[2] != "null") ? values[2] : "";
        taste_rating = (values[3] != "null") ? std::stoi(values[3]) : 0;
        quality_rating = (values[4] != "null") ? std::stoi(values[4]) : 0;
        review = (values[5] != "null") ? values[5] : "";
    }
}
