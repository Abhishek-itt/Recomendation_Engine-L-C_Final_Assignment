#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "RequestTypes.h"
#include "Presentation/SocketServer.h"

#include "Business/Admin.h"
#include "Business/Employee.h"
#include "Business/Chef.h"
#include "Business/User.h"

#include "DTO/UserDTO.h"
#include "DTO/FoodItemDTO.h"
#include "DTO/DailyRolloutDTO.h"
#include "DTO/RolloutVotingDTO.h"
#include "DTO/FoodFeedbackDTO.h"
#include "DTO/DailyMenuDTO.h"
#include "DTO/DailyMenuResponseDTO.h"

class ClientRequestHandler {
public:
    std::string handleClientRequest(std::string request);
    RequestType getRequestType(std::string request);
    std::string getRequestData(std::string request);

    std::string createResponse(ResponseType responseType, std::string data);
    std::vector<std::string> splitRequestData(std::string data);
    
private:
    RequestType requestType;
    ResponseType responseType;

    Admin admin;
    Employee employee;
    Chef chef;
    User user;


    
};