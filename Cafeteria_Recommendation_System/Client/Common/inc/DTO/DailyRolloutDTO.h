#pragma once
#include <string>

class DailyRolloutDTO {
public:
    unsigned int rollout_id;
    std::string date;
    std::string meal_type;
    unsigned int food_id;
;
    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};