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

{\nvector<int> _availableLanguages;}

int get_currentLanguage();
void addLanguage(int newLanguage);
vector<int> get_availableLanguages();
void deleteLanguage(int language);

int get_currentLanguage() {
    return 3;
  }

vector<int> addLanguage(int newLanguage) {
  vector<int> temp = {newLanguage};
  _availableLanguages = temp;
  return temp;
  }

vector<int> get_availableLanguages() {
  return _availableLanguages; }

vector<int> deleteLanguage(int language) { vector<int> temp = _availableLanguages; temp.erase(temp.begin() + language); _availableLanguages = temp; return temp; }

