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

bool getHeatingCoolingStatus() { static bool simulatedStatus = false; return simulatedStatus; }

void turnHeatingCoolingOff() { static bool simulatedStatus = true; simulatedStatus = false; std::cout << "Unit turned off" << std::endl; std::cout << "reasoning": "Unit turned off" << std::endl; return false; }

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
  return;
}

struct HeatingCoolingStatus { bool status; std::string statusString; }; void updateStatus() { static HeatingCoolingStatus simulatedStatus = {false, "off"}; std::string status = simulatedStatus.statusString; std::cout << "Status updated to: " << status << std::endl; std::cout << "reasoning": "Status updated to: " << status << std::endl; }

