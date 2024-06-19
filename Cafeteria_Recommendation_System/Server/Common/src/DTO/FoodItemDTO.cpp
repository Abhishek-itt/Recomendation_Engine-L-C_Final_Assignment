#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/FoodItemDTO.h"

std::string FoodItemDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (food_id != 0) ? std::to_string(food_id) + "\n" : "\n";
    serializedData += (!food_name.empty()) ? food_name + "\n" : "\n";
    serializedData += (price != 0.0) ? std::to_string(price) + "\n" : "\n";
    serializedData += (is_available) ? "1\n" : "0\n";
    serializedData += (!description.empty()) ? description + "\n" : "\n";

    return serializedData;
}

void FoodItemDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
{
    std::vector<std::string> values;
    std::istringstream iss(NewlineSeparatedValues);
    std::string line;

    while (std::getline(iss, line))
    {
        values.push_back(line.empty() ? "null" : line);
    }

    if (values.size() >= 5)
    {
        food_id = (values[0] != "null") ? std::stoi(values[0]) : 0;
        food_name = (values[1] != "null") ? values[1] : "";
        price = (values[2] != "null") ? std::stod(values[2]) : 0.0;
        is_available = (values[3] != "null") ? (values[3] == "1") : false;
        description = (values[4] != "null") ? values[4] : "";
    }
}