#include "DBAccessor/RolloutVotingDAO.h"

bool RolloutVotingDAO::voteOnRollout(unsigned int rolloutId, std::string userName) {
    std::string query = "INSERT INTO Rollout_Voting (rollout_id, user_name) VALUES (" + std::to_string(rolloutId) + ", '" + userName + "');";
    return mySqlDBAccess.executeQuery(query);
}

int RolloutVotingDAO::getVoteCount(unsigned int rolloutId) {
    std::string query = "SELECT COUNT(*) FROM Rollout_Voting WHERE rollout_id = " + std::to_string(rolloutId) + ";";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    if (result.size() > 0) {
        if (result[0].size() > 0) {
            return std::stoi(result[0][0]);
        }
    }
    
    return 0;
}

unsigned int RolloutVotingDAO::getVoteCountForFoodItem(unsigned int foodId) {
    std::string query = "SELECT COUNT(*) FROM Rollout_Voting JOIN Rollout_Menu ON Rollout_Voting.rollout_id = Rollout_Menu.rollout_id WHERE food_id = " + std::to_string(foodId) + ";";
    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    if (result.size() > 0) {
        if (result[0].size() > 0) {
            return std::stoi(result[0][0]);
        }
    }
    
    return 0;
}