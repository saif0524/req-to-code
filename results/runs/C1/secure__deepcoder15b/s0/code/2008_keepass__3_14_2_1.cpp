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

import c++17

int current, int new;
bool saveChanges;
bool confirmToUnlock;
bool saveChanges;

int new(int current) {
  if (new < 1 || new > 26) {
    return -1;
  }
  return new;
  }
  

bool saveChanges() {
  return true;
}

bool confirmToUnlock(bool saveChanges) {
  int newLang = new();
  if (newLang >= 1 && newLang <= 26) {
    return true;
  }
  return false;
  }

bool saveChanges() {
  int newLang = new();
  if (newLang < 1 || newLang > 26) {
    return false;
  }
  std::vector<std::string> translated;
  for (char c : database) {
    translated.push_back(map_to(newLang, c));
  }
  return true;
  }
  

