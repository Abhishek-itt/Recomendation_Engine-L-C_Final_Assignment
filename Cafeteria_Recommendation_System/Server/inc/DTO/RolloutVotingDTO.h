#pragma once
#include <string>

class RolloutVotingDTO {
public:
    unsigned int voting_id;
    unsigned int rollout_id;
    std::string user_name;

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
                voting_id = std::stoi(token);
                break;
            case 1:
                rollout_id = std::stoi(token);
                break;
            case 2:
                user_name = token;
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
        std::to_string(voting_id) + "\n" + std::to_string(rollout_id) + "\n" + user_name + "\n";
    }
};