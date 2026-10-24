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

std::set<std::string> addWordToDatabase(std::string word);
std::bool isWordInDatabase(std::string word);
std::vector<std::string> getAllWordsInDatabase();
std::bool isWordInSet(std::string word);
std::bool removeWordFromDatabase(std::string word);

std::set<std::string> addWordToDatabase(std::string word) {
  if (std::empty<std::set<std::string>>(this)) {
    std::set<std::string> s;
    s.insert(word);
    return s;
  }
  return std::set<std::string>(this->begin(), this->end(), std::move(this));
  }
  

bool isWordIndatabase(string word) {
  if (this.empty()) {
    return false;
  }
  return this.find(word) != this.end();
  }

vector<string> getAllWordsInDatabase() { vector<string> result; set<string> temp = this; for (auto& elem : temp) { result.push_back(elem); } return result; }

bool isWordInSet(string word) {
    for (const auto& elem : this) {
        if (elem == word) {
            return true;
        }
    }
    return false;
    }

bool removeWordFromDatabase(string word) {
  if (this.empty()) {
    return false;
  }
  for (auto& elem : this) {
    if (elem == word) {
      this.erase(elem.begin() + 1, elem.end());
      return true;
    }
  }
  return false;
  },
  

