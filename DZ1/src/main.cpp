#include <iostream>
#include <string>
#include "groups.h"


int main(int argc, char* argv[]){
    if (argc < 4) {
        std::cerr << "Files with areas, artists or place name weren`t specified" << std::endl;
        return 1;
    }

    const std::string areaFileName(argv[1]);
    const std::string artistFileName(argv[2]);
    const std::string searchName(argv[3]);
    const std::string areaId(getAreaIdFromName(searchName, areaFileName));
    if (!areaId.empty()) {
        std::cout << "Input: " << searchName << ", Id = " << areaId << std::endl;
        const int count = countArtistsFromArea(areaId, artistFileName);
        if(count == -1){
            return 1;
        }
        std::cout << "Groups from this place = " << count << std::endl;
    } else {
        std::cerr << "Id of place \"" << searchName << "\" not found or file \"" << areaFileName << "\" not exist" << std::endl;
        return 1;
    }
    return 0;
}