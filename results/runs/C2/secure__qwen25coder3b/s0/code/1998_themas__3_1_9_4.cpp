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

std::vector<std::string> getAvailableThermostats();
std::map<std::string, int> getCurrentTemperatureSettings();
void displayThermostatSettings(const std::vector<std::string>& thermostats, const std::map<std::string, int>& settings);
std::string selectThermostat(const std::vector<std::string>& thermostats);
bool validateTemperature(int temperature);

std::vector<std::string> getAvailableThermostats() { std::vector<std::string> thermostats; return thermostats; }

std::map<std::string, int> getCurrentTemperatureSettings(const std::map<std::string, int>& currentTemperatureSettings) { return currentTemperatureSettings; }

void displayThermostatSettings(const std::vector<std::string>& thermostats, const std::map<std::string, int>& settings) {
  for (const auto& thermostat : thermostats) {
    std::cout << thermostat << " - Current Temperature: " << settings[thermostat] << std::endl;
  }
}

std::string selectThermostat(const std::vector<std::string>& thermostats) {
  std::string selectedThermostat;
  std::cout << "Select a thermostat: " << std::endl;
  for (const auto& thermostat : thermostats) {
    std::cout << thermostat << std::endl;
  }
  std::cin >> selectedThermostat;
  if (std::find(thermostats.begin(), thermostats.end(), selectedThermostat) == thermostats.end()) {
    std::cout << "Invalid thermostat selected. Please try again." << std::endl;
    return selectThermostat(thermostats);
  }
  return selectedThermostat;
}

bool validateTemperature(int temperature) {
  std::vector<int> validTemperatures = {18, 20, 22, 24, 26};
  return std::find(validTemperatures.begin(), validTemperatures.end(), temperature) != validTemperatures.end();
}

