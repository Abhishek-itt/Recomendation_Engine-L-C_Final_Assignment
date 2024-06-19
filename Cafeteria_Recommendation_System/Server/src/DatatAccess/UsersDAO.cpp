#include "DAtaAccess/UsersDAO.h"

UserDTO UsersDAO::getUserByUserName(std::string userName) {
    std::vector<std::vector<std::string>> result;
    std::string query = "SELECT * FROM Users WHERE user_name = '" + userName + "'";
    std::cout << "query: " << query << std::endl;
    result = mySqlDBAccess.fetchData(query); 
    std::cout << "sizeof result: " << result.size() << std::endl;   
    UserDTO userDTO;
    if (result.size() == 0) {
        return userDTO;
    }
    else
    {
        for (auto i: result) {
            for (auto j: i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }

    std::cout << sizeof(result[0]) << std::endl;    
    userDTO.user_name = result[0][0];
    std::cout << std::stoi(result[0][1]) << std::endl;
    userDTO.employee_id = std::stoi(result[0][1]);
    userDTO.user_type = result[0][2];
    userDTO.first_name = result[0][3];
    userDTO.last_name = result[0][4];
    }
    std::cout << "log" << std::endl;
    return userDTO;
}

