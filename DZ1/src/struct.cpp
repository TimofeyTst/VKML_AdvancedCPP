#include "../include/struct.h"
#include <iostream>
#include <fstream>
#include <sstream>


std::string getAreaIdFromName(const std::string& name){
    std::ifstream file("static/area");
    std::string line;
    
    if (file.is_open()){
    while (std::getline(file, line)) {
            std::istringstream iss(line); 
            std::string area_id, area_gid, area_name;
            std::getline(iss, area_id, '\t');
            std::getline(iss, area_gid, '\t');
            std::getline(iss, area_name, '\t');

            
            if (area_name == name){
                return area_id; 
            };
        };
        file.close();
    } else {
        std::cout << "File not found\n";
    };
    return "";
};


bool isArtistFromArea(const std::string& artist, const std::string& areaId){
    std::istringstream iss(artist); 
    std::string temp, artist_type, artist_area;
    // пропускаем первые 9 элементов
    for (size_t i = 0; i < 10; i++) {
        std::getline(iss, temp, '\t');
    }
    // считываем 10-й элемент
    std::getline(iss, artist_type, '\t');
    // считываем 11-й элемент
    std::getline(iss, artist_area, '\t');

    if (artist_type == "2" && artist_area == (areaId)){
        return true;
    } else {
        return false;
    }
};


size_t countArtistsFromArea(const std::string& areaId){
    std::ifstream file("static/artist");
    std::string artist;
    size_t count = 0;
    if (file.is_open()){
        while (std::getline(file, artist)) {
            if (isArtistFromArea(artist, areaId)) count++;
        };
        file.close();
        return count;
    } else {
        std::cout << "File not found\n";
        return 0;
    };
};