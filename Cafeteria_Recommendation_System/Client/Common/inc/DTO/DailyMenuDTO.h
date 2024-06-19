#pragma once
#include <string>

class DailyMenuDTO {
public:
    unsigned int daily_menu_id;
    unsigned int food_id;
    std::string date;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};