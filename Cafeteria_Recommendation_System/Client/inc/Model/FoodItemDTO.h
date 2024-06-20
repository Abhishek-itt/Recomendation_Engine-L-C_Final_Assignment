#pragma once
#include <string>

class FoodItemDTO {
public:
    unsigned int food_id;
    std::string food_name;
    unsigned int price;
    bool is_available;
    std::string description;

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
            case 1:
                food_name = token;
                break;
            case 2:
                price = std::stoi(token);
                break;
            case 3:
                is_available = std::stoi(token);
                break;
            case 4:
                description = token;
                break;
            default:
                break;
            }
            input.erase(0, pos + delimiter.length());
            i++;
        }
    }

    std::string Deserializer()
    {
        return std::to_string(food_id) + "\n" + food_name + "\n" + std::to_string(price) + "\n" + std::to_string(is_available) + "\n" + description + "\n";
    }
};