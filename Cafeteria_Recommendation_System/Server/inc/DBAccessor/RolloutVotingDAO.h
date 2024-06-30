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
    RolloutVotingDTO getRolloutVoting(unsigned int votingId);
    std::vector<RolloutVotingDTO> getRolloutVotings(unsigned int rolloutId);
};