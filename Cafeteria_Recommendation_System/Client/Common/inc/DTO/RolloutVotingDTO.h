#pragma once
#include <string>

class RolloutVotingDTO {
public:
    unsigned int voting_id;
    unsigned int rollout_id;
    std::string user_name;

    std::string serializeDataAsNSV();
    void deserializeDataFromNSV(std::string NewlineSeparatedValues);
};