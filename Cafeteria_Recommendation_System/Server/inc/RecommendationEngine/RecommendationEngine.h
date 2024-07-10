#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

#include "DBAccessor/FoodItemDAO.h"
#include "DBAccessor/FoodFeedbackDAO.h"
#include "DBAccessor/RolloutMenuDAO.h"
#include "DBAccessor/RolloutVotingDAO.h"
#include "DBAccessor/MealMenuDAO.h"
#include "DBAccessor/MealMenuResponseDAO.h"

#define NEGATIVE_WORD_SCORE -10
#define SENTIMENT_WORDS_FILE_PATH "../../sentiment_words.txt"

class RecommendationEngine {
public:
    std::vector<FoodItemDTO> getRecommendedFoodItems(unsigned int count = 5);
private:
    std::vector<FoodItemDTO> foodItems;
    std::vector<FoodItemDTO> recommendedFoodItems;
    std::vector <std::pair<unsigned  int, float>> recommendationScores;

    FoodItemDAO foodItemDAO;
    
    void getFoodItems();
    void calculateRecommendationScores();
};

class SentimentAnalyzer {
public:
    SentimentAnalyzer(const std::string& filename);


    int calculateSentimentScore(const std::string& review);

private:
    std::unordered_map<std::string, int> sentimentWords;

    void loadSentimentWords(const std::string& filename);
    bool isNegationWord(const std::string& word);
};

class RecommendationScoreCalculator {
public:
    float calculateRecommendationScore(unsigned int foodId);

private:

    FoodFeedbackDAO foodFeedbackDAO;
    RolloutMenuDAO rolloutMenuDAO;
    RolloutVotingDAO rolloutVotingDAO;
    MealMenuDAO mealMenuDAO;

    float avgTasteRating;
    float avgQualityRating;
    float avgVoteCount;
    float totalRollout;
    float totalMealCount;
    float sentimentScore;

    float getAverageTasteRating(unsigned int foodId);
    float getAverageQualityRating(unsigned int foodId);
    float getVoteCount(unsigned int foodId);
    float getRolloutCount(unsigned int foodId);
    float getMealMenuCount(unsigned int foodId);
    float getSentimentScore(unsigned int foodId);

}; 