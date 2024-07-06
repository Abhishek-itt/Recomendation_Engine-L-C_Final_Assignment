#include "View/ChefView.h"

void ChefView::chefLandingPage()
{
    while (true)
    {
        std::cout << "Chef Home" << std::endl;
        std::cout << "5. View All Food Items" << std::endl;
        std::cout << "6. View Food Item" << std::endl;
        std::cout << "8. get recommended list." << std::endl;    
        std::cout << "9. Rollout Meal Menu" << std::endl;
        std::cout << "13. View Votes on Rollout" << std::endl;
        std::cout << "14. Rollout Meal" << std::endl;
        std::cout << "16. Logout" << std::endl;

        std::cout << "Enter your choice: ";

        RequestType requestType;
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        requestType = static_cast<RequestType>(choice);

        switch (requestType)
        {
        case RequestType::GET_FOOD_ITEMS:
            this->viewAllFoodItems();
            break;
        case RequestType::GET_FOOD_ITEM:
            this->viewFoodItem();
            break;
        case RequestType::GET_RECOMMENDATION_LIST:
            this->getRecommendedList();
            break;
        case RequestType::ROLLOUT_MEAL_MENU:
            this->rolloutMealMenu();
            break;
        case RequestType::GET_VOTES_ON_ROLLOUT:
            this->viewVotesOnRollout();
            break;
        case RequestType::ROLLOUT_MEAL:
            this->rolloutMeal();
            break;
        case RequestType::LOGOUT:
            this->logout();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            exit(0);
            break;
        }
    }
}

void ChefView::viewAllFoodItems()
{
    std::string foodItems = this->chefController.getFoodItemList();
    std::cout << foodItems << std::endl;

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

void ChefView::viewFoodItem()
{
    unsigned int foodId;
    std::cout << "Enter food id: ";
    std::cin >> foodId;

    std::string foodItem = this->chefController.getFoodItem(foodId);
    std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);

    std::cout << "Food Id: " << foodItemData[0] << std::endl;
    std::cout << "Food Name: " << foodItemData[1] << std::endl;
    std::cout << "Price: " << foodItemData[2] << std::endl;
    std::cout << "Availability: " << foodItemData[3] << std::endl;
    std::cout << "Description: " << foodItemData[4] << std::endl;
}

void ChefView::getRecommendedList()
{
    int count;
    std::cout << "Enter number of recommended items: ";
    std::cin >> count;
    std::string recommendedList = chefController.getRecommendationList(count);
    std::cout << recommendedList << std::endl;
}

void ChefView::rolloutMealMenu()
{
    std::string date;
    std::string mealType;
    unsigned int foodId;

    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    getRecommendedList();

    std::cout << "Enter number of food items to roll out: ";
    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter food id: ";
        std::cin >> foodId;

        if (this->chefController.rolloutMealMenu(date, mealType, foodId))
        {
            std::cout << "Meal menu rolled out successfully for food id " << foodId << std::endl;
        }
        else
        {
            std::cout << "Failed to roll out meal menu for food id " << foodId << std::endl;
        }
    }
}

void ChefView::viewVotesOnRollout()
{
    std::string date;
    std::string mealType;

    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::string rolloutVotes = this->chefController.getVotesOnRollout(date, mealType);
    std::vector<std::string> rolloutVotesData = utils.lineDeserializer(rolloutVotes);
    for (std::string rolloutVote : rolloutVotesData)
    {
        std::vector<std::string> rolloutVoteData = utils.wordDeserializer(rolloutVote);
        std::cout << "Food Id: " << rolloutVoteData[0] << "\t" << "Votes: " << rolloutVoteData[1] << std::endl;
    }
}

void ChefView::rolloutMeal()
{
    std::string date;
    std::string mealType;
    unsigned int foodId;

    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::cout << "Enter food id: ";
    std::cin >> foodId;

    if (this->chefController.rolloutMeal(date, mealType, foodId))
    {
        std::cout << "Meal rolled out successfully for food id " << foodId << std::endl;
    }
    else
    {
        std::cout << "Failed to roll out meal for food id " << foodId << std::endl;
    }
}

void ChefView::logout()
{
    std::cout << "Logging out" << std::endl;
    this->chefController.logout();
}