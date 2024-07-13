#pragma once

enum class RequestType {
    USER_LOGIN,
    ADD_USER,
    ADD_FOOD_ITEM,
    DELETE_FOOD_ITEM,
    GET_FOOD_ITEM,
    GET_FOOD_ITEMS,
    ADD_FOOD_FEEDBACK,
    GET_FEEDBACKS_FOR_FOOD,

    UPDATE_DIET_PREFERENCE,
    GET_DIET_PREFERENCE,

    GET_NOTIFICATIONS,
    SEND_READ_RECEIPT,

    GET_RECOMMENDATION_LIST,
    ROLLOUT_MEAL_MENU,
    GET_ROLLOUT_MEAL_MENU,
    GET_FOOD_ID_FOR_ROLLOUT,
    VOTE_ON_ROLLOUT_MENU,
    GET_VOTES_ON_ROLLOUT,
    ROLLOUT_MEAL,
    GET_MEAL_MENU,
    RESPONSE_ON_MEAL,
    LOGOUT,
};