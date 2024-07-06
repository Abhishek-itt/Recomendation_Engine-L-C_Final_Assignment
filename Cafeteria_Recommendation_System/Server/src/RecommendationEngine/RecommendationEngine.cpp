#include "RecommendationEngine/RecommendationEngine.h"

float RecommendationScoreCalculator::calculateRecommendationScore(unsigned int foodId) {
    avgTasteRating = getAverageTasteRating(foodId);
    avgQualityRating = getAverageQualityRating(foodId);
    avgVoteCount = getVoteCount(foodId);
    totalRollout = getRolloutCount(foodId);
    totalMealCount = getMealMenuCount(foodId);

    float tasteScore = avgTasteRating * 0.4;
    float qualityScore = avgQualityRating * 0.3;
    float voteScore = avgVoteCount * 0.1;
    float rolloutScore = totalRollout * 0.05;
    float mealScore = totalMealCount * 0.05;

    return tasteScore + qualityScore + voteScore + rolloutScore + mealScore;
}

float RecommendationScoreCalculator::getAverageTasteRating(unsigned int foodId) {
    return foodFeedbackDAO.getAverageTasteRating(foodId);
}

float RecommendationScoreCalculator::getAverageQualityRating(unsigned int foodId) {
    return foodFeedbackDAO.getAverageQualityRating(foodId);
}

float RecommendationScoreCalculator::getVoteCount(unsigned int foodId) {
    return rolloutVotingDAO.getVoteCountForFoodItem(foodId);
}

float RecommendationScoreCalculator::getRolloutCount(unsigned int foodId) {
    return rolloutMenuDAO.getRolloutCount(foodId);
}

float RecommendationScoreCalculator::getMealMenuCount(unsigned int foodId) {
    return mealMenuDAO.getMealMenuCount(foodId);
}

void RecommendationEngine::getFoodItems() {
    foodItems = foodItemDAO.getFoodItems();
}

void RecommendationEngine::calculateRecommendationScores() {
    for (auto foodItem : foodItems) {
        RecommendationScoreCalculator recommendationScoreCalculator;
        std::cout << "Food ID: " << foodItem.food_id << std::endl;
        std::cout << "Food Name: " << foodItem.food_name << std::endl;
        float recommendationScore = recommendationScoreCalculator.calculateRecommendationScore(foodItem.food_id);
        std::cout << "Recommendation Score: " << recommendationScore << std::endl;
        recommendationScores.push_back(std::make_pair(foodItem.food_id, recommendationScore));
    }
}

std::vector<FoodItemDTO> RecommendationEngine::getRecommendedFoodItems(unsigned int count) {
    getFoodItems();
    calculateRecommendationScores();

    std::sort(recommendationScores.begin(), recommendationScores.end(), [](std::pair<unsigned int, float> a, std::pair<unsigned int, float> b) {
        return a.second > b.second;
    });

    for (int i = 0; i < count; i++) {
        recommendedFoodItems.emplace_back(foodItemDAO.getFoodItem(recommendationScores[i].first));
    }

    return recommendedFoodItems;
}