#pragma once
#include <iostream>
#include <vector>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


const std::string HOST = "localhost";
const std::string USER = "abhishek";
const std::string PASSWORD = "ITTAbhi@7684";
const std::string DATABASE = "cafetarea";

class MySqlDBAccess{
public:
    MySqlDBAccess();
    ~MySqlDBAccess();
    void connect();
    void disconnect();

    bool executeQuery(std::string query);
    bool executeUpdate(std::string query);

    bool execute(std::string query);

    std::vector<std::vector<std::string>> fetchData(std::string query);

private:

    sql::Driver* mySqlDriver;
    sql::Connection* mySqlConnection;
    sql::Statement* mySqlStatement;
    sql::ResultSet* mySqlResultSet;
};