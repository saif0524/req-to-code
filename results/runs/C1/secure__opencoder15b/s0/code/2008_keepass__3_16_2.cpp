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

std::filesystem;

bool validate_path(const std::string& path);
bool parse_arguments(int argc, char* argv[]);

bool validate_path(const std::string& path) {
  if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path)) {
    return true;
  } else {
    return false;
  }
}

bool parse_arguments(int argc, char* argv[]) {
  std::string db_path;
  for (int i = 1; i < argc; ++i) {
    db_path += argv[i];
    if (i != argc - 1) {
      db_path += " ";
    }
  }
  return validate_path(db_path);
}

