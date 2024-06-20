#pragma once
#include <string>

class DailyMenuResponseDTO {
public:
    unsigned int daily_menu_id;
    std::string user_name;
    std::string response;

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
                daily_menu_id = std::stoi(token);
                break;
            case 1:
                user_name = token;
                break;
            case 2:
                response = token;
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
        std::to_string(daily_menu_id) + "\n" + user_name + "\n" + response + "\n";
    }
};

