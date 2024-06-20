#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/RolloutVotingDTO.h"

class RolloutVotingDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addRolloutVoting(RolloutVotingDTO rolloutVotingDTO);
    RolloutVotingDTO getRolloutVoting(unsigned int rolloutVotingId);
    std::vector<RolloutVotingDTO> getRolloutVotings(unsigned int dailyRolloutId);
    std::vector<RolloutVotingDTO> getRolloutVotings(std::string userName);
    std::vector<RolloutVotingDTO> getRolloutVotings(unsigned int dailyRolloutId, std::string userName);
};
