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

struct Entry; void displayEntries(const std::vector<Entry>& entries);
struct Entry { std::string username; std::string password; };

void searchDatabase(const std::string& searchTerm);
void displayEntries(const std::vector<Entry>& entries);

void searchDatabase(const std::string& searchTerm) {
  if (searchTerm.empty()) {
    return;
  }
  std::vector<Entry> matchingEntries;
  for (const auto& entry : entries) {
    if (entry.username.find(searchTerm) != std::string::npos || entry.password.find(searchTerm) != std::string::npos) {
      matchingEntries.push_back(entry);
    }
  }
  displayEntries(matchingEntries);
}

void displayEntries(const std::vector<Entry>& entries) { for (const auto& entry : entries) { if (entry.username.find(searchTerm) != std::string::npos || entry.password.find(searchTerm) != std::string::npos) { displayEntry(entry); } } }

