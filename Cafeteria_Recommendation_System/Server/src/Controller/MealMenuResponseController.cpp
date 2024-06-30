#include "Controller/MealMenuResponseController.h"

std::string MealMenuResponseController::getMealMenuResponse(unsigned int mealMenuId, std::string userName)
{
    MealMenuResponseDTO mealMenuResponse = mealMenuResponseDAO.getMealMenuResponse(mealMenuId, userName);
    return mealMenuResponse.response;
}

std::vector<std::string> MealMenuResponseController::getMealMenuResponses(unsigned int mealMenuId)
{
    std::vector<MealMenuResponseDTO> mealMenuResponses = mealMenuResponseDAO.getMealMenuResponses(mealMenuId);
    std::vector<std::string> responses;
    for (MealMenuResponseDTO mealMenuResponse : mealMenuResponses)
    {
        responses.push_back(mealMenuResponse.response);
    }
    return responses;
}

bool MealMenuResponseController::addMealMenuResponse(int mealMenuId, std::string userName, std::string response)
{
    MealMenuResponseDTO mealMenuResponse;
    mealMenuResponse.mealMenuId = mealMenuId;
    mealMenuResponse.userName = userName;
    mealMenuResponse.response = response;

    return mealMenuResponseDAO.addMealMenuResponse(mealMenuResponse);
}