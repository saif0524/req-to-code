#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

vector<Record> database;

bool check_duplicate_id(int id);
bool check_duplicate_name(std::string name);
bool check_duplicate_salesman_name(std::string name);
bool check_duplicate_team_name(std::string name);
bool check_duplicate_name_salesman(std::string name);

bool check_duplicate_id(int id) {
     for (const auto& record : database) {
         if (record.id == id) {
             return false;
         }
     }
     return true;
}

bool check_duplicate_name(std::string name) {
     for (const auto& record : database) {
         if (record.name == name) {
             return false;
         }
     }
     return true;
}

bool check_duplicate_salesman_name(int id) {
     for (const auto& record : database) {
         if (record.id == id) {
             return false;
         }
     }
     return true;
}

bool check_duplicate_salesman_name(std::string name) {
     for (const auto& record : database) {
         if (record.name == name) {
             return false;
         }
     }
     return true;
}

bool check_duplicate_name_salesman(std::string name) {
     for (const auto& record : database) {
         if (record.name == name) {
             return false;
         }
     }
     return true;
}

