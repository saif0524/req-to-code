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

bool searchUser(const std::string& displayName, const std::string& userName, std::vector<User>& users);
User getUserById(int userId);
bool validateUser(const User& user);
bool createUser(const User& user);
bool updateUser(const User& user);

bool searchUser(const std::string& displayName, const std::string& userName, std::vector<User>& users) {
  if (displayName.empty() || userName.empty()) {
    return false;
  }

  for (const auto& user : users) {
    if (user.displayName == displayName && user.userName == userName) {
      return true;
    }
  }

  return false;
}

User getUserById(int userId) {
  for (const auto& user : users) {
    if (user.id == userId) {
      return user;
    }
  }
  return User(); // or throw an exception
}

bool validateUser(const User& user) {
  return searchUser(user.displayName, user.userName, users);
}

bool createUser(const User& user) {
  if (searchUser(user.displayName, user.userName, users)) {
    return false; // User already exists
  }

  // Add the new user to the users vector
  users.push_back(user);

  return true; // User created successfully
}

bool updateUser(const User& user) {
  if (!validateUser(user)) {
    return false; // User does not exist
  }

  for (auto& u : users) {
    if (u.id == user.id) {
      u.displayName = user.displayName;
      u.userName = user.userName;
      u.email = user.email;
      u.password = user.password;
      return true; // User updated successfully
    }
  }

  return false; // User not found
}

