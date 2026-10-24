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
\nvector<string> search_passwords(string text) {
  vector<string> result;
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      result.push_back(entry[0]);
    }
  }
  return result;
}
\n\vas search_all(std::string text) {
  return std::vector<std::array<std::string,5>>({
    search_usernames(text),
    search_passwords(text),
    search_urls(text),
    search_notes(text)
  });
}
\n\vas search_usernames(std::string text) {
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      return entry;
    }
  }
  return entry;
}
\nspace;\n\vas search_passwords(std::string text) {
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      return entry;
    }
  }
  return entry;
}
\nspace;\n\vas search_urls(std::string text) {
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      return entry;
    }
  }
  return entry;
}
\nspace;\n\vas search_notes(std::string text) {
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      return entry;
    }
  }
  return entry;
}
The shared declarations already include a vector<string> which is used in the search functions, so no additional declarations are needed.
The function now returns a vector of array<string,5> which contains the matching entries. The shared declarations include the necessary headers, so no additional declarations are needed.

std::vector<std::array<std::string, 5>> search_all(std::string text);
std::vector<std::array<std::string, 5>> search_usernames(std::string text);
std::vector<std::array<std::string, 5>> search_passwords(std::string text);
std::vector<std::array<std::string, 5>> search_urls(std::string text);
std::vector<std::array<std::string, 5>> search_notes(std::string text);

vector<string> search_all(string text) { vector<string> result; static array<string,5> database; for (auto& entry : database) { array<string,5> currentEntry; for (int i = 0; i < 5; i++) { if (find(entry[i].begin(), entry[i].end(), text) != entry[i].begin()) continue; currentEntry[i] = entry[i]; } if (!currentEntry.empty()) result.push_back(currentEntry); } return result; }

vector<string> search_usernames(string text) { static array<string,5> database; for (auto& entry : database) { if (find(entry[0].begin(), entry[0].end(), text)) { result.push_back(entry); } } return result; }

vector<array<string,5>> search_passwords(string text) {
  vector<array<string,5>> result;
  static array<string,5> database;
  for (auto& entry : database) {
    if (find(entry[0].begin(), entry[0].end(), text)) {
      array<string,5> currentEntry;
      currentEntry[0] = entry;
      result.push_back(currentEntry);
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

