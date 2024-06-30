#include "Controller/VotingController.h"

bool VotingController::voteOnRollout(unsigned int rolloutId, std::string userName) {
    return rolloutVotingDAO.voteOnRollout(rolloutId, userName);
}

int VotingController::getVoteCount(unsigned int rolloutId) {
    return rolloutVotingDAO.getVoteCount(rolloutId);
}