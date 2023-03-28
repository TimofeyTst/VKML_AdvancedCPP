#pragma once
#include <string>

// Вычисление id места с именем name в файле с именем fileName
std::string getAreaIdFromName(const std::string& name, const std::string& fileName = "static/area");


// Подсчет артистов, пренадлежащих группе из определенного места. 
// Поиск в файле с именем fileName
int countArtistsFromArea(const std::string& areaId, const std::string& fileName = "static/artist");