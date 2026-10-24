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
std::string getEntryDetails(const std::string& entryId);
void displayResults(const std::vector<std::string>& results);

std::vector<std::string> searchDatabase(const std::string& query) {
  std::map<std::string, Entry> database;
  std::vector<std::string> results;
  // Process the query string to handle partial matches and related data
  std::string processedQuery = processQuery(query);
  // Search the database for entries containing the processed query string
  for (const auto& entry : database) {
    if (entry.contains(processedQuery)) {
      results.push_back(entry.getId());
    }
  }
  return results;
}

std::vector<std::string> filterEntries(const std::vector<std::string>& entries, const std::string& query, const std::map<std::string, Entry>& database) {
  std::vector<std::string> results;
  for (const auto& entryId : entries) {
    if (database.find(entryId) != database.end() && database[entryId].contains(query)) {
      results.push_back(entryId);
    }
  }
  return results;
}

std::string processQuery(const std::string& query) {
  std::string processedQuery;
  // Convert the query to lowercase
  for (char c : query) {
    processedQuery += std::tolower(c);
  }
  // Remove non-alphanumeric characters
  processedQuery.erase(std::remove_if(processedQuery.begin(), processedQuery.end(), [](char c) {
    return !std::isalnum(c);
  }), processedQuery.end());
  // Handle related data by searching for entries that contain words related to the query
  // This is a placeholder for the related data handling logic
  return processedQuery;
}

std::string getEntryDetails(const std::string& entryId, const std::map<std::string, Entry>& database) {
  std::string entryDetails;
  if (database.find(entryId) != database.end()) {
    const auto& entry = database[entryId];
    entryDetails = "{\"username\":\"" + entry.getUsername() + "\", \"password\":\"" + entry.getPassword() + "\", \"url\":\"" + entry.getUrl() + "\", \"notes\":\"" + entry.getNotes() + "\", \"title\":\"" + entry.getTitle() + "\"}";
  } else {
    entryDetails = "{\"reason\":\"Entry not found\"}";
  }
  return entryDetails;
}

void displayResults(const std::vector<std::string>& results) {
  std::string jsonResults;
  for (const auto& entryId : results) {
    std::string entryDetails = getEntryDetails(entryId);
    jsonResults += entryDetails + ', ';
  }
  if (!jsonResults.empty()) {
    jsonResults.pop_back(); // Remove the trailing comma
  }
  jsonResults = '[' + jsonResults + ']';
  std::cout << jsonResults << std::endl;
}

