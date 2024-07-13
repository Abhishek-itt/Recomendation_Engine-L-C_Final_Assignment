#include <iostream>
#include <string>

#include "Utils/Serializar.h"

std::string Serializer::getBufferFlag(std::string data) {
    std::string bufferFlag;
    size_t pos = data.find('\n');
    if (pos != std::string::npos) {
        bufferFlag = data.substr(0, pos);
    }
    return bufferFlag;
}

std::string Serializer::getBufferMessage(std::string data) {
    size_t pos = data.find('\n');
    if (pos != std::string::npos) {
        data = data.substr(pos + 1);
    }
    return data;
}

std::vector<std::string> Serializer::split(std::string data) {
    std::vector<std::string> result;
    std::string temp;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == '\n') {
            result.push_back(temp);
            temp = "";
        } else {
            temp += data[i];
        }
    }
    return result;
}

std::string Serializer::serialize(std::vector<std::string> data) {
    std::string result;
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << std::endl;
        result += data[i] + "\n";
    }
    return result;
}
