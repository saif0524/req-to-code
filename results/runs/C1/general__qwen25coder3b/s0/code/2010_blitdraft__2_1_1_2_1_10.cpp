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

std::optional<std::string> searchActiveDirectory(const std::string& username);
bool validateUserStatus(const std::optional<std::string>& status);
bool createUser(const std::string& username, const std::string& status);

std::optional<std::string> searchActiveDirectory(const std::string& username) {
  // Placeholder for Active Directory search logic
  // This could involve using a library like ADL (Active Directory Library) or a similar API
  // For demonstration, let's assume it returns 'Active' or 'Inactive'
  if (username == 'user1') {
    return 'Active';
  } else if (username == 'user2') {
    return 'Inactive';
  } else {
    return std::nullopt;
  }
}

bool validateUserStatus(const std::optional<std::string>& status) {
  if (!status) {
    return false; // User status not found
  }
  if (*status == 'Active' || *status == 'Inactive') {
    return true;
  }
  return false;
}

bool createUser(const std::string& username, const std::string& status) {
  auto statusResult = searchActiveDirectory(username);
  if (!statusResult) {
    return false; // User not found in Active Directory
  }
  if (!validateUserStatus(statusResult)) {
    return false; // Invalid user status
  }
  // User creation logic here
  return true; // User created successfully
}

