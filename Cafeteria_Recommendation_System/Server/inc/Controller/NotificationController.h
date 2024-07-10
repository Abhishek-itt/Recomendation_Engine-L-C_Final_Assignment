#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "DBAccessor/UserNotificationDAO.h"

class NotificationController {

public:
    bool addNotification(std::string notification);
    bool setReadReceipt(int notificationId);
    std::vector<std::string> getNotifications(std::string userName);

private:
    UserNotificationDAO userNotificationDAO;
};