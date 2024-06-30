#include "RecommendationEngine/RecommendationEngine.h"

float RecommendationScoreCalculator::calculateRecommendationScore(unsigned int foodId) {
    avgTasteRating = getAverageTasteRating();
    avgQualityRating = getAverageQualityRating();
    avgVoteCount = getVoteCount();
    totalRollout = getRolloutCount();
    totalMealCount = getMealMenuCount();

    float tasteScore = avgTasteRating * 0.4;
    float qualityScore = avgQualityRating * 0.3;
    float voteScore = avgVoteCount * 0.1;
    float rolloutScore = totalRollout * 0.05;
    float mealScore = totalMealCount * 0.05;

    return tasteScore + qualityScore + voteScore + rolloutScore + mealScore;
}

float RecommendationScoreCalculator::getAverageTasteRating() {
    return foodFeedbackDAO.getAverageTasteRating(foodId);
}

float RecommendationScoreCalculator::getAverageQualityRating() {
    return foodFeedbackDAO.getAverageQualityRating(foodId);
}

float RecommendationScoreCalculator::getVoteCount() {
    return rolloutVotingDAO.getVoteCountForFoodItem(foodId);
}

float RecommendationScoreCalculator::getRolloutCount() {
    return rolloutMenuDAO.getRolloutCount(foodId);
}

float RecommendationScoreCalculator::getMealMenuCount() {
    return mealMenuDAO.getMealMenuCount(foodId);
}

void RecommendationEngine::getFoodItems() {
    foodItems = foodItemDAO.getFoodItems();
}

void RecommendationEngine::calculateRecommendationScores() {
    for (auto foodItem : foodItems) {
        RecommendationScoreCalculator recommendationScoreCalculator;
        float recommendationScore = recommendationScoreCalculator.calculateRecommendationScore(foodItem.food_id);
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