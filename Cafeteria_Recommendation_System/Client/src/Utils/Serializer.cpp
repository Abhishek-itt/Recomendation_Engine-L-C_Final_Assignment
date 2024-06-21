#include "Utils/Serializer.h"

std::vector<std::string> Utils::lineDeserializer(std::string data) {
    std::vector<std::string> result;
    std::string temp;
    std::cout << data.size() << strlen(data.c_str()) << std::endl;  
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == '\n' && data[i + 1] == '\n') {
            result.push_back(temp);
            temp = "";
        } else {
            temp += data[i];
        }
    }
    return result;
}

std::vector<std::string> Utils::wordDeserializer(std::string data) {
    std::vector<std::string> result;
    data += "\n";
    if (data.at(0) == '\n')
        data = data.substr(1);

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

std::string Utils::lineSerializer(std::vector<std::string> data) {
    std::string result;
    for (int i = 0; i < data.size(); i++) {
        result += data[i] + "\n\n";
    }
    return result;
}

std::string Utils::wordSerializer(std::vector<std::string> data) {
    std::string result;
    for (int i = 0; i < data.size(); i++) {
        result += data[i] + "\n";
    }
    return result;
}