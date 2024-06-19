#include "Database/MySql/MySqlDBAccess.h"

MySqlDBAccess::MySqlDBAccess() {
    try {
        mySqlDriver = get_driver_instance();
        this->connect();
    } catch (sql::SQLException& e) {
        std::cerr << "Error connecting to MySQL: " << e.what() << std::endl;
        throw;
    }
}

MySqlDBAccess::~MySqlDBAccess() {
    this->disconnect();
}

void MySqlDBAccess::connect() {
    try {
        mySqlConnection = mySqlDriver->connect(HOST, USER, PASSWORD);
        mySqlStatement = mySqlConnection->createStatement();

        mySqlConnection->setSchema(DATABASE);
    } catch (sql::SQLException& e) {
        std::cerr << "Error connecting to MySQL: " << e.what() << std::endl;
        throw;
    }
}

void MySqlDBAccess::disconnect() {
    mySqlConnection->close();

    delete mySqlStatement;
    delete mySqlConnection;
}

bool MySqlDBAccess::executeQuery(std::string query) {
    try {
        mySqlResultSet = mySqlStatement->executeQuery(query);
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Error executing query: " << e.what() << std::endl;
        return false;
    }
}

bool MySqlDBAccess::executeUpdate(std::string query) {
    try {
        mySqlStatement->executeUpdate(query);
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Error executing update: " << e.what() << std::endl;
        return false;
    }
}

std::vector<std::vector<std::string>> MySqlDBAccess::fetchData(std::string query) {
    std::vector<std::vector<std::string>> data;
    try {
        mySqlResultSet = mySqlStatement->executeQuery(query);
        int columnCount = mySqlResultSet->getMetaData()->getColumnCount();

        while (mySqlResultSet->next()) {
            std::vector<std::string> row;
            for (int i = 1; i <= columnCount; i++) {
                row.push_back(mySqlResultSet->getString(i));
            }
            data.push_back(row);
        }
    } catch (sql::SQLException& e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
    return data;
}
