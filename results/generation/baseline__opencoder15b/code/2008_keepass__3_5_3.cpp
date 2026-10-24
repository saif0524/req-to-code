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

void searchDatabase(const std::string& query, std::vector<std::string>& results);
void filterResults(const std::vector<std::string>& results, std::vector<std::string>& filteredResults);
void highlightMatches(const std::vector<std::string>& results, std::vector<std::string>& highlightedResults);
void showResults(const std::vector<std::string>& results);
void updateDatabase(const std::string& entry, const std::string& newEntry);

void searchDatabase(const std::string& query, std::vector<std::string>& results) {
  // Iterate over the database
  for (const auto& entry : database) {
    // Check if the entry contains the query string
    if (entry.find(query) != std::string::npos) {
      // If the entry contains the query string, add it to the results
      results.push_back(entry);
    }
  }
}

void filterResults(const std::vector<std::string>& results, std::vector<std::string>& filteredResults) {
  filteredResults.clear();
  for (const auto& entry : results) {
    if (entry.find(query) != std::string::npos) {
      filteredResults.push_back(entry);
    }
  }
}

void highlightMatches(const std::vector<std::string>& results, std::vector<std::string>& highlightedResults) {
  highlightedResults.clear();
  for (const auto& entry : results) {
    if (entry.find(query) != std::string::npos) {
      highlightedResults.push_back(entry);
    }
  }
}

void showResults(const std::vector<std::string>& results) {
  // Create a JSON object
  rapidjson::Document document;
  document.SetObject();
  rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

  // Add the search results to the JSON object
  for (const auto& entry : results) {
    rapidjson::Value value(entry.c_str(), entry.length(), allocator);
    document.AddMember("result", value, allocator);
  }

  // Serialize the JSON object to a string
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  document.Accept(writer);

  // Output the JSON string
  std::cout << buffer.GetString() << std::endl;
}

void updateDatabase(const std::string& entry, const std::string& newEntry) {
  // Check if the new entry already exists in the database
  for (const auto& e : database) {
    if (e == newEntry) {
      // Return a JSON object indicating that the entry already exists
      rapidjson::Document document;
      document.SetObject();
      document.AddMember("reason", "Entry already exists", document.GetAllocator());
      rapidjson::StringBuffer buffer;
      rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
      document.Accept(writer);
      std::cout << buffer.GetString() << std::endl;
      return;
    }
  }
  // Add the new entry to the database
  database.push_back(newEntry);
  // Return a JSON object indicating that the entry has been added successfully
  rapidjson::Document document;
  document.SetObject();
  document.AddMember("reason", "Entry added successfully", document.GetAllocator());
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  document.Accept(writer);
  std::cout << buffer.GetString() << std::endl;
}

