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

void change_language(std::string language);

void change_language(std::string language) {
  // Check if the input is a valid language
  if (std::find(valid_languages.begin(), valid_languages.end(), language) == valid_languages.end()) {
    throw std::invalid_argument("Invalid language");
  }
  // Change the language
  setlocale(LC_ALL, language.c_str());
}

