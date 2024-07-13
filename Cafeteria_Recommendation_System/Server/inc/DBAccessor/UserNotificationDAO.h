#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"

class UserNotificationDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addNotification(std::string notification);
    bool setReadReceipt(int notificationId);
    std::vector<std::string> getNotifications(std::string userName);
    

};