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

void initializeSystem();
void readCurrentTemperatures();
void determineUnitStatus();
void turnOnUnit(int unitId);
void turnOffUnits();

void initializeSystem() {
  turnOffUnits();
  readCurrentTemperatures();
  determineUnitStatus();
  // Return JSON with the results of the initialization process.
}

void readCurrentTemperatures() {
  json result;
  for (int i = 0; i < numberOfThermostats; i++) {
    double currentTemperature = getTemperature(i);
    double currentSetting = getSetting(i);
    result["thermostat" + to_string(i)] = {"temperature": currentTemperature, "setting": currentSetting};
  }
  return result;
}

void determineUnitStatus() {
  json result;

  for (int i = 0; i < numberOfThermostats; i++) {
    double currentTemperature = getTemperature(i);
    double currentSetting = getSetting(i);

    if (currentSetting > currentTemperature) {
      result["thermostat" + to_string(i)] = {"reasoning": "Heating needed"};
    } else if (currentSetting < currentTemperature) {
      result["thermostat" + to_string(i)] = {"reasoning": "Cooling needed"};
    } else {
      result["thermostat" + to_string(i)] = {"reasoning": "No action needed"};
    }
  }

  return result;
}

void turnOnUnit(int unitId) { if (unitId < 0 || unitId >= numberOfThermostats) { return json{{"unitId": unitId, "reasoning": "Invalid unitId"}}; } turnOn(unitId); return json{{"unitId": unitId, "reasoning": "Unit turned on"}}; }

void turnOffUnits() { json result; for (int i = 0; i < numberOfThermostats; i++) { turnOff(i); result["thermostat" + to_string(i)] = {"reasoning": "Unit turned off"}; } return result; }

