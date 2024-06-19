#include "Common/DTO/FoodItemDTO.h"
#include "Common/DTO/UserDTO.h"
#include "Common/DTO/DailyMenuDTO.h"
#include "Common/DTO/DailyRolloutDTO.h"
#include "Common/DTO/DailyMenuResponseDTO.h"
#include "Common/DTO/RolloutVotingDTO.h"

#include "DataAccess/FoodItemDAO.h"
#include "DataAccess/UsersDAO.h"
#include "DataAccess/DailyMenuDAO.h"
#include "DataAccess/DailyRolloutDAO.h"
#include "DataAccess/RolloutVotingDAO.h"
#include "DataAccess/FoodFeedbackDAO.h"
#include "DataAccess/DailyMenuResponseDAO.h"

class RecommendationEngineDataHandler {

public:
    

private:
    FoodItemDAO foodItemDAO;
    UsersDAO usersDAO;
    DailyMenuDAO dailyMenuDAO;
    DailyRolloutDAO dailyRolloutDAO;
    RolloutVotingDAO rolloutVotingDAO;
    FoodFeedbackDAO foodFeedbackDAO;
    DailyMenuResponseDAO dailyMenuResponseDAO;

    FoodItemDTO foodItemDTO;
    UserDTO userDTO;
    DailyMenuDTO dailyMenuDTO;
    DailyRolloutDTO dailyRolloutDTO;
    RolloutVotingDTO rolloutVotingDTO;
    FoodFeedbackDTO foodFeedbackDTO;
    
};