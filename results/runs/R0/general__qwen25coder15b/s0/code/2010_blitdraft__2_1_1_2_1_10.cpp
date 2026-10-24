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

std::optional<User> searchActiveDirectory(const std::string& username);
void createOrUpdateUser(const User& user);
bool validateUserStatus(const User& user);
void handleUserStatusMismatch(const User& user);

std::optional<User> searchActiveDirectory(const std::string& username) {
  return searchActiveDirectory(username);
}

void createOrUpdateUser(const User& user) {
  std::optional<User> existingUser = searchActiveDirectory(user.getUsername());

  if (existingUser.has_value()) {
    existingUser->update(user);
  } else {
    createNewUser(user);
  }

  if (!validateUserStatus(user)) {
    logError("User status mismatch");
    return false;
  }
}

bool validateUserStatus(const User& user) {
  std::optional<User> existingUser = searchActiveDirectory(user.getUsername());

  if (existingUser.has_value()) {
    return existingUser->getStatus() == 'Active';
  } else {
    return false;
  }
}

void handleUserStatusMismatch(const User& user) {
  std::optional<User> existingUser = searchActiveDirectory(user.getUsername());

  if (existingUser.has_value()) {
    existingUser->update(user);
  } else {
    logError("User status mismatch");
    return false;
  }

  if (!validateUserStatus(user)) {
    logError("User status mismatch");
    return false;
  }
}

