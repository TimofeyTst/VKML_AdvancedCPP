#pragma once
#include <string>
#include <vector>


struct Artist {
    int id;
    std::string gid;
    std::string name;
    std::string sort_name;
    std::string begin_date_year;
    std::string begin_date_month;
    std::string begin_date_day;
    std::string end_date_year;
    std::string end_date_month;
    std::string end_date_day;
    int type;
    int area;
    int gender;
    std::string comment;
    std::string edits_pending;
    std::string last_updated;
    std::string ended;
};

struct Artist_type {
    int id;
    std::string name;
    std::string parent;
    std::string child_order;
    std::string description;
    std::string gid;

};

struct Area {
    std::string id;
    std::string gid;
    std::string name;
    std::string tmp;
    int tmp2;
    std::string date;
    std::string sixNAndLastF;
};

std::vector<std::string> split(std::string line);

// Вычисление id места, введенного из строки
std::string getAreaIdFromName(std::string name);

// Если тип артиста относится к группе и его area по совпадает
// с areid, то true, иначе false
bool isArtistFromArea(std::string artist, std::string areaId);


// Подсчет артистов, пренадлежащих группе из определенного места
// Вместо string artists должен быть массив артистов
size_t countArtistsFromArea(std::string areaId);
