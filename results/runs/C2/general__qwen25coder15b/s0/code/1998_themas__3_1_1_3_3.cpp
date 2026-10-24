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

using namespace std;

int read_max_concurrent_units(const std::string& file_path);
void store_max_concurrent_units(int max_units, const std::string& file_path);

using namespace std;

int read_max_concurrent_units(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + file_path);
  }
  int max_units;
  file >> max_units;
  if (!file.eof()) {
    throw std::runtime_error("Invalid file format: expected integer value only");
  }
  file.close();
  return max_units;
}

void store_max_concurrent_units(int max_units, const std::string& file_path) {
  std::ofstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + file_path);
  }
  int current_max_units;
  file >> current_max_units;
  if (!file.eof()) {
    throw std::runtime_error("Invalid file format: expected integer value only");
  }
  file << max_units;
}

