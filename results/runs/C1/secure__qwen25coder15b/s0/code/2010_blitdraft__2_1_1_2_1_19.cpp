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

bool validate_user_data(const User& user);
bool check_required_fields(const User& user);
std::string generate_error_message(const User& user);

bool validate_user_data(const User& user) {
  if (!check_required_fields(user)) {
    return generate_error_message(user, "Required fields are missing");
  }
  if (!validate_user_data(user)) {
    return generate_error_message(user, "User data is invalid");
  }
  return true;
}

bool check_required_fields(const User& user) {
  if (!validate_user_data(user)) {
    return generate_error_message(user, "Required fields are missing");
  }
  return true;
}
std::string generate_error_message(const User& user, const std::string& message) {
  return message;
}

std::string generate_error_message(const User& user, const std::string& message) {
  if (!validate_user_data(user)) {
    return message;
  }
  return 'User data is valid';
}

