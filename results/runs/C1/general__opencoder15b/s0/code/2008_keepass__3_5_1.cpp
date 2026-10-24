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

void searchDatabase(const std::string& searchText, const std::string& searchField, const std::vector<std::string>& searchFields, const std::vector<std::string>& searchOperators, const std::vector<std::string>& searchValues, const std::vector<std::string>& searchNotes, const std::vector<std::string>& searchUrls, const std::vector<std::string>& searchGroups, const std::vector<std::string>& searchUsers, const std::vector<std::string>& searchTitles);
std::vector<std::string> filterSearchResults(const std::vector<std::string>& results, const std::vector<std::string>& searchTexts);

void searchDatabase(const std::string& searchText, const std::string& searchField, const std::vector<std::string>& searchFields, const std::vector<std::string>& searchOperators, const std::vector<std::string>& searchValues, const std::vector<std::string>& searchNotes, const std::vector<std::string>& searchUrls, const std::vector<std::string>& searchGroups, const std::vector<std::string>& searchUsers, const std::vector<std::string>& searchTitles) {
  std::vector<std::string> filteredResults;
  for (const auto& text : searchTexts) {
    auto it = std::find(results.begin(), results.end(), text);
    if (it != results.end()) {
      filteredResults.push_back(*it);
    }
  }
}

std::vector<std::string> filterSearchResults(const std::vector<std::string>& results, const std::vector<std::string>& searchTexts) {
  std::vector<std::string> filteredResults;
  for (const auto& text : searchTexts) {
    auto it = std::find(results.begin(), results.end(), text);
    if (it != results.end()) {
      filteredResults.push_back(*it);
    }
  }
  return filteredResults;
}

std::vector<std::string> filterSearchResults(const std::vector<std::string>& results, const std::vector<std::string>& searchTexts) {
  std::vector<std::string> filteredResults;
  for (const auto& text : searchTexts) {
    auto it = std::find(results.begin(), results.end(), text);
    if (it != results.end()) {
      filteredResults.push_back(*it);
    }
  }
  return filteredResults;
}

