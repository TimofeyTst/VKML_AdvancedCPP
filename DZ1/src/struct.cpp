#include "../include/struct.h"
#include <iostream>
#include <fstream>
#include <sstream>


std::string getAreaIdFromName(const std::string& name, const std::string& fileName){
    std::ifstream file("static/" + fileName);
    std::string line;
    
    if (file.is_open()){
    while (std::getline(file, line)) {
            std::istringstream iss(line); 
            std::string areaId, areaGid, areaName;
            std::getline(iss, areaId, '\t');
            std::getline(iss, areaGid, '\t');
            std::getline(iss, areaName, '\t');
            if (areaName == name){
                return areaId; 
            };
        };
        file.close();
    } else {
        std::cout << "File '" << fileName << " not found in directory 'static'\n";
    };
    return "";
};


bool isArtistFromArea(const std::string& artist, const std::string& areaId){
    std::istringstream iss(artist); 
    std::string temp, artistType, artistArea;
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

    if (artistType == "2" && artistArea == (areaId)){
        return true;
    } else {
        return false;
    }
};


size_t countArtistsFromArea(const std::string& areaId, const std::string& fileName){
    std::ifstream file("static/" + fileName);
    std::string artist;
    size_t count = 0;
    if (file.is_open()){
        while (std::getline(file, artist)) {
            if (isArtistFromArea(artist, areaId)) count++;
        };
        file.close();
        return count;
    } else {
        std::cout << "File '" << fileName << " not found in directory 'static'\n";
        return 0;
    };
};