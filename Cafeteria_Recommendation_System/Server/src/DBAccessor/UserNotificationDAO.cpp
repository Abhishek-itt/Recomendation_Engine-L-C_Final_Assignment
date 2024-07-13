#include "DBAccessor/UserNotificationDAO.h"

bool UserNotificationDAO::addNotification(std::string notification)
{
    std::string query = "INSERT INTO User_Notifications (user_name, notification) SELECT user_name, '" + notification + "' FROM Users";
    std::cout << query << std::endl;
    return mySqlDBAccess.executeUpdate(query);
}

bool UserNotificationDAO::setReadReceipt(int notificationId)
{
    std::string query = "UPDATE User_Notifications SET read_receipt = 1 WHERE notification_id = " + std::to_string(notificationId);
    return mySqlDBAccess.executeUpdate(query);
}

std::vector<std::string> UserNotificationDAO::getNotifications(std::string userName)
{
    std::vector<std::string> notifications;
    std::string query = "SELECT notification_id, message FROM User_Notifications WHERE user_name = '" + userName + "'";
    std::cout << query << std::endl;
    std::vector<std::vector<std::string>> data = mySqlDBAccess.fetchData(query);
    for (std::vector<std::string> row : data)
    {
        std::cout << row[0] << " " << row[1] << std::endl;
        notifications.push_back(row[0] + "\n" + row[1] + "\n");
    }
    return notifications;
}