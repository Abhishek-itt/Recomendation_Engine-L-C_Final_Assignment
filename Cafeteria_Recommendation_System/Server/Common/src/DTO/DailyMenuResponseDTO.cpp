#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/DailyMenuResponseDTO.h"

std::string DailyMenuResponseDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (daily_menu_id != 0) ? std::to_string(daily_menu_id) + "\n" : "\n";
    serializedData += (!user_name.empty()) ? user_name + "\n" : "\n";
    serializedData += response + "\n";

    return serializedData;
}

void DailyMenuResponseDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
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
        user_name = (values[1] != "null") ? values[1] : "";
        response = (values[2] != "null") ? values[2] : "";
    }
}