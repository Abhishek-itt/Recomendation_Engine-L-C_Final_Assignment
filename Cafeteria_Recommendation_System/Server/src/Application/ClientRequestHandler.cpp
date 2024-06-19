#include "Application/ClientRequestHandler.h"


std::string ClientRequestHandler::handleClientRequest(std::string request) {
    requestType = getRequestType(request);
    std::string requestData = getRequestData(request);
    std::string responseData;
    std::string response;
    std::vector<std::string> requestDataArray = splitRequestData(requestData);
    std::vector<FoodItemDTO> foodItems;

    UserDTO userDTO;
    FoodItemDTO foodItemDTO;

    switch(requestType) {
        case RequestType::ADMIN_LOGIN:
            userDTO.deserializeDataFromNSV(requestData);
            if(admin.login(userDTO.user_name, userDTO.employee_id))
            {
                responseData = "success";
                responseType = ResponseType::SUCCESS;
            }
            else
            {
                responseData = "failure";
                responseType = ResponseType::FAILURE;
            }
            response =  createResponse(responseType, responseData);
            break;

        case RequestType::CHEF_LOGIN:
            userDTO.deserializeDataFromNSV(requestData);
            if(chef.login(userDTO.user_name, userDTO.employee_id))
            {
                responseData = "success";
                responseType = ResponseType::SUCCESS;
            }
            else
            {
                responseData = "failure";
                responseType = ResponseType::FAILURE;
            }
            response =  createResponse(responseType, responseData);
            break;

        case RequestType::EMPLOYEE_LOGIN:

            userDTO.deserializeDataFromNSV(requestData);
            if(employee.login(userDTO.user_name, userDTO.employee_id))
            {
                responseData = "success";
                responseType = ResponseType::SUCCESS;
            }
            else
            {
                responseData = "failure";
                responseType = ResponseType::FAILURE;
            }
            response =  createResponse(responseType, responseData);
            break;

        case RequestType::ADD_FOOD_ITEM:
            foodItemDTO.deserializeDataFromNSV(requestData);
            if(admin.addFoodItem(foodItemDTO))
            {
                responseData = "success";
                responseType = ResponseType::SUCCESS;
            }
            else
            {
                responseData = "failure";
                responseType = ResponseType::FAILURE;
            }
            response =  createResponse(responseType, responseData);
            break;
        
        case RequestType::FETCH_FOOD_ITEM_LIST:
            foodItems = user.getFoodItems();
            responseData = "";
            for(FoodItemDTO foodItem : foodItems)
            {
                responseType = ResponseType::SUCCESS;
                responseData += foodItem.serializeDataAsNSV();
            }
            response =  createResponse(ResponseType::SUCCESS, responseData);
            break;

        case RequestType::REMOVE_FOOD_ITEM:
            if(admin.removeFoodItem(std::stoi(requestDataArray[0])))
            {
                responseData = "success";
                responseType = ResponseType::SUCCESS;
            }
            else
            {
                responseData = "failure";
                responseType = ResponseType::FAILURE;
            }
            response =  createResponse(responseType, responseData);
            break;
    }

    return response;
}

RequestType ClientRequestHandler::getRequestType(std::string request) {
    std::string requestTypeString = request.substr(0, request.find("\n"));
    return static_cast<RequestType>(std::stoi(requestTypeString));
}

std::string ClientRequestHandler::getRequestData(std::string request) {
    return request.substr(request.find("\n") + 1);
}

std::string ClientRequestHandler::createResponse(ResponseType responseType, std::string data) {
    return std::to_string(static_cast<int>(responseType)) + "\n" + data + "\n";
}

std::vector<std::string> ClientRequestHandler::splitRequestData(std::string data) {
    std::vector<std::string> splitData;
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, pos);
        splitData.push_back(token);
        data.erase(0, pos + delimiter.length());
    }
    splitData.push_back(data);
    return splitData;
}

