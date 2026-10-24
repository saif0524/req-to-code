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

static std::vector<Entry> database;

void createTanEntry(std::string& title, std::string& username, std::string& url, std::string& notes, std::string& tan);
void updateTanExpiration(std::string& tan);
bool validateTan(const std::string& tan);
void addTanToDatabase(const std::string& tan);
void displayTanEntry(const std::string& tan);

void createTanEntry(std::string& title, std::string& username, std::string& url, std::string& notes, std::string& tan) {
  // Check if the TAN is valid
  if (!validateTan(tan)) {
    throw std::invalid_argument("TAN is invalid");
  }

  // Add the TAN to the database
  addTanToDatabase(tan);

  // Set the entry's details
  title = "TAN";
  username = "TAN User";
  url = "TAN URL";
  notes = "TAN Notes";

  // Set the expiration time to the current time
  updateTanExpiration(tan);
}

void updateTanExpiration(std::string& tan) {
  // Find the TAN entry in the database
  auto it = std::find_if(database.begin(), database.end(), [&tan](const Entry& entry) {
    return entry.tan == tan;
  });

  // If the TAN entry is found, update its expiration time
  if (it != database.end()) {
    it->expiration = std::chrono::system_clock::now();
  }
}

bool validateTan(const std::string& tan) {
  // Find the TAN entry in the database
  auto it = std::find_if(database.begin(), database.end(), [&tan](const Entry& entry) {
    return entry.tan == tan;
  });

  // If the TAN entry is found, the TAN is invalid
  return it != database.end();
}

void addTanToDatabase(const std::string& tan) {
  static std::vector<Entry> database;

  // Check if the TAN is already used
  if (validateTan(tan)) {
    throw std::invalid_argument("TAN is already used");
  }

  // Add the TAN to the database
  database.push_back(tan);
}

class KeePass {
public:
  static std::vector<Entry> database;

  void displayTanEntry(const std::string& tan) {
    // Find the TAN entry in the database
    auto it = std::find_if(database.begin(), database.end(), [&tan](const Entry& entry) {
      return entry.tan == tan;
    });

    // If the TAN entry is found, display its details
    if (it != database.end()) {
      std::cout << R"(\n{\n"title": "

