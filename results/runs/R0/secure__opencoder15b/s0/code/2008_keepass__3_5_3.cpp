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

void searchDatabase(const std::string& query, std::vector<std::string>& results) {
  // Iterate over the database entries
  for (const auto& entry : database) {
    // Check if the entry contains the query
    if (entry.find(query) != std::string::npos) {
      // If the entry matches the query, add it to the results
      results.push_back(entry);
    }
  }
}

