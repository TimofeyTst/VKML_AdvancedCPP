#pragma once
#include <string>

// Вычисление id места, введенного из строки
std::string getAreaIdFromName(const std::string& name);

// Если тип артиста относится к группе и его area по совпадает
// с areid, то true, иначе false
bool isArtistFromArea(const std::string& artist, const std::string& areaId);


// Подсчет артистов, пренадлежащих группе из определенного места
// Вместо string artists должен быть массив артистов
size_t countArtistsFromArea(const std::string& areaId);
