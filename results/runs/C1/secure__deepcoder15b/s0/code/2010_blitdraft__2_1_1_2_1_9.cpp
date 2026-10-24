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

string userDisplayName, string userUsername -> string& string;
string userDisplayName, string userUsername -> bool;
string userDisplayName, string userUsername -> bool;
string userDisplayName -> string;
string userUsername -> string;

string userDisplayName(const std::string& userDisplayName, const std::string& userUsername) {
  return userDisplayName + " " + userUsername;
}

string userDisplayName(const std::string& userDisplayName, const std::string& userUsername) { return userDisplayName + " " + userUsername; } string userDisplayName(string userDisplayName) { return userDisplayName; }

std::string userDisplayName(const std::string& userDisplayName) { return userDisplayName; }

std::string userUsername(const std::string& userUsernameStr) {
  std::string stream;
  std::string s = stream >> userUsernameStr;
  size_t space_pos = s.find('');
  if (space_pos != std::string::npos) {
    return s.substr(0, space_pos);
  }
  return userUsernameStr;
}

