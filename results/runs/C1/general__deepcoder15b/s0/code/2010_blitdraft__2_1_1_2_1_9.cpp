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

${userMap = std::map<std::string, User*>>

void searchUser(const string& searchDisplayName, int* userId, const string& name, int count);

void searchUser(const std::string& searchDisplayName, int* userId, const std::string& name, int count) {
  static std::map<std::string, User*> userMap;

  // Populate the map with all possible display names
  // For example, if the system has a list of display names:
  // userMap = {{"user1"}, {{"user2"}}, ...};

  // Loop through each user in the map to find a match
  for (auto& pair : userMap) {
    if (pair.first == searchDisplayName && name == pair.second && count >= (pair.second ? pair.first.count : static_cast<int>(pair.first).count)) {
      return true;
    }
  }

  return false;
  }

