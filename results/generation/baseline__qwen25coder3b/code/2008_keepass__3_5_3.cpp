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

std::vector<std::pair<std::string, std::string>> searchDatabase(const std::string& query);
std::vector<std::pair<std::string, std::string>> filterEntries(const std::vector<std::pair<std::string, std::string>>& entries, const std::string& query);
std::string processQuery(const std::string& query);
void displayEntries(const std::vector<std::pair<std::string, std::string>>& entries);

std::vector<std::pair<std::string, std::string>> searchDatabase(const std::string& query) {
  return filterEntries(database, query);
}

std::vector<std::pair<std::string, std::string>> filterEntries(const std::vector<std::pair<std::string, std::string>>& entries, const std::string& query) {
  std::vector<std::pair<std::string, std::string>> result;
  for (const auto& entry : entries) {
    if (entry.first.find(query) != std::string::npos || entry.second.find(query) != std::string::npos) {
      result.push_back(entry);
    }
  }
  return result;
}

std::string processQuery(const std::string& query) {
  std::string processedQuery = query;
  std::replace(processedQuery.begin(), processedQuery.end(), ' ', '_');
  std::transform(processedQuery.begin(), processedQuery.end(), processedQuery.begin(), ::tolower);
  return processedQuery;
}

void displayEntries(const std::vector<std::pair<std::string, std::string>>& entries) {
  for (const auto& entry : entries) {
    std::cout << entry.first << " : " << entry.second << std::endl;
  }
}

