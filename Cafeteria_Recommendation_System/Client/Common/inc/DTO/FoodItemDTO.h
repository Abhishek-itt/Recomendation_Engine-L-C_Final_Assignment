#pragma once
#include <string>

class FoodItemDTO {
public:
    unsigned int food_id;
    std::string food_name;
    unsigned int price;
    bool is_available;
    std::string description;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};