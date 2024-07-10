#include "View/ChefView.h"
#include <limits>

void ChefView::chefLandingPage()
{
    while (true)
    {
        std::cout << "Chef Home" << std::endl;
        std::cout << "1. View All Food Items" << std::endl;
        std::cout << "2. View Food Item" << std::endl;
        std::cout << "3. Get Recommended List" << std::endl;
        std::cout << "4. Rollout Meal Menu" << std::endl;
        std::cout << "5. View Votes on Rollout" << std::endl;
        std::cout << "6. Rollout Meal" << std::endl;
        std::cout << "7. Logout" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 7)
        {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            this->viewAllFoodItems();
            break;
        case 2:
            this->viewFoodItem();
            break;
        case 3:
            this->getRecommendedList();
            break;
        case 4:
            this->rolloutMealMenu();
            break;
        case 5:
            this->viewVotesOnRollout();
            break;
        case 6:
            this->rolloutMeal();
            break;
        case 7:
            this->logout();
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
    for (const std::string& foodItem : foodItemsData)
    {
        std::vector<std::string> foodItemData = utils.wordDeserializer(foodItem);
        std::cout << foodItemData[0] << "\t" << foodItemData[1] << "\t" << foodItemData[2] << "\t" << foodItemData[3] << "\t" << foodItemData[4] << std::endl;
    }
}

void ChefView::viewFoodItem()
{
    unsigned int foodId;
    std::cout << "Enter food id: ";
    while (!(std::cin >> foodId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid food id: ";
    }

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
    while (!(std::cin >> count))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number: ";
    }

    std::string recommendedList = chefController.getRecommendationList(count);
    std::cout << recommendedList << std::endl;
}

void ChefView::rolloutMealMenu()
{
    std::string date;
    std::string mealType;
    unsigned int foodId;

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    getRecommendedList();

    std::cout << "Enter number of food items to roll out: ";
    int count;
    while (!(std::cin >> count))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number: ";
    }

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter food id: ";
        while (!(std::cin >> foodId))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid food id: ";
        }

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

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::string rolloutVotes = this->chefController.getVotesOnRollout(date, mealType);
    std::vector<std::string> rolloutVotesData = utils.lineDeserializer(rolloutVotes);
    for (const std::string& rolloutVote : rolloutVotesData)
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

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter meal type: ";
    std::cin >> mealType;

    std::cout << "Enter food id: ";
    while (!(std::cin >> foodId))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid food id: ";
    }

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
