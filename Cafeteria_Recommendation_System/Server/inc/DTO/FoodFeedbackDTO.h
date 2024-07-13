#pragma once
#include <string>

class FoodFeedbackDTO {
public:
    unsigned int feedback_id;
    unsigned int food_id;
    std::string user_name;
    unsigned int taste_rating;
    unsigned int quality_rating;
    std::string review;

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
                feedback_id = std::stoi(token);
                break;
            case 1:
                food_id = std::stoi(token);
                break;
            case 2:
                user_name = token;
                break;
            case 3:
                taste_rating = std::stoi(token);
                break;
            case 4:
                quality_rating = std::stoi(token);
                break;
            case 5:
                review = token;
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
        return std::to_string(feedback_id) + "\n" + std::to_string(food_id) + "\n" + user_name + "\n" + std::to_string(taste_rating) + "\n" + std::to_string(quality_rating) + "\n" + review + "\n";
    }
};