#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/UserDTO.h"

std::string UserDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (!user_name.empty()) ? user_name + "\n" : "\n";
    serializedData += (employee_id != 0) ? std::to_string(employee_id) + "\n" : "\n";
    serializedData += (!user_type.empty()) ? user_type + "\n" : "\n";
    serializedData += (!first_name.empty()) ? first_name + "\n" : "\n";
    serializedData += (!last_name.empty()) ? last_name + "\n" : "\n";

    return serializedData;
}

void UserDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
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
        user_name = (values[0] != "null") ? values[0] : "";
        employee_id = (values[1] != "null") ? std::stoi(values[1]) : 0;
        user_type = (values[2] != "null") ? values[2] : "";
        first_name = (values[3] != "null") ? values[3] : "";
        last_name = (values[4] != "null") ? values[4] : "";
    }
}