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

int read_max_units_from_file(const std::string& file_path);
void store_max_units_in_system(int max_units);

int read_max_units_from_file(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file "

void store_max_units_in_system(int max_units) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << file_path << std::endl;
    return;
  }
  int max_units_from_file = read_max_units_from_file(file_path);
  if (max_units_from_file == -1) {
    std::cerr << "Error: Unable to read maximum number of units from file" << std::endl;
    return;
  }
  max_units = max_units_from_file;
  std::cout << "Maximum number of units stored successfully" << std::endl;
}

