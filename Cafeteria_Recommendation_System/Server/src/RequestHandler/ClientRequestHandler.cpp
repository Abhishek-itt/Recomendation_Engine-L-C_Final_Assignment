#include "RequestHandler/ClientRequestHandler.h"

#include "Controller/UserController.h"
#include "Controller/CRUDController.h"
#include "Controller/RolloutController.h"
#include "Controller/VotingController.h"
#include "Controller/MealMenuController.h"

#include "Utils/RequestTypes.h"

std::string ClientRequestHandler::HandleRequest(std::string requestBuffer) {
    Serializer serializer;
    UserController userController;
    CRUDController crudController;
    RolloutController rolloutController;
    VotingController votingController;
    MealMenuController mealMenuController;

    RequestType requestType;

    std::string bufferFlag = serializer.getBufferFlag(requestBuffer);
    std::string bufferMessage = serializer.getBufferMessage(requestBuffer);
    std::vector<std::string> bufferMessages = serializer.split(bufferMessage);

    requestType = static_cast<RequestType>(std::stoi(bufferFlag));
    switch (requestType) {
        case RequestType::USER_LOGIN:
            bufferMessages = serializer.split(bufferMessage);
            return userController.login(bufferMessages[0], bufferMessages[1]);

        case RequestType::ADD_USER:
            bufferMessages = serializer.split(bufferMessage);
            if (userController.addUser(bufferMessages[0], bufferMessages[1], bufferMessages[2], bufferMessages[3], bufferMessages[4]))
                return "success";
            else
                return "failed";

        case RequestType::ADD_FOOD_ITEM:
            std::cout << "Buffer Flag: " << bufferFlag << std::endl;
            std::cout << "Buffer Message: " << bufferMessage << "end" << std::endl;
            bufferMessages = serializer.split(bufferMessage);
            if (crudController.addFoodItem(bufferMessages))
                return "success";
            else
                return "failed";

        case RequestType::DELETE_FOOD_ITEM:
            if (crudController.deleteFoodItem(std::stoi(bufferMessage)))
                return "success";
            else
                return "failed";

        case RequestType::GET_FOOD_ITEM:
            return crudController.getFoodItem(std::stoi(bufferMessage));
        
        case RequestType::GET_FOOD_ITEMS:
            return serializer.serialize(crudController.getFoodItems());

        case RequestType::ADD_FOOD_FEEDBACK:
            bufferMessages = serializer.split(bufferMessage);
            if (crudController.addFoodFeedback(bufferMessages))
                return "success";
            else
                return "failed";

        case RequestType::GET_FEEDBACKS_FOR_FOOD:
            return serializer.serialize(crudController.getFoodFeedbacks(std::stoi(bufferMessage)));

        case RequestType::GET_RECOMMENDATION_LIST:
            return serializer.serialize(crudController.getRecommendationList(std::stoi(bufferMessage)));

        case RequestType::ROLLOUT_MEAL_MENU:
            bufferMessages = serializer.split(bufferMessage);
            if (rolloutController.addRolloutMenu(bufferMessages[0], bufferMessages[1], std::stoi(bufferMessages[2])))
                return "success";
            else
                return "failed";
        case RequestType::GET_ROLLOUT_MEAL_MENU:
            bufferMessages = serializer.split(bufferMessage);
            return serializer.serialize(rolloutController.getRolloutMenu(bufferMessages[0], bufferMessages[1]));

        case RequestType::GET_FOOD_ID_FOR_ROLLOUT:
            return std::to_string(rolloutController.getFoodId(std::stoi(bufferMessage)));

        case RequestType::VOTE_ON_ROLLOUT_MENU:
            bufferMessages = serializer.split(bufferMessage);
            if (votingController.voteOnRollout(std::stoi(bufferMessages[0]), bufferMessages[1]))
                return "success";
            else
                return "failed";

        case RequestType::ROLLOUT_MEAL:
            bufferMessages = serializer.split(bufferMessage);
            if (mealMenuController.addMealMenu(bufferMessages[0], bufferMessages[1], std::stoi(bufferMessages[2])))
                return "success";
            else
                return "failed";

        case RequestType::GET_MEAL_MENU:
            bufferMessages = serializer.split(bufferMessage);
            return mealMenuController.getMealMenu(bufferMessages[0], bufferMessages[1]);

        case RequestType::GET_VOTES_ON_ROLLOUT:
            bufferMessages = serializer.split(bufferMessage);
            std::cout << bufferMessages[0] << " " << bufferMessages[1] << std::endl;
            std::vector<std::string> rolloutList = rolloutController.getRolloutMenu(bufferMessages[0], bufferMessages[1]);
            std::cout << "Rollout List: " << std::endl;
            for (std::string rollout : rolloutList) {
                std::cout << rollout << std::endl;
            }
            std::vector<std::string> rolloutVotes;

            for (std::string rollout : rolloutList) {
                rolloutVotes.push_back(rollout + "\n" +std::to_string(votingController.getVoteCount(std::stoi(rollout))) + "\n");
            }
            for (std::string rolloutVote : rolloutVotes) {
                std::cout << rolloutVote << std::endl;
            }
            return serializer.serialize(rolloutVotes);

    }

    std::cout << "Buffer Flag: " << bufferFlag << std::endl;
    std::cout << "Buffer Message: " << bufferMessage << "end" << std::endl;

    return "success";
}