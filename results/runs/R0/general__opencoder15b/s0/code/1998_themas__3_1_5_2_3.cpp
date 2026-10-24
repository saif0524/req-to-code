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

void generateUnitUnavailableEvent(const std::string& thermostatId, const std::string& unitId);

void generateUnitUnavailableEvent(const std::string& thermostatId, const std::string& unitId) {
  // Create a system event
  std::string event = "Unit unavailable event: Thermostat " + thermostatId + " requested unit " + unitId + " but was not turned on.";

  // Log the event
  std::cout << event << std::endl;
}

