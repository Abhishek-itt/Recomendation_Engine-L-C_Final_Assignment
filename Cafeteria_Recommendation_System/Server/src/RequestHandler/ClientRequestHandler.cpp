#include "RequestHandler/ClientRequestHandler.h"

#include "Controller/UserController.h"
#include "Controller/FoodItemController.h"
#include "Controller/RolloutController.h"
#include "Controller/VotingController.h"
#include "Controller/MealMenuController.h"
#include "Controller/NotificationController.h"

#include "Utils/RequestTypes.h"

std::string ClientRequestHandler::HandleRequest(std::string requestBuffer)
{
    Serializer serializer;
    UserController userController;
    FoodItemController foodItemController;
    RolloutController rolloutController;
    VotingController votingController;
    MealMenuController mealMenuController;
    NotificationController notificationController;

    RequestType requestType;

    std::string bufferFlag = serializer.getBufferFlag(requestBuffer);
    std::string bufferMessage = serializer.getBufferMessage(requestBuffer);
    std::vector<std::string> bufferMessages = serializer.split(bufferMessage);

    requestType = static_cast<RequestType>(std::stoi(bufferFlag));
    switch (requestType)
    {
    case RequestType::USER_LOGIN:
        {
            bufferMessages = serializer.split(bufferMessage);
            return userController.login(bufferMessages[0], bufferMessages[1]);
        }

    case RequestType::ADD_USER:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (userController.addUser(bufferMessages[0], bufferMessages[1], bufferMessages[2], bufferMessages[3], bufferMessages[4]))
                return "success";
            else
                return "failed";
        }

    case RequestType::ADD_FOOD_ITEM:
        {
            std::cout << "Buffer Flag: " << bufferFlag << std::endl;
            std::cout << "Buffer Message: " << bufferMessage << "end" << std::endl;
            bufferMessages = serializer.split(bufferMessage);
            if (foodItemController.addFoodItem(bufferMessages))
                return "success";
            else
                return "failed";
        }

    case RequestType::DELETE_FOOD_ITEM:
        {
            if (foodItemController.deleteFoodItem(std::stoi(bufferMessage)))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_FOOD_ITEM:
        {
            std::string foodItem = foodItemController.getFoodItem(std::stoi(bufferMessage));
            if (foodItem.empty())
            {
                return "NULL";
            }
            return foodItem;
        }

    case RequestType::GET_FOOD_ITEMS:
        {
            std::string foodItems = serializer.serialize(foodItemController.getFoodItems());
            if (foodItems.empty())
            {
                return "NULL";
            }
            return foodItems;
        }

    case RequestType::ADD_FOOD_FEEDBACK:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (foodItemController.addFoodFeedback(bufferMessages))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_FEEDBACKS_FOR_FOOD:
        {
            std::vector<std::string> feedbacks = foodItemController.getFoodFeedbacks(std::stoi(bufferMessage));
            if (feedbacks.empty())
            {
                return "NULL";
            }
            return serializer.serialize(feedbacks);
        }

    case RequestType::GET_RECOMMENDATION_LIST:
        {
            std::vector<std::string> recommendationList = foodItemController.getRecommendationList(std::stoi(bufferMessage));
            if (recommendationList.empty())
            {
                return "NULL";
            }
            return serializer.serialize(recommendationList);
        }

    case RequestType::ROLLOUT_MEAL_MENU:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (rolloutController.addRolloutMenu(bufferMessages[0], bufferMessages[1], std::stoi(bufferMessages[2])))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_ROLLOUT_MEAL_MENU:
        {
            bufferMessages = serializer.split(bufferMessage);
            std::vector<std::string> rolloutMenu = rolloutController.getRolloutMenu(bufferMessages[0], bufferMessages[1]);
            if (rolloutMenu.empty())
            {
                return "NULL";
            }
            return serializer.serialize(rolloutMenu);
        }

    case RequestType::GET_FOOD_ID_FOR_ROLLOUT:
        {
            std::string foodId = std::to_string(rolloutController.getFoodId(std::stoi(bufferMessage)));
            if (foodId.empty())
            {
                return "NULL";
            }
            return foodId;
        }

    case RequestType::VOTE_ON_ROLLOUT_MENU:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (votingController.voteOnRollout(std::stoi(bufferMessages[0]), bufferMessages[1]))
                return "success";
            else
                return "failed";
        }

    case RequestType::ROLLOUT_MEAL:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (mealMenuController.addMealMenu(bufferMessages[0], bufferMessages[1], std::stoi(bufferMessages[2])))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_MEAL_MENU:
        {
            bufferMessages = serializer.split(bufferMessage);
            std::string mealMenu = mealMenuController.getMealMenu(bufferMessages[0], bufferMessages[1]);
            if (mealMenu.empty())
            {
                return "NULL";
            }
            return mealMenu;
        }

    case RequestType::GET_DIET_PREFERENCE:
        {
            bufferMessages = serializer.split(bufferMessage);
            std::vector<std::string> dietPreference = userController.getUserDietPreference(bufferMessages[0]);
            if (dietPreference.empty())
            {
                return "NULL";
            }
            return serializer.serialize(dietPreference);
        }

    case RequestType::UPDATE_DIET_PREFERENCE:
        {
            bufferMessages = serializer.split(bufferMessage);
            if (userController.updateUserDietPreference(bufferMessages[0], bufferMessages[1], bufferMessages[2], bufferMessages[3], bufferMessages[4]))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_NOTIFICATIONS:
        {
            bufferMessages = serializer.split(bufferMessage);
            std::vector<std::string> notifications = notificationController.getNotifications(bufferMessages[0]);
            if (notifications.empty())
            {
                return "NULL";
            }
            return serializer.serialize(notifications);
        }

    case RequestType::SEND_READ_RECEIPT:
        {
            if (notificationController.setReadReceipt(std::stoi(bufferMessage)))
                return "success";
            else
                return "failed";
        }

    case RequestType::GET_VOTES_ON_ROLLOUT:
        {
            bufferMessages = serializer.split(bufferMessage);
            std::cout << bufferMessages[0] << " " << bufferMessages[1] << std::endl;
            std::vector<std::string> rolloutList = rolloutController.getRolloutMenu(bufferMessages[0], bufferMessages[1]);
            std::cout << "Rollout List: " << std::endl;
            for (std::string rollout : rolloutList)
            {
                std::cout << rollout << std::endl;
            }
            std::vector<std::string> rolloutVotes;

            for (std::string rollout : rolloutList)
            {
                rolloutVotes.push_back(rollout + "\n" + std::to_string(votingController.getVoteCount(std::stoi(rollout))) + "\n");
            }
            for (std::string rolloutVote : rolloutVotes)
            {
                std::cout << rolloutVote << std::endl;
            }
            return serializer.serialize(rolloutVotes);
        }
    }

    std::cout << "Buffer Flag: " << bufferFlag << std::endl;
    std::cout << "Buffer Message: " << bufferMessage << "end" << std::endl;

    return "success";
}