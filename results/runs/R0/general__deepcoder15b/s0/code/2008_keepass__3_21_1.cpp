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

std::pair<std::tuple<std::string, std::string>, std::string> create_tan_entry(std::string username, std::string password, int expiration);
bool remove_tan_entry_from_db(std::shared_tan_db_t& db, std::string id);
void set_tan_entry_expiration(std::shared_tan_db_t& db, std::string id);

std::pair<std::tuple<std::string, std::string>, std::string> create_tan_entry(std::string username, std::string password, int expiration) {
    auto t = std::make_tuple(username, password);
    return std::make_pair(t, expiration);
    }

bool remove_tan_entry_from_db(std::shared_tan_db_t& db, std::string id) {
    for (auto& entry : db) {
        if (entry.first == std::make_tuple(std::string id)) {
            // Remove this entry from the database
            return true;
        }
    }
    return false;
}

void set_tan_entry_expiration(std::shared_tan_db_t& db, std::string id) {
    bool found = false;
    for (auto& entry : db) {
        if (entry.first == std::make_tuple(std::string id)) {
            entry.second = std::make_pair(std::string(

