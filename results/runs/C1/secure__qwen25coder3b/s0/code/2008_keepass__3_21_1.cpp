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

void createTanEntry(const std::string& tan, const std::string& notes);
void updateTanExpiration(const std::string& tan);
bool validateTan(const std::string& tan);
void addTanToDatabase(const std::string& tan, const std::string& notes);
std::vector<std::string> getTanEntries();

void createTanEntry(const std::string& tan, const std::string& notes) {
  if (tan.empty()) {
    throw std::invalid_argument("TAN cannot be empty");
  }
  if (!std::all_of(tan.begin(), tan.end(), ::isalnum)) {
    throw std::invalid_argument("TAN must contain only letters and numbers");
  }
  // Add the TAN entry to the database
  // Implementation details depend on the database handling logic
}

void updateTanExpiration(const std::string& tan) {
  if (!validateTan(tan)) {
    throw std::invalid_argument("Invalid TAN");
  }
  // Update the expiration time of the TAN entry to the current time
  // Implementation details depend on the database handling logic
}

bool validateTan(const std::string& tan) {
  if (tan.empty()) {
    return false;
  }
  return std::all_of(tan.begin(), tan.end(), ::isalnum);
}

void addTanToDatabase(const std::string& tan, const std::string& notes) {
  if (!validateTan(tan)) {
    throw std::invalid_argument("Invalid TAN");
  }
  // Add the TAN entry to the database
  // Implementation details depend on the database handling logic
}

std::vector<std::string> getTanEntries() {
  std::vector<std::string> tanEntries;
  // Assuming TAN is stored in a field named 'tan'
  for (const auto& entry : database) {
    if (entry.tan != "") {
      tanEntries.push_back(entry.tan);
    }
  }
  return tanEntries;
}

