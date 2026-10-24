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

std::string selectedThermostatName;

void displayThermostats(const std::vector<std::pair<std::string, int>>& thermostats);
std::vector<int> getValidTemperatures();
void selectThermostat(const std::string& thermostatName);
void setTemperature(int temperature);
void handleUserInput();

void displayThermostats(const std::vector<std::pair<std::string, int>>& thermostats) {
  for (const auto& [thermostatName, temperature] : thermostats) {
    std::cout << thermostatName << " - Current Temperature: " << temperature << std::endl;
  }
}

std::vector<int> getValidTemperatures() {
  std::vector<int> validTemperatures;
  for (int temp = 10; temp <= 30; temp++) {
    validTemperatures.push_back(temp);
  }
  return validTemperatures;
}

void selectThermostat(const std::string& thermostatName, const std::vector<std::pair<std::string, int>>& thermostats) {
  for (auto& [thermostatName, temperature] : thermostats) {
    if (thermostatName == thermostatName) {
      selectedThermostatName = thermostatName;
      break;
    }
  }
}

void setTemperature(int& temperature, const std::vector<std::pair<std::string, int>>& thermostats) {
  for (auto& [thermostatName, thermostatTemp] : thermostats) {
    if (thermostatName == selectedThermostatName) {
      thermostatTemp = temperature;
      break;
    }
  }
}

void handleUserInput() {
  std::vector<std::pair<std::string, int>> thermostats = getThermostats();
  displayThermostats(thermostats);

  std::string thermostatName;
  std::cout << "Select a thermostat: " << std::endl;
  std::cin >> thermostatName;

  int temperature;
  std::vector<int> validTemperatures = getValidTemperatures();
  std::cout << "Select a temperature: " << std::endl;
  for (int temp : validTemperatures) {
    std::cout << temp << " ";
  }
  std::cout << std::endl;
  std::cin >> temperature;

  selectThermostat(thermostatName);
  setTemperature(temperature);
}

