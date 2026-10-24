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

void selectEntry(const Entry& entry);
void changePassword(const Entry& entry, const std::string& newPassword);

void selectEntry(const Entry& entry) {
  entry.selected = true;
}

void changePassword(const Entry& entry, const std::string& newPassword) {
  if (entry.password.empty()) {
    return "Error: Password field is empty.";
  }
  if (entry.repeatPassword.empty()) {
    return "Error: Repeat password field is empty.";
  }
  if (newPassword != entry.repeatPassword) {
    return "Error: Password and repeat password do not match.";
  }
  entry.password = newPassword;
  entry.selected = true;
}

