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

\string#include <string>\string#include <vector>
std::vector<std::db_entry> is already included in the shared declarations. We need to define a new struct std::db_entry with an integer password.

char input, returns vector<db_entry> where each db_entry contains at least one character from input;
string username, returns vector<db_entry> where db_entry.username == username;
string group_name, returns vector<db_entry> where db_entry.group_name == group_name;
string password, returns vector<db_entry> where db_entry.password == password;
string url, returns vector<db_entry> where db_entry.url == url;

vector<db_entry> searchChar(char input) {
    vector<db_entry> result;
    for (const auto& db_entry : entries) {
        bool contains = false;
        for (char c : db_entry) {
            if (c == input) {
                contains = true;
                break;
            }
        }
        if (contains) {
            result.push_back(db_entry);
        }
    }
    return result;
}

vector<db_entry> search_for_username(string target_username) {
vector<db_entry> result;
for (const auto& entry : entries) {
if (entry->username == target_username) {
result.push_back(entry);
}
}
return result;
}

vector<db_entry> group_name(string group_name) { vector<db_entry> result; for (char c : group_name) { for (const auto& db_entry : entries) { if (db_entry->group_name == c) { result.push_back(db_entry); } } } return result; }

vector<db_entry> password(string password) { vector<db_entry> result; for (const auto& db_entry : entries) { if (db_entry.password == password) { result.push_back(db_entry); } } return result; }

vector<db_entry> url(string url) {
  vector<db_entry> result;
  for (const auto& db_entry : entries) {
    if (db_entry->url == url) {
      result.push_back(db_entry);
    }
  }
  return result;
}

