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

bool validateTemperatureSetting(int temperatureSetting, int lowerBound, int upperBound);
bool validateCurrentTemperature(int currentTemperature, int lowerBound, int upperBound);
void processTemperatureData(int temperatureSetting, int currentTemperature, int lowerBound, int upperBound);

bool validateTemperatureSetting(int temperatureSetting, int lowerBound, int upperBound) {
  if (temperatureSetting < lowerBound || temperatureSetting > upperBound) {
    return false;
  }
  return true;
}

bool validateCurrentTemperature(int currentTemperature, int lowerBound, int upperBound) {
  if (currentTemperature < lowerBound || currentTemperature > upperBound) {
    return false;
  }
  return true;
}

void processTemperatureData(int temperatureSetting, int currentTemperature, int lowerBound, int upperBound) {
  if (!validateTemperatureSetting(temperatureSetting, lowerBound, upperBound)) {
    std::cout << "Invalid temperature setting" << std::endl;
    return;
  }

  if (!validateCurrentTemperature(currentTemperature, lowerBound, upperBound)) {
    std::cout << "Invalid current temperature" << std::endl;
    return;
  }

  std::cout << "Valid temperature setting and current temperature" << std::endl;
}

