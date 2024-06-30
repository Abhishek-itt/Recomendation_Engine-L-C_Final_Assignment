#pragma once

#include <string>
#include <vector>

#include "DTO/RolloutVotingDTO.h"
#include "DBAccessor/RolloutVotingDAO.h"

class VotingController {
public:
    bool voteOnRollout(unsigned int rolloutId, std::string userName);
    int getVoteCount(unsigned int rolloutId);

private:
    RolloutVotingDAO rolloutVotingDAO;
};