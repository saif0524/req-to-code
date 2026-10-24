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

bool is_valid_path(const std::string& path);

bool is_valid_path(const std::string& path) {
  if (path.find(' ') != std::string::npos) {
    return true;
  }
  return false;
}

