#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DTO/RolloutVotingDTO.h"

std::string RolloutVotingDTO::serializeDataAsNSV()
{
    std::string serializedData;
    serializedData += (voting_id != 0) ? std::to_string(voting_id) + "\n" : "\n";
    serializedData += (rollout_id != 0) ? std::to_string(rollout_id) + "\n" : "\n";
    serializedData += (!user_name.empty()) ? user_name + "\n" : "\n";

    return serializedData;
}

void RolloutVotingDTO::deserializeDataFromNSV(std::string NewlineSeparatedValues)
{
    std::vector<std::string> values;
    std::istringstream iss(NewlineSeparatedValues);
    std::string line;

    while (std::getline(iss, line))
    {
        values.push_back(line.empty() ? "null" : line);
    }

    if (values.size() >= 3)
    {
        voting_id = (values[0] != "null") ? std::stoi(values[0]) : 0;
        rollout_id = (values[1] != "null") ? std::stoi(values[1]) : 0;
        user_name = (values[2] != "null") ? values[2] : "";
    }
}