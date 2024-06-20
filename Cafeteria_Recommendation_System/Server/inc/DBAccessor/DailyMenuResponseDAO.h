#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DBAccessor/MySQL/MySqlDBAccess.h"
#include "DTO/DailyMenuResponseDTO.h"

class DailyMenuResponseDAO
{
private:
    MySqlDBAccess mySqlDBAccess;

public:
    bool addDailyMenuResponse(DailyMenuResponseDTO dailyMenuResponseDTO);
    DailyMenuResponseDTO getDailyMenuResponse(unsigned int dailyMenuResponseId);
    std::vector<DailyMenuResponseDTO> getDailyMenuResponses(unsigned int dailyMenuId);
    std::vector<DailyMenuResponseDTO> getDailyMenuResponses(std::string userName);
    std::vector<DailyMenuResponseDTO> getDailyMenuResponses(unsigned int dailyMenuId, std::string userName);
};
