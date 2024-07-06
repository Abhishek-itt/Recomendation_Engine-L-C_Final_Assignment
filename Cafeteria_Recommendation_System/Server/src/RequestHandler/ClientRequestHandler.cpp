#include "RequestHandler/ClientRequestHandler.h"

#include "Controller/UserController.h"
#include "Controller/CRUDController.h"

#include "Utils/RequestTypes.h"

std::string ClientRequestHandler::HandleRequest(std::string requestBuffer) {
    Serializer serializer;
    UserController userController;
    CRUDController crudController;

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
        default:
            return "FAILED";
    }

    std::cout << "Buffer Flag: " << bufferFlag << std::endl;
    std::cout << "Buffer Message: " << bufferMessage << "end" << std::endl;

    return "success";
}