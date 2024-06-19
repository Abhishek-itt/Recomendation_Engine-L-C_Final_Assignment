#include "RequestTypes.h"

std::string createRequestString(RequestType requestType, std::string data) {
    return std::to_string(static_cast<int>(requestType)) + "\n" + data;
}

std::string createResponseString(ResponseType responseType, std::string data) {
    return std::to_string(static_cast<int>(responseType)) + "\n" + data;
}
