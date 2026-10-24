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
void readTemperatureValues();
void readTemperatureSettings();
void determineUnitStatus();
void turnOnUnits();

void initializeSystem() {
  // Step 1: Turn off all heating and cooling units
  turnOffAllUnits();

  // Step 2: Read current temperature values of each thermostat
  readTemperatureValues();

  // Step 3: Read current temperature settings of each thermostat
  readTemperatureSettings();

  // Step 4: Determine the status of each heating and cooling unit
  determineUnitStatus();

  // Step 5: Turn on the appropriate heating or cooling units
  turnOnUnits();
}

void readTemperatureValues() {
  // Assuming 'thermostats' is a shared vector of thermostat data structures
  std::vector<Thermostat> &thermostats = getThermostats();

  // Create a JSON object to store the temperature values
  json temperatures;

  // Iterate over each thermostat
  for (const auto &thermostat : thermostats) {
    // Retrieve the current temperature
    double temperature = thermostat.getCurrentTemperature();

    // Add the temperature to the JSON object
    temperatures[thermostat.getId()] = temperature;
  }

  // Return the JSON object
  return temperatures;
}

void readTemperatureSettings() {
  // Assuming 'thermostats' is a shared vector of thermostat data structures
  std::vector<Thermostat> &thermostats = getThermostats();

  // Create a JSON object to store the temperature settings
  json settings;

  // Iterate over each thermostat
  for (const auto &thermostat : thermostats) {
    // Retrieve the current temperature setting
    double setting = thermostat.getCurrentTemperatureSetting();

    // Add the setting to the JSON object
    settings[thermostat.getId()] = setting;
  }

  // Return the JSON object
  return settings;
}

void determineUnitStatus() {
  struct Thermostat;
  using json = nlohmann::json;
  using std::begin;
  using std::end;

  std::vector<Thermostat> &thermostats = getThermostats();

  json statuses;

  for (const auto &thermostat : thermostats) {
    if (thermostat.getCurrentTemperature() < thermostat.getCurrentTemperatureSetting()) {
      statuses[thermostat.getId()] = "Heating";
    } else if (thermostat.getCurrentTemperature() > thermostat.getCurrentTemperatureSetting()) {
      statuses[thermostat.getId()] = "Cooling";
    } else {
      statuses[thermostat.getId()] = "Off";
    }
  }

  return statuses;
}

void turnOnUnits() {
  // Assuming 'thermostats' is a shared vector of thermostat data structures
  std::vector<Thermostat> &thermostats = getThermostats();

  // Create a JSON object to store the units to be turned on
  json unitsToTurnOn;

  // Iterate over each thermostat
  for (const auto &thermostat : thermostats) {
    // Check if the thermostat needs heating
    if (thermostat.getCurrentTemperature() < thermostat.getCurrentTemperatureSetting()) {
      unitsToTurnOn[thermostat.getId()] = "Heating";
    }
    // Check if the thermostat needs cooling
    else if (thermostat.getCurrentTemperature() > thermostat.getCurrentTemperatureSetting()) {
      unitsToTurnOn[thermostat.getId()] = "Cooling";
    }
  }

  // Return the JSON object with the reasoning
  return unitsToTurnOn;
}

