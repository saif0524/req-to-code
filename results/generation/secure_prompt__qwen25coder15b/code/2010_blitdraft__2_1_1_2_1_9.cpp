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

bool verify_user(const User& user);

bool verify_user(const User& user) {
  std::optional<User> found_user = search_user(user.user_name, user.display_name);
  return found_user.has_value();
}

