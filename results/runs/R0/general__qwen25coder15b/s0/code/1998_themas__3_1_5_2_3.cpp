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

void generate_unit_unavailable_event(const Thermostat& thermostat, const HeatingCoolingUnit& unit);

void generate_unit_unavailable_event(const Thermostat& thermostat, const HeatingCoolingUnit& unit) {
  // Create a JSON object to store the event details
  Json::Value event;

  // Set the event type to 'request denied'
  event[

