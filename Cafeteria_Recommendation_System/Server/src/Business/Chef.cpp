#include "Chef.h"

bool Chef::login(std::string username, int employeeId) {
    userDTO = usersDAO.getUserByUserName(username);

    if (userDTO.employee_id == employeeId) {
        if (userDTO.user_type == "Chef") {
            return true;
        }
    }
    return false;
}