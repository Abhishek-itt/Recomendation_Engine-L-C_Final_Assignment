#pragma once
#include <string>

class UserDTO {
public:
    std::string user_name;
    int employee_id;
    std::string user_type;
    std::string first_name;
    std::string last_name;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};