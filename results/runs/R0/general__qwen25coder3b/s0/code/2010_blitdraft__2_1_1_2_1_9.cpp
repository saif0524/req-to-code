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

bool searchUser(const std::string& displayName, const std::string& userName, const std::vector<User>& users);
bool verifyUserExistence(const std::string& userId);

bool searchUser(const std::string& displayName, const std::string& userName, const std::vector<User>& users) {
  for (const auto& user : users) {
    if (user.displayName == displayName && user.userName == userName) {
      return true;
    }
  }
  return false;
}

bool verifyUserExistence(const std::string& userId) {
  for (const auto& user : users) {
    if (user.id == userId) {
      return true;
    }
  }
  return false;
}

