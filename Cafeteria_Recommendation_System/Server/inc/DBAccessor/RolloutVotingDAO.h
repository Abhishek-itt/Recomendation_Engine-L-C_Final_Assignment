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
    bool voteOnRollout(unsigned int rolloutId, std::string userName);
    int getVoteCount(unsigned int rolloutId);

    unsigned int getVoteCountForFoodItem(unsigned int foodId);
};