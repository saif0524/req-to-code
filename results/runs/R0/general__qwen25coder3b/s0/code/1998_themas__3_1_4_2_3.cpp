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

bool checkTemperature(double currentTemp, double lowerTrigger, double upperTrigger);
void determineHCMode(double currentTemp, double lowerTrigger, double upperTrigger);
void outputRequest(bool turnOffHeating, bool turnOffCooling);

bool checkTemperature(double currentTemp, double lowerTrigger, double upperTrigger) {
  return currentTemp >= lowerTrigger && currentTemp <= upperTrigger;
}

void determineHCMode(double currentTemp, double lowerTrigger, double upperTrigger) {
  bool isWithinRange = checkTemperature(currentTemp, lowerTrigger, upperTrigger);
  bool turnOffHeating = !isWithinRange;
  bool turnOffCooling = !isWithinRange;
  if (currentTemp < lowerTrigger) {
    turnOffHeating = false;
    turnOffCooling = true;
  } else if (currentTemp > upperTrigger) {
    turnOffHeating = true;
    turnOffCooling = false;
  }
  outputRequest(turnOffHeating, turnOffCooling);
}

void outputRequest(bool turnOffHeating, bool turnOffCooling) {
  if (turnOffHeating) {
    std::cout << "Turn off heating unit" << std::endl;
  } else {
    std::cout << "Turn on heating unit" << std::endl;
  }
  if (turnOffCooling) {
    std::cout << "Turn off cooling unit" << std::endl;
  } else {
    std::cout << "Turn on cooling unit" << std::endl;
  }
}

