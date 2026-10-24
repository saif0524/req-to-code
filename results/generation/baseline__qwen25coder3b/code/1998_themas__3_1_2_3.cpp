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
  // Step 1: Initialize a JSON object to store the results.
  json result;

  // Step 2: Iterate over each thermostat.
  for (int i = 0; i < numberOfThermostats; i++) {
    // Step 3: Read the current temperature value.
    double currentTemperature = getTemperature(i);

    // Step 4: Read the current temperature setting.
    double currentSetting = getSetting(i);

    // Step 5: Add the temperature and setting to the JSON object.
    result["thermostat" + to_string(i)] = {"temperature": currentTemperature, "setting": currentSetting};
  }

  // Step 6: Return the JSON object.
  return result;
}

void determineUnitStatus() {
  json result;

  for (int i = 0; i < numberOfThermostats; i++) {
    double currentTemperature = getTemperature(i);
    double currentSetting = getSetting(i);

    if (currentSetting > currentTemperature) {
      result[

void turnOnUnit(int unitId) {
  if (unitId < 0 || unitId >= numberOfThermostats) {
    return json{"unitId": unitId, "reasoning": "Invalid unitId"};
  }
  turnOn(unitId);
  return json{"unitId": unitId, "reasoning": "Unit turned on"};
}

void turnOffUnits() {
  json result;

  for (int i = 0; i < numberOfThermostats; i++) {
    turnOff(i);
    result["thermostat" + to_string(i)] = {"reasoning": "Unit turned off"};
  }

  return result;
}

