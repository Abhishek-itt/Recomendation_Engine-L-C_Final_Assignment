enum class ClientRequestType {
    FETCH,
    CREATE,
    UPDATE,
    DELETE,
};

enum class TargetTable{
    NOT_APPLICABLE = 0,
    USERS,
    FOOD_ITEMS,
    FOOD_FEEDBACK,
    DAILY_ROLLOUT,
    DAILY_MENU,
    DAILY_MENU_RESPONSE,
    ROLLOUT_VOTING
};

