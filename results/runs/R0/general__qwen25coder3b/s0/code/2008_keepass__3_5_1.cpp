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

std::vector<std::string> searchDatabase(const std::string& query);
std::vector<std::string> filterEntries(const std::vector<std::string>& entries, const std::string& query);
std::string processQuery(const std::string& query);
void displayResults(const std::vector<std::string>& results);
std::vector<std::string> getDatabaseEntries();

std::vector<std::string> searchDatabase(const std::string& query) {
  std::string processedQuery = processQuery(query);
  std::vector<std::string> results = filterEntries(getDatabaseEntries(), processedQuery);
  return results;
}

std::vector<std::string> filterEntries(const std::vector<std::string>& entries, const std::string& query) {
  std::vector<std::string> results;
  for (const auto& entry : entries) {
    if (entry.find(query) != std::string::npos) {
      results.push_back(entry);
    }
  }
  return results;
}

std::string processQuery(const std::string& query) {
  std::string processedQuery;
  for (char c : query) {
    processedQuery += '*';
  }
  std::transform(processedQuery.begin(), processedQuery.end(), processedQuery.begin(), ::tolower);
  return processedQuery;
}

void displayResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

std::vector<std::string> getDatabaseEntries() { return databaseEntries; }

