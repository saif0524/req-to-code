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
void turnHeatingCoolingOff();
void turnHeatingCoolingOn();
void handleSupervisorCommand(const std::string& command);
void updateStatus();

bool getHeatingCoolingStatus() {
  static bool simulatedStatus = false; // Simulated status of the heating/cooling unit
  return "status": simulatedStatus;
}

void turnHeatingCoolingOff() {
  static bool simulatedStatus = true; // Simulated status of the heating/cooling unit
  simulatedStatus = false;
  std::cout << "Unit turned off" << std::endl;
  std::cout << "reasoning": "Unit turned off" << std::endl;
}

void turnHeatingCoolingOn() {
  static bool simulatedStatus = false; // Simulated status of the heating/cooling unit
  simulatedStatus = true;
  std::cout << "Unit turned on" << std::endl;
  std::cout << "reasoning": "Unit turned on" << std::endl;
}

void handleSupervisorCommand(const std::string& command) {
  static bool simulatedStatus = false;
  if (command == "on") {
    simulatedStatus = true;
    std::cout << "Unit turned on" << std::endl;
    std::cout << "reasoning": "Unit turned on" << std::endl;
  } else if (command == "off") {
    simulatedStatus = false;
    std::cout << "Unit turned off" << std::endl;
    std::cout << "reasoning": "Unit turned off" << std::endl;
  }
  return {"status": simulatedStatus};
}

void updateStatus() {
  static bool simulatedStatus = false;
  std::string status = getHeatingCoolingStatus()['status'];
  std::cout << "Status updated to: " << status << std::endl;
  std::cout << "reasoning": "Status updated to: " << status << std::endl;
}

