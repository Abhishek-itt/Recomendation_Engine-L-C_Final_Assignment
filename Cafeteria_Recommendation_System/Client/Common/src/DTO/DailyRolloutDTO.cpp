#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/DailyRolloutDTO.h"

std::string DailyRolloutDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (rollout_id != 0) ? std::to_string(rollout_id) + "\n" : "\n";
    serializedData += (!date.empty()) ? date + "\n" : "\n";
    serializedData += (!meal_type.empty()) ? meal_type + "\n" : "\n";
    serializedData += (food_id != 0) ? std::to_string(food_id) + "\n" : "\n";

    return serializedData;
}

void DailyRolloutDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
{
    std::vector<std::string> values;
    std::istringstream iss(NewlineSeparatedValues);
    std::string line;

    while (std::getline(iss, line))
    {
        values.push_back(line.empty() ? "null" : line);
    }

    if (values.size() >= 4)
    {
        rollout_id = (values[0] != "null") ? std::stoi(values[0]) : 0;
        date = (values[1] != "null") ? values[1] : "";
        meal_type = (values[2] != "null") ? values[2] : "";
        food_id = (values[3] != "null") ? std::stoi(values[3]) : 0;
    }
}