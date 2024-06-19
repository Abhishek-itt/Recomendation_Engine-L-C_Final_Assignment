#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/DailyMenuDTO.h"

std::string DailyMenuDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (daily_menu_id != 0) ? std::to_string(daily_menu_id) + "\n" : "\n";
    serializedData += (food_id != 0) ? std::to_string(food_id) + "\n" : "\n";
    serializedData += (!date.empty()) ? date + "\n" : "\n";

    return serializedData;
}

void DailyMenuDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
{
    std::vector<std::string> values;
    std::istringstream iss(NewlineSeparatedValues);
    std::string line;

    while (std::getline(iss, line))
    {
        values.push_back(line.empty() ? "null" : line);
    }

    if (values.size() >= 3)
    {
        daily_menu_id = (values[0] != "null") ? std::stoi(values[0]) : 0;
        food_id = (values[1] != "null") ? std::stoi(values[1]) : 0;
        date = (values[2] != "null") ? values[2] : "";
    }
}
