#pragma once
#include <string>

// Вычисление id места с именем name в файле с именем fileName
std::string getAreaIdFromName(const std::string& name, const std::string& fileName = "area");

// Если тип артиста относится к группе и его areaId совпадает
// с переданным areaId, то true, иначе false
bool isArtistFromArea(const std::string& artist, const std::string& areaId);


// Подсчет артистов, пренадлежащих группе из определенного места. 
// Поиск в файле с именем fileName
size_t countArtistsFromArea(const std::string& areaId, const std::string& fileName = "artist");