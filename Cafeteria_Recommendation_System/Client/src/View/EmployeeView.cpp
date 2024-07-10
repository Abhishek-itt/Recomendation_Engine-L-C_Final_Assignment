#include "View/EmployeeView.h"

EmployeeView::EmployeeView(std::string username)
{
    this->username = username;
}

void EmployeeView::employeeLandingPage()
{
    while (true)
    {
        std::cout << "Welcome to Cafeteria" << std::endl;
        std::cout << "1. View all food items" << std::endl;
        std::cout << "2. View food item" << std::endl;
        std::cout << "3. Give feedback" << std::endl;
        std::cout << "4. View food feedback" << std::endl;
        std::cout << "5. Get Rollout Menu" << std::endl;
        std::cout << "6. Vote on Rollout Menu" << std::endl;
        std::cout << "7. View Meal Menu" << std::endl;
        std::cout << "8. Logout" << std::endl;

        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            viewAllFoodItems();
            break;
        case 2:
            viewFoodItem();
            break;
        case 3:
            giveFeedback();
            break;
        case 4:
            viewFoodFeedback();
            break;
        case 5:
            viewRolloutMenu();
            break;
        case 6:
            voteOnRolloutMenu();
            break;
        case 7:
            viewMealMenu();
            break;
        case 8:
            logout();
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
}

void EmployeeView::viewAllFoodItems()
{
    std::string foodItems = this->employeeController.getFoodItemList();

    std::vector<std::string> foodItemsData = utils.lineDeserializer(foodItems);
    // Print table header
    std::cout << "Food Id\tFood Name\tPrice\tAvailability\tDescription" << std::endl;

    // Print table rows
    for (std::string foodItem : foodItemsData)
    {
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);
        std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
    }
}

void EmployeeView::viewFoodItem()
{
    unsigned int foodId;
    std::cout << "Enter food id: ";
    std::cin >> foodId;
    std::string foodItem = this->employeeController.getFoodItem(foodId);
    std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);

    std::cout << "Food Id: " << foodItemData[0] << std::endl;
    std::cout << "Food Name: " << foodItemData[1] << std::endl;
    std::cout << "Price: " << foodItemData[2] << std::endl;
    std::cout << "Availability: " << foodItemData[3] << std::endl;
    std::cout << "Description: " << foodItemData[4] << std::endl;
}

void EmployeeView::giveFeedback()
{
    std::cout << "Enter food ID: ";
    unsigned int foodId;
    std::cin >> foodId;

    std::cout << "Enter taste rating: ";
    unsigned int tasteRating;
    std::cin >> tasteRating;

    std::cout << "Enter quality rating: ";
    unsigned int qualityRating;
    std::cin >> qualityRating;

    std::cout << "Enter review: ";
    std::string review;
    std::getline(std::cin, review);

    bool success = employeeController.giveFeedback(foodId, "david_lee", tasteRating, qualityRating, review);
    if (success)
    {
        std::cout << "Feedback added successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to add feedback" << std::endl;
    }
}

void EmployeeView::viewFoodFeedback()
{
    std::cout << "Enter food ID: ";
    unsigned int foodId;
    std::cin >> foodId;

    std::string response = employeeController.getFeedback(foodId);

    std::vector<std::string> feedbackData = utils.lineDeserializer(response);

    std::cout << "Username\tTaste Rating\tQuality Rating\tReview" << std::endl;
    for (std::string feedback : feedbackData)
    {
        std::vector<std::string> feedbackItem = utils.wordDeserializer(feedback);
        std::cout << feedbackItem[0] << "\t" << feedbackItem[1] << "\t" << feedbackItem[2] << "\t" << feedbackItem[3] << std::endl;
    }
}

void EmployeeView::viewRolloutMenu()
{
    std::string date;
    std::string mealType;

    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::string response = employeeController.getRolloutMenu(date, mealType);

    std::vector<std::string> rolloutMenuData = utils.wordDeserializer(response);

    for (std::string rolloutId : rolloutMenuData)
    {
        std::cout << "Rollout ID: " << rolloutId << std::endl;
        unsigned int rolloutFoodId = employeeController.getFoodId(std::stoi(rolloutId));
        std::cout << "rollout food id " << rolloutFoodId << std::endl;
        std::string foodDetails = employeeController.getFoodItem(rolloutFoodId);
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodDetails);

        std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
    }
}

void EmployeeView::voteOnRolloutMenu()
{
    unsigned int rolloutId;
    std::cout << "Enter rollout id: ";
    std::cin >> rolloutId;

    bool success = employeeController.voteOnRollout(rolloutId, username);
    if (success)
    {
        std::cout << "Voted successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to vote" << std::endl;
    }
}

void EmployeeView::viewMealMenu()
{
    std::string date;
    std::string mealType;

    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::string response = employeeController.getMealMenu(date, mealType);
    std::string foodDetails = employeeController.getFoodItem(std::stoi(response));
    std::vector<std::string> foodItemData = utils.wordDeserializer(foodDetails);

    std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
}

void EmployeeView::logout()
{
    std::cout << "Logging out" << std::endl;
    employeeController.logout();
}