#include <iostream>
#include <string>
#include "../include/struct.h"

using namespace std;


int main(int argc, char* argv[]){
    if (argc > 1){
        string search_name = argv[1];
        for (int i = 2; i < argc; ++i) {
            search_name += " " + string(argv[i]);
        }

        string area_id = getAreaIdFromName(search_name);
        if (!area_id.empty()) {
            cout << "Input: " << search_name << ", Id = " << area_id << endl;
            cout << "Groups from this place = " << countArtistsFromArea(area_id) << endl;
        } else {
            cout << "Id of place \"" << search_name << "\" not found" << endl;
        };
    } else {
        cout << "Place name wasn`t specified" << endl;
    }
    return 0;
}
