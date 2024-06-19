#pragma once
#include <iostream>

enum class RequestType {
    ADMIN_LOGIN = 1,
    EMPLOYEE_LOGIN,
    CHEF_LOGIN,
    ADD_FOOD_ITEM,
    FETCH_FOOD_ITEM_LIST,
    REMOVE_FOOD_ITEM,
};

enum class ResponseType {
    SUCCESS = 1,
    FAILURE = 2
};

class SocketRequest {
public:
    std::string requestData;
    RequestType requestType;
};

class SocketResponse {
public:
    std::string responseData;
    ResponseType responseType;
};
