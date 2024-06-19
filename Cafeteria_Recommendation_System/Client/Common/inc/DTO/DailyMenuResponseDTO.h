#pragma once
#include <string>

class DailyMenuResponseDTO {
public:
    unsigned int daily_menu_id;
    std::string user_name;
    std::string response;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};