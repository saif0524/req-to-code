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

std::optional<User> search_user(const std::string& user_name, const std::string& display_name);
bool verify_user(const User& user);

std::optional<User> search_user(const std::string& user_name, const std::string& display_name) {
  std::optional<User> found_user = search_user(user_name, display_name);
  return found_user.has_value();
}

bool verify_user(const User& user) {
  std::optional<User> found_user = search_user(user.user_name, user.display_name);
  return found_user.has_value();
}

