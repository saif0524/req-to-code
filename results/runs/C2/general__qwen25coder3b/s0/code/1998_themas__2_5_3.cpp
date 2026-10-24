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

bool getHeatingCoolingStatus();
void setHeatingCoolingStatus(bool status);
void turnHeatingCoolingOff();
void turnHeatingCoolingOn();
void handleSupervisorCommand(const std::string& command);

bool getHeatingCoolingStatus() { bool status = false; return status; }

void setHeatingCoolingStatus(bool status) { setHeatingCoolingStatus(status); std::cout << "{Heating/cooling unit set to 

bool turnHeatingCoolingOff() { setHeatingCoolingStatus(false); return true; }

void turnHeatingCoolingOn() { return setHeatingCoolingStatus(true); }

void handleSupervisorCommand(const std::string& command) {
  std::string upperCommand = command;
  std::transform(upperCommand.begin(), upperCommand.end(), upperCommand.begin(), ::toupper);

  if (upperCommand == "ON") {
    setHeatingCoolingStatus(true);
  } else if (upperCommand == "OFF") {
    setHeatingCoolingStatus(false);
  }

  // Return JSON object with result
  std::string result = upperCommand == "ON" ? "Heating/cooling unit turned ON" : "Heating/cooling unit turned OFF";
  std::cout << "{" << result << "}" << std::endl;
}

