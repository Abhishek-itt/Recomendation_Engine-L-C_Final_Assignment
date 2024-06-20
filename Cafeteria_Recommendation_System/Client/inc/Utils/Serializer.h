#pragma once
#include <iostream>
#include <string>
#include <vector>

class Utils {
    public:
        std::vector<std::string> lineDeserializer(std::string data);
        std::vector<std::string> wordDeserializer(std::string data);

        std::string lineSerializer(std::vector<std::string> data);
        std::string wordSerializer(std::vector<std::string> data);
};