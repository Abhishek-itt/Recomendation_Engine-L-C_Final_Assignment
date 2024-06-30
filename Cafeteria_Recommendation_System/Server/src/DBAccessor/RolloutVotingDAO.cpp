#include "DBAccessor/RolloutVotingDAO.h"

bool RolloutVotingDAO::addRolloutVoting(RolloutVotingDTO rolloutVotingDTO)
{
    std::string query = "INSERT INTO rollout_voting (rollout_id, user_name) VALUES (";
    query += std::to_string(rolloutVotingDTO.rollout_id) + ", '" + rolloutVotingDTO.user_name + "');";

    return mySqlDBAccess.execute(query);
}

RolloutVotingDTO RolloutVotingDAO::getRolloutVoting(unsigned int votingId)
{
    std::string query = "SELECT * FROM rollout_voting WHERE voting_id = " + std::to_string(votingId) + ";";

    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    RolloutVotingDTO rolloutVotingDTO;
    if (result.size() > 0)
    {
        rolloutVotingDTO.voting_id = std::stoi(result[0][0]);
        rolloutVotingDTO.rollout_id = std::stoi(result[0][1]);
        rolloutVotingDTO.user_name = result[0][2];
    }

    return rolloutVotingDTO;
}

std::vector<RolloutVotingDTO> RolloutVotingDAO::getRolloutVotings(unsigned int rolloutId)
{
    std::string query = "SELECT * FROM rollout_voting WHERE rollout_id = " + std::to_string(rolloutId) + ";";

    std::vector<std::vector<std::string>> result = mySqlDBAccess.fetchData(query);

    std::vector<RolloutVotingDTO> rolloutVotings;
    for (int i = 0; i < result.size(); i++)
    {
        RolloutVotingDTO rolloutVotingDTO;
        rolloutVotingDTO.voting_id = std::stoi(result[i][0]);
        rolloutVotingDTO.rollout_id = std::stoi(result[i][1]);
        rolloutVotingDTO.user_name = result[i][2];

        rolloutVotings.push_back(rolloutVotingDTO);
    }

    return rolloutVotings;
}
