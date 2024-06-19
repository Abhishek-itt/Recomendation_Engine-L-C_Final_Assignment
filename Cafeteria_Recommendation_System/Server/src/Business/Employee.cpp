#include "Employee.h"

bool Employee::login(std::string username, int employeeId) {
    userDTO = usersDAO.getUserByUserName(username);

    if (userDTO.employee_id == employeeId) {
        if (userDTO.user_type == "Employee") {
            return true;
        }
    }
    return false;
}