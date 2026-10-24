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

struct Entry; using SelectedEntry = Entry; SelectedEntry selectedEntry;

void selectEntry(const Entry& entry);
void changePassword(const std::string& newPassword, const std::string& repeatPassword);

void selectEntry(const Entry& entry) {
  selectedEntry = entry;
}

void changePassword(const std::string& newPassword, const std::string& repeatPassword) {
  // Check if the newPassword and repeatPassword are identical
  if (newPassword != repeatPassword) {
    return "Error: Passwords do not match";
  }

  // Check if the newPassword is not empty and contains at least one character
  if (newPassword.empty() || newPassword.length() < 1) {
    return "Error: Password is empty";
  }

  // Select the entry for viewing or modification
  selectEntry(selectedEntry);

  // Change the password of the selected entry
  selectedEntry.setPassword(newPassword);
}

