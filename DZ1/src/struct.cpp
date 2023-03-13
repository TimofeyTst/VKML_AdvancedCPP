#include "../include/struct.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


std::vector<std::string> split(std::string line){
    std::istringstream iss(line);  // создание потока для чтения строки
    std::string word;
    std::vector<std::string> area;

    while (iss >> word) {  // чтение слов из потока
        area.push_back(word);
    }
    return area;
}


std::string getAreaIdFromName(std::string name){
    std::ifstream file("static/area");
    std::string line;
    
    if (file.is_open()){
    while (std::getline(file, line)) {
            std::istringstream iss(line); 
            Area area;
            std::getline(iss, area.id, '\t');
            std::getline(iss, area.gid, '\t');
            std::getline(iss, area.name, '\t');

            
            if (area.name == name){
                return area.id; 
            };
        };
        file.close();
    } else {
        std::cout << "File not found\n";
    };
    return "";
};


bool isArtistFromArea(std::string artist, std::string areaId){
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

size_t countArtistsFromArea(std::string areaId){
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