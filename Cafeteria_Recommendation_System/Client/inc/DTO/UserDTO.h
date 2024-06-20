#pragma once
#include <string>

class UserDTO {
public:
    std::string user_name;
    int employee_id;
    std::string user_type;
    std::string first_name;
    std::string last_name;

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
                user_name = token;
                break;
            case 1:
                employee_id = std::stoi(token);
                break;
            case 2:
                user_type = token;
                break;
            case 3:
                first_name = token;
                break;
            case 4:
                last_name = token;
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
        user_name + "\n" + std::to_string(employee_id) + "\n" + user_type + "\n" + first_name + "\n" + last_name + "\n";
    }
};