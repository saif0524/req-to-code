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

bool validate_passwords(const std::string& password, const std::string& repeat_password);

bool validate_passwords(const std::string& password, const std::string& repeat_password) {
  if (password != repeat_password) {
    return false;
  }
  return true;
}

