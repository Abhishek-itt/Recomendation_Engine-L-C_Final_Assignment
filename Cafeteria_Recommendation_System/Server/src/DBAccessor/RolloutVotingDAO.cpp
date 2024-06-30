#include "DBAccessor/RolloutVotingDAO.h"

bool RolloutVotingDAO::voteOnRollout(unsigned int rolloutId, std::string userName) {
    std::string query = "INSERT INTO rollout_voting (rollout_id, user_name) VALUES (" + std::to_string(rolloutId) + ", '" + userName + "');";
    return mySqlDBAccess.executeQuery(query);
}

int RolloutVotingDAO::getVoteCount(unsigned int rolloutId) {
    std::string query = "SELECT COUNT(*) FROM rollout_voting WHERE rollout_id = " + std::to_string(rolloutId) + ";";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    if (result.size() > 0) {
        return std::stoi(result[0][0]);
    }
}