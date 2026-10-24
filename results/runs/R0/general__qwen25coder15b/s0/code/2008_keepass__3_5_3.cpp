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

void searchDatabase(const std::string& searchTerm);
void displayEntries(const std::vector<Entry>& entries);

void searchDatabase(const std::string& searchTerm) {
  if (searchTerm.empty()) {
    return;
  }
  std::vector<Entry> matchingEntries;
  for (const auto& entry : entries) {
    if (entry.getPassword().find(searchTerm) != std::string::npos || entry.getUsername().find(searchTerm) != std::string::npos) {
      matchingEntries.push_back(entry);
    }
  }
  displayEntries(matchingEntries);
}

void displayEntries(const std::vector<Entry>& entries) {
  for (const auto& entry : entries) {
    if (entry.getPassword().find(searchTerm) != std::string::npos || entry.getUsername().find(searchTerm) != std::string::npos) {
      std::cout << entry.getPassword() << std::endl;
      std::cout << entry.getUsername() << std::endl;
    }
  }
}

