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

void search_user(const std::string& user_name, const std::string& display_name);
bool verify_user(const std::string& user_name, const std::string& display_name);

void search_user(const std::string& user_name, const std::string& display_name) {
  // Call the search_user function from the planned functions
  bool found = search_user(user_name, display_name);

  // Return the result
  return found;
}

bool verify_user(const std::string& user_name, const std::string& display_name) {
  // Call the search_user function from the planned functions
  bool found = search_user(user_name, display_name);

  // Check if the user is found in the table
  if (found) {
    return true;
  } else {
    return false;
  }
}

