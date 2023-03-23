#include <iostream>
#include <fstream>
#include <sstream>
#include "groups.h"

const std::string GROUP_TYPE = "2";

std::string getAreaIdFromName(const std::string& name, const std::string& areaFileName){
    std::ifstream file(areaFileName);
    
    if (!file.is_open()) {
        std::cerr << "File '" << areaFileName << "' not found in directory 'static'\n";
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line); 
        std::string areaId;
        std::string areaGid;
        std::string areaName;
        std::getline(iss, areaId, '\t');
        std::getline(iss, areaGid, '\t');
        std::getline(iss, areaName, '\t');
        if (areaName == name){
            return areaId; 
        }
    }
    return "";
}

// Если тип артиста относится к группе и его areaId совпадает
// с переданным areaId, то true, иначе false
bool isArtistFromArea(const std::string& artist, const std::string& areaId){
    std::istringstream iss(artist); 
    std::string temp;
    std::string artistType;
    std::string artistArea;
    // пропускаем первые 9 элементов, так как они содержат поля,
    // не представляющее для нас интереса: id; gid; name; sort_name; 
    // begin_date_year; begin_date_month; begin_date_day; 
    // end_date_year; end_date_month; end_date_day;
    for (size_t i = 0; i < 10; i++) {
        std::getline(iss, temp, '\t');
    }
    // считываем 10-й элемент
    std::getline(iss, artistType, '\t');
    // считываем 11-й элемент
    std::getline(iss, artistArea, '\t');

    return (artistType == GROUP_TYPE && artistArea == areaId);
}


int countArtistsFromArea(const std::string& areaId, const std::string& artistFileName){
    std::ifstream file(artistFileName);

    if (!file.is_open()) {
        std::cerr << "File '" << artistFileName << "' not found in directory 'static'\n";
        return -1;
    }

    std::string artist;
    size_t count = 0;
    while (std::getline(file, artist)) {
        if (isArtistFromArea(artist, areaId)) {
            count++;
        }
    }
    return count;
}