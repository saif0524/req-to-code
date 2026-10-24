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
void displayResults(const std::vector<std::pair<std::string, std::string>>& results);

std::vector<std::pair<std::string, std::string>> searchDatabase(const std::string& query) {
  std::vector<std::pair<std::string, std::string>> results;
  std::vector<std::pair<std::string, std::string>> database = { // Example database entries
    {"username1", "password1"},
    {"username2", "password2"},
    {"username3", "password3"}
  };
  // Process the query to handle special characters and prepare it for searching
  std::string processedQuery = processQuery(query);
  // Filter the database entries to include only those that contain the processed query string
  for (const auto& entry : database) {
    if (entry.first.find(processedQuery) != std::string::npos || entry.second.find(processedQuery) != std::string::npos) {
      results.push_back(entry);
    }
  }
  // Display the search results to the user
  displayResults(results);
  return results;
}

std::vector<std::pair<std::string, std::string>> filterEntries(const std::vector<std::pair<std::string, std::string>>& entries, const std::string& query) {
  std::vector<std::pair<std::string, std::string>> results;
  // Process the query to handle special characters and prepare it for searching
  std::string processedQuery = processQuery(query);
  // Filter the database entries to include only those that contain the processed query string
  for (const auto& entry : entries) {
    if (entry.first.find(processedQuery) != std::string::npos || entry.second.find(processedQuery) != std::string::npos) {
      results.push_back(entry);
    }
  }
  // Display the search results to the user
  displayResults(results);
  return results;
}

std::string processQuery(const std::string& query) {
  std::string processedQuery = query;
  std::unordered_map<char, char> escapeMap = {{'\', '\'}, {'%', '\

void displayResults(const std::vector<std::pair<std::string, std::string>>& results) {
  for (const auto& entry : results) {
    std::cout << "Username: " << entry.first << ", Password: " << entry.second << std::endl;
  }
}

