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
  // Include necessary headers

  // Declare the Json class
  using Json = Json::Value;

  // Create a JSON object to store the event details
  Json event;

  // Set the event type to 'request denied'
  event["type"] = "request denied";

  // Set the thermostat name
  event["thermostat"] = thermostat.name;

  // Set the heating or cooling unit name
  event["unit"] = unit.name;

  // Print the event details
  std::cout << event << std::endl;
}

