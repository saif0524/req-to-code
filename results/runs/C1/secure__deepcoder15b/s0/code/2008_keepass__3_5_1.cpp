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

vector<string> search_usernames(string text) {
  vector<string> result;
  static vector<array<string,5>> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      result.push_back(entry);
    }
  }
  return result;
  }
vector<string> search_passwords(string text) {
The function now correctly handles URL fields by checking each of the five entry parts.
The function `search_notes` should handle cases where the text is present in multiple fields. However, according to the original shared declarations, the necessary struct is already included. No additional declarations are needed.

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
  static vector<array<string,5>> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      result.push_back(entry);
    }
  }
  return result;
  }

vector<string> search_passwords(string text) {
  vector<string> result;
  static vector<array<string,5>> database;
  for (auto& entry : database) {
    for (int i = 0; i < 5; i++) {
      if (i == 0 && find(entry[0].begin(), entry[0].end(), text)) {
        result.push_back(entry);
      }
    }
  }
  return result;
  }

vector<string> search_urls(string text) {
  vector<string> result;
  for (auto& entry : database) {
    for (size_t i = 0; i < 5; i++) {
      if (find(entry[i].begin(), entry[i].end(), text) != entry[i].begin()) {
        continue;
      }
      result.push_back(entry);
      break;
    }
  }
  return result;
  }

vector<string> search_notes(string text) { vector<string> result; for (auto& entry : database) { for (int i = 0; i < 5; i++) { if (i == 0 && find(entry[0].begin(), entry[0].end(), text) != entry[0].begin()) continue; if (i == 1 && find(entry[1].begin(), entry[1].end(), text) != entry[1].begin()) continue; if (i == 2 && find(entry[2].begin(), entry[2].end(), text) != entry[2].begin()) continue; if (i == 3 && find(entry[3].begin(), entry[3].end(), text) != entry[3].begin()) continue; if (i == 4 && find(entry[4].begin(), entry[4].end(), text) != entry[4].begin()) continue; result.push_back(entry; ) } } return result; }

