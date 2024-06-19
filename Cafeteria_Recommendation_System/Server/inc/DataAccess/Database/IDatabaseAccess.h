#pragma once

#include <iostream>
#include <vector>

const std::string HOST = "localhost";
const std::string USER = "abhishek";
const std::string PASSWORD = "ITTAbhi@7684";
const std::string DATABASE = "cafetarea";

class IDatabaseAccess {
public:
    virtual ~IDatabaseAccess() {}

    virtual void connect() = 0;
    virtual void disconnect() = 0;

    virtual bool execute(std::string query) = 0;

    virtual std::vector<std::vector<std::string>> fetchData(std::string query) = 0;
};
