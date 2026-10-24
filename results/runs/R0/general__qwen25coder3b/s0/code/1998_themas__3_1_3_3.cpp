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

bool validateTemperature(double currentTemperature, double lowerRange, double upperRange);
bool validateTemperatureSetting(double temperatureSetting, double lowerRange, double upperRange);
void processTemperatureData(double currentTemperature, double temperatureSetting, double lowerRange, double upperRange);

bool validateTemperature(double currentTemperature, double lowerRange, double upperRange) {
  if (currentTemperature < lowerRange || currentTemperature > upperRange) {
    return false;
  }
  return true;
}

bool validateTemperatureSetting(double temperatureSetting, double lowerRange, double upperRange) {
  if (temperatureSetting < lowerRange || temperatureSetting > upperRange) {
    return false;
  }
  return true;
}

void processTemperatureData(double currentTemperature, double temperatureSetting, double lowerRange, double upperRange) {
  if (!validateTemperature(currentTemperature, lowerRange, upperRange)) {
    // Output invalid temperature status for current temperature
    return;
  }

  if (!validateTemperatureSetting(temperatureSetting, lowerRange, upperRange)) {
    // Output invalid temperature status for temperature setting
    return;
  }

  // Set the thermostat's temperature setting
  // (Assuming there's a function to set the temperature setting)
  setThermostatTemperatureSetting(temperatureSetting);
}

