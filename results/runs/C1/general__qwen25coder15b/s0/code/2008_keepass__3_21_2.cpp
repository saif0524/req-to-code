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

void updateEntry(const std::string& entryId, const std::string& newTitle, const std::string& newUsername, const std::string& newUrl);
bool checkTan(const std::string& entryId, const std::string& tan);
void expireTan(const std::string& entryId);
std::string generateTan(const std::string& entryId);

void updateEntry(const std::string& entryId, const std::string& newTitle, const std::string& newUsername, const std::string& newUrl) {
  if (!checkTan(entryId, tan)) {
    return "Invalid TAN";
  }
  if (!expireTan(entryId)) {
    return "TAN expired";
  }
  // Update the entry in the database
  // ...
}

bool updateEntry(const std::string& entryId, const std::string& newTitle, const std::string& newUsername, const std::string& newUrl) {
  if (!checkTan(entryId, tan)) {
    return "Invalid TAN";
  }
  if (!expireTan(entryId)) {
    return "TAN expired";
  }
  // Update the entry in the database
  // ...
}
bool checkTan(const std::string& entryId, const std::string& tan) {
  if (!expireTan(entryId)) {
    return "TAN expired";
  }
  // Check if the TAN is valid by comparing it with the TAN stored in the database for that entry
  // ...
  return "Valid TAN";
}

void expireTan(const std::string& entryId) {
  if (!checkTan(entryId, tan)) {
    return "Invalid TAN";
  }
  // Update the entry in the database with a new TAN that is invalid
  // ...
  return "TAN expired";
}

std::string generateTan(const std::string& entryId) {
  // Generate a secure random number
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(100000, 999999);

  // Generate a new TAN
  std::string tan = std::to_string(dis(gen));

  // Store the new TAN in the database
  // ...

  // Return the new TAN
  return tan;
}

