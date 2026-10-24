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

int load_heating_cooling_units(const std::string& filename);
void store_heating_cooling_units(int max_units);

int load_heating_cooling_units(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    return -1; // Return an error code if the file cannot be opened
  }

  int max_units;
  file >> max_units;

  file.close();
  return max_units;
}

