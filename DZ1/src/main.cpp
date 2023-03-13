#include <iostream>
#include <string>
#include "../include/struct.h"

using namespace std;


int main(int argc, char* argv[]){

    std::string search_name = argv[1];
    for (int i = 2; i < argc; ++i) {
        search_name += " " + std::string(argv[i]);
    }

    std::string area_id = getAreaIdFromName(search_name);
    if (area_id != "") {
        std::cout << "Input: " << search_name << ", Id = " << area_id << std::endl;
        std::cout << "Groups from this place = " << countArtistsFromArea(area_id) << std::endl;
    } else {
        std::cout << "Id of place \"" << search_name << "\" not found" << std::endl;
    };
    return 0;
}
