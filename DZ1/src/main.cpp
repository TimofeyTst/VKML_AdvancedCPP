#include <iostream>
#include <string>
#include "../include/struct.h"


int main(int argc, char* argv[]){
    if (argc > 3){
        std::string areaFileName = std::string(argv[1]);
        std::string artistFileName = std::string(argv[2]);
        std::string searchName = argv[3];
        for (int i = 4; i < argc; ++i) {
            searchName += " " + std::string(argv[i]);
        }
        
        std::string areaId = getAreaIdFromName(searchName, areaFileName);
        if (!areaId.empty()) {
            std::cout << "Input: " << searchName << ", Id = " << areaId << std::endl;
            std::cout << "Groups from this place = " << countArtistsFromArea(areaId, artistFileName) << std::endl;
        } else {
            std::cout << "Id of place \"" << searchName << "\" not found" << std::endl;
        }
    } else {
        if (argc == 1) {
            std::cout << "Files with areas, artists and place name weren`t specified" << std::endl;
        }
        std::cout << "Place name wasn`t specified" << std::endl;
    }
    return 0;
}