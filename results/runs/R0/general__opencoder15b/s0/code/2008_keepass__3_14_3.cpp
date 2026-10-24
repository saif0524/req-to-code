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

void changeLanguage(const std::string& languageCode);
std::vector<std::string> getAvailableLanguages();
std::string getSelectedLanguage();
void setSelectedLanguage(const std::string& languageCode);

void changeLanguage(const std::string& languageCode) {
  // Implementation of changeLanguage function
}

std::vector<std::string> getAvailableLanguages() { 
  std::vector<std::string> availableLanguages; 
  for (const auto& locale : availableLocales) { 
    std::string languageCode = locale.substr(0, locale.find('_')); 
    availableLanguages.push_back(languageCode); 
  } 
  return availableLanguages; 
}

std::string getSelectedLanguage() { 
   return selectedLanguage; 
}

void setSelectedLanguage(const std::string& languageCode) { 
    if (std::find(getAvailableLanguages().begin(), getAvailableLanguages().end(), languageCode) != getAvailableLanguages().end()) { 
        selectedLanguage = languageCode; 
    } else { 
        throw std::invalid_argument("Invalid language code"); 
    } 
}

