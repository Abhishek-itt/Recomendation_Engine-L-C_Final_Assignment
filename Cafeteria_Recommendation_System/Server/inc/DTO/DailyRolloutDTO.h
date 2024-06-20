#pragma once
#include <string>

class DailyRolloutDTO {
public:
    unsigned int rollout_id;
    std::string date;
    std::string meal_type;
    unsigned int food_id;

    void Serializer(std::string input)
    {
        std::string delimiter = "\n";
        size_t pos = 0;
        std::string token;
        int i = 0;
        while ((pos = input.find(delimiter)) != std::string::npos) {
            token = input.substr(0, pos);
            switch (i)
            {
            case 0:
                rollout_id = std::stoi(token);
                break;
            case 1:
                date = token;
                break;
            case 2:
                meal_type = token;
                break;
            case 3:
                food_id = std::stoi(token);
                break;
            default:
                break;
            }
            input.erase(0, pos + delimiter.length());
            i++;
        }
    }

    void Deserializer()
    {
        std::to_string(rollout_id) + "\n" + date + "\n" + meal_type + "\n" + std::to_string(food_id) + "\n";
    }
};