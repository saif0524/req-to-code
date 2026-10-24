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

std::vector<std::string> getAvailableLanguages();
void displayLanguageSelectionMenu(const std::vector<std::string>& availableLanguages);
void handleLanguageSelection(const std::vector<std::string>& availableLanguages, std::string selectedLanguage);
void downloadLanguagePack(const std::string& selectedLanguage);
void getMoreLanguages();

std::vector<std::string> getAvailableLanguages() {
  return {"Arabic", "Brazilian", "Bulgarian", "Catalan", "Chinese (Simplified)", "Chinese (Traditional)", "Czech", "Danish", "Dutch", "English", "Estonian", "Finnish", "French", "Galician", "German", "Greek", "Hebrew", "Hungarian", "Italian", "Japanese", "Korean", "Lithuanian", "Macedonian", "Malay", "Norwegian", "Polish", "Portuguese", "Romanian", "Russian", "Serbian", "Slovak", "Spanish", "Swedish", "Turkish", "Ukrainian"};
}

void displayLanguageSelectionMenu(const std::vector<std::string>& availableLanguages) {
  for (const auto& language : availableLanguages) {
    std::cout << language << std::endl;
  }
}

void handleLanguageSelection(const std::vector<std::string>& availableLanguages, std::string selectedLanguage) {
  if (std::find(availableLanguages.begin(), availableLanguages.end(), selectedLanguage) != availableLanguages.end()) {
    std::cout << "Language 

void downloadLanguagePack(const std::string& selectedLanguage) {
  if (std::find(getAvailableLanguages().begin(), getAvailableLanguages().end(), selectedLanguage) != getAvailableLanguages().end()) {
    std::cout << "Downloading language pack for "

void getMoreLanguages() {
  std::string url = "https://keepass.info/download.html#languages";\nstd::system(url.c_str());\n}

