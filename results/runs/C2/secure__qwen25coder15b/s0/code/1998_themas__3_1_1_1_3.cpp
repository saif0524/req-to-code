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

struct HCUnit {
  int id;
  std::string name;

  void parse(const std::string& line);
};

void load_hc_unit_definitions(const std::string& initialization_data_file);

void load_hc_unit_definitions(const std::string& initialization_data_file) {
  std::vector<HCUnit> hc_units;
  std::map<int, HCUnit> hc_units_by_id;
  std::set<std::string> hc_units_by_name;
  std::unordered_map<std::string, int> hc_units_by_name_and_id;

  std::ifstream file(initialization_data_file);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open initialization data file");
  }

  std::string line;
  while (std::getline(file, line)) {
    HCUnit unit;
    unit.parse(line);
    hc_units.push_back(unit);
    hc_units_by_id[unit.id] = unit;
    hc_units_by_name.insert(unit.name);
    hc_units_by_name_and_id[unit.name] = unit.id;
  }
}

