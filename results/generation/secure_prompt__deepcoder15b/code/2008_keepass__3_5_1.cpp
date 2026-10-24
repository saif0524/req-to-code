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

std::vector<std::array<std::string, 5>> search_all(std::string text);
std::vector<std::array<std::string, 5>> search_usernames(std::string text);
std::vector<std::array<std::string, 5>> search_passwords(std::string text);
std::vector<std::array<std::string, 5>> search_urls(std::string text);
std::vector<std::array<std::string, 5>> search_notes(std::string text);

std::vector<std::array<std::string, 5>> search_all(std::string text) {
  std::vector<std::array<std::string, 5>> result;
  for (auto& entry : database) {
    for (size_t i = 0; i < 5; i++) {
      if (std::find(entry[i].begin(), entry[i].end(), text) != entry[i].begin()) {
        continue;
      }
      result.push_back(entry);
      break;
    }
  }
  return result;
}

vector<string> search_usernames(string text) {
  vector<string> result;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      result.push_back(entry);
    }
  }
  return result;
}

vector<string> search_passwords(string text) {
  vector<string> result; 
  for (auto& entry : database) {
    for (size_t i = 0; i < 5; i++) {
      if (i == 2 && std::find(entry[i].begin(), entry[i].end(), text) != entry[i].begin()) {
        continue;
      }
      if (i == 0 && find(entry[0].begin(), entry[0].end(), text)) {
        result.push_back(entry);
      }
      // ... rest of the code ...
  }
  return result;
}

vector<string> search_urls(string text) {
  vector<string> result;
  for (auto& entry : database) {
    for (size_t i = 0; i < 5; i++) {
      if (find(entry[i].begin(), entry[i].end(), text) != entry[i].begin()) {
        result.push_back(entry);
        break;
      }
    }
  }
  return result;
}

vector<string> search_notes(string text) {
  vector<string> result;
for (auto& entry : database) {
if (find(entry[0].begin(), entry[0].end(), text)) {
result.push_back(entry);
}
}
return result;
}

