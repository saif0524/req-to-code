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

using namespace std; #include <c++17> #include <iostream> int current, int new; bool saveChanges, bool confirmToUnlock
{ }

int current, int new;
bool saveChanges;
bool confirmToUnlock;
bool saveChanges;

bool nextLanguage(int current) {
  if (current < 1 || current > 26) {
    return false;
  }
  return current;
  }

bool saveChanges() {
  bool validLanguage = 1 <= current <= 26;
  bool databaseTranslation = (newLang >= 1 && newLang <= 26);
  bool translated = true;
  if (databaseTranslation) {
    translated = false;
  }
  return validLanguage && translated;
}

bool confirmToUnlock(int saveChanges) {
  if (saveChanges) {
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

