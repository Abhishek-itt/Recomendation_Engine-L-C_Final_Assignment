#include "Controller/NotificationController.h"

bool NotificationController::addNotification(std::string notification) {
    return userNotificationDAO.addNotification(notification);
}

bool NotificationController::setReadReceipt(int notificationId) {
    return userNotificationDAO.setReadReceipt(notificationId);
}

std::vector<std::string> NotificationController::getNotifications(std::string userName) {
    return userNotificationDAO.getNotifications(userName);
}
