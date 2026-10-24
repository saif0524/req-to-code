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

using HeatingCoolingUnit = ...;

bool is_max_units_running(const std::vector<HeatingCoolingUnit>& units);
void add_to_queue(std::vector<HeatingCoolingUnit>& units, const HeatingCoolingUnit& unit);
void process_queue(std::vector<HeatingCoolingUnit>& units);
void turn_on_unit(const HeatingCoolingUnit& unit);

bool is_max_units_running(std::vector<HeatingCoolingUnit>& units) { return units.size() == max_units; }

void add_to_queue(std::vector<HeatingCoolingUnit>& units, const HeatingCoolingUnit& unit) { using HeatingCoolingUnit = ...; if (units.size() < max_units) { units.push_back(unit); } else { units.pop_front(); units.push_back(unit); } }

void process_queue(std::vector<HeatingCoolingUnit>& units, int max_units, const HeatingCoolingUnit& unit) { if (!is_max_units_running(units, max_units)) { add_to_queue(units, unit); } else { units.pop_front(); units.push_back(unit); } if (units.front().thermostat.needs_heating()) { turn_on_unit(units.front()); } else if (units.front().thermostat.needs_cooling()) { turn_on_unit(units.front()); } }

void turn_on_unit(const HeatingCoolingUnit& unit) { if (!is_max_units_running(units)) { add_to_queue(units, unit); } else { units.pop_front(); units.push_back(unit); } if (!units.empty() && units.front().thermostat.needs_heating()) { turn_on_unit(units.front()); } else if (!units.empty() && units.front().thermostat.needs_cooling()) { turn_on_unit(units.front()); } }

