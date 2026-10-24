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

std::string
{\n#include <vector>\n}

char input, returns vector<db_entry> where each db_entry contains at least one character from input;
string username, returns vector<db_entry> where db_entry.username == username;
string group_name, returns vector<db_entry> where db_entry.group_name == group_name;
string password, returns vector<db_entry> where db_entry.password == password;
string url, returns vector<db_entry> where db_entry.url == url;

vector<db_entry> searchChar(char input, vector<db_entry> entries) {
vector<db_entry> result;
for (const auto& db_entry : entries) {
bool hasChar = false;
for (char c : db_entry) {
if (c == input) {
hasChar = true;
break;
}
}
if (hasChar) {
result.push_back(db_entry);
}
}
return result;
}

vector<db_entry> username(string username) {
    vector<db_entry> result;
    for (const auto& db_entry : entries) {
      if (db_entry->username == username) {
        result.push_back(db_entry);
      }
    }
    return result;
    }
    

vector<db_entry> group_name(string group_name) { vector<db_entry> result; for (char c : group_name) { for (const auto& db_entry : entries) { if (db_entry->group_name == c) { result.push_back(db_entry); } } } return result; }

vector<db_entry> password(string password) {
vector<db_entry> result;
for (const auto& db_entry : entries) {
if (db_entry->password == password) {
result.push_back(db_entry);
}
}
return result;
}

vector<db_entry> url(string url) {
  vector<db_entry> result;
  for (const auto& db_entry : entries) {
    if (db_entry->url == url) {
      result.push_back(db_entry);
    }
  }
  return result;
}

