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

std::string searchActiveDirectory(const std::string& username);
bool validateUserStatus(const std::string& status);
bool createUser(const std::string& username, const std::string& status);

bool validateUserStatus(const std::string& status) {
  if (status == "Active" || status == "Inactive") {
    return true;
  }
  return false;
}

bool createUser(const std::string& username, const std::string& status) {
  std::string userStatus = searchActiveDirectory(username);
  if (!validateUserStatus(userStatus)) {
    return false;
  }
  // Placeholder for creating a new user
  return true;
}

