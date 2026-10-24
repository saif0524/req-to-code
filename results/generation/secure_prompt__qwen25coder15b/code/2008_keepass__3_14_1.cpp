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

void selectLanguage(const std::string& languageCode);
void downloadLanguage(const std::string& languageCode);
void getMoreLanguages(const std::string& languageCode);

void selectLanguage(const std::string& languageCode) {
  if (!KeePass::selectLanguage(languageCode)) {
    return;
  }
  if (!KeePass::downloadLanguage(languageCode)) {
    return;
  }
  if (!KeePass::getMoreLanguages(languageCode)) {
    return;
  }
}

void downloadLanguage(const std::string& languageCode) {
  if (!KeePass::selectLanguage(languageCode)) {
    return;
  }
  if (!KeePass::downloadLanguage(languageCode)) {
    return;
  }
  if (!KeePass::getMoreLanguages(languageCode)) {
    return;
  }
}

void getMoreLanguages(const std::string& languageCode) {
  if (!KeePass::selectLanguage(languageCode)) {
    return;
  }
  if (!KeePass::downloadLanguage(languageCode)) {
    return;
  }
  if (!KeePass::getMoreLanguages(languageCode)) {
    return;
  }
}

