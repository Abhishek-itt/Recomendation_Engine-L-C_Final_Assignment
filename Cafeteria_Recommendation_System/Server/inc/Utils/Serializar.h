#pragma once

#include <iostream>
#include <string>
#include <vector>

class Serializer {
public:
    static std::string getBufferFlag(std::string);
    static std::string getBufferMessage(std::string);
    std::vector<std::string> split(std::string);
    std::string serialize(std::vector<std::string>);
};