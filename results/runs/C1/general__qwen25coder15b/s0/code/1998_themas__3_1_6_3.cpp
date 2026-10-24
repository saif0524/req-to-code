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

void read_heating_cooling_unit_status(HeatingCoolingUnit& unit, bool& is_on);
void generate_signal(HeatingCoolingUnit& unit, bool& is_on);
void output_status(HeatingCoolingUnit& unit);
void generate_event(HeatingCoolingUnit& unit);

void read_heating_cooling_unit_status(HeatingCoolingUnit& unit, bool& is_on) {
  is_on = unit.is_on;
}

void generate_signal(const HeatingCoolingUnit& unit, bool& is_on) {
  return TBD::generate_signal(unit, is_on);
}

void output_status(const HeatingCoolingUnit& unit) {
  std::cout << (unit.is_on ? "ON" : "OFF") << std::endl;
}

void generate_event(HeatingCoolingUnit& unit) {
  bool previous_status = unit.is_on;
  unit.is_on = !previous_status;
  // Call the generate_signal function from the TBD class
  TBD::generate_signal(unit, unit.is_on);
  // Output the status information of the heating or cooling unit
  output_status(unit);
}

