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

bool validate_tan(const std::string& tan, const std::string& username);
bool use_tan(std::string& tan, const std::string& username);
bool tan_expired(const std::string& tan);

bool validate_tan(const std::string& tan, const std::string& username) {
  // Check if the TAN code is expired.
  if (tan_expired(tan)) {
    return false;
  }
  // If the TAN code is not expired, it is valid.
  return true;
}

bool use_tan(std::string& tan, const std::string& username) {
  // Check if the TAN code is expired.
  if (tan_expired(tan)) {
    return false;
  }
  // If the TAN code is not expired, it is valid.
  return true;
}

bool tan_expired(const std::string& tan) {
    // Get the current time.
   time_t current_time = time(nullptr);
    // Check if the TAN code has expired.
    if (current_time > tan->created_at) {
      // Remove the TAN code from the user's session.
     tan->code = "";
      // Return a JSON object with the 'code' field set to the TAN code
      // and the 'reason' field set to 'TAN code has expired'.
     return true;
    }
    // The TAN code is not expired.
    return false;
}

