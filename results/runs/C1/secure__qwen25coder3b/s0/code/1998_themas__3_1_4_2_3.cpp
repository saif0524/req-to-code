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
void outputRequest(bool turnOnHeating, bool turnOnCooling);

bool checkTemperature(double currentTemp, double lowerTrigger, double upperTrigger) {
  return (currentTemp >= lowerTrigger) && (currentTemp <= upperTrigger);
}

void outputRequest(bool turnOnHeating, bool turnOnCooling, bool bothHeatingAndCooling) { std::string request = turnOnHeating ? "Turn on heating" : "Turn off heating"; request += turnOnCooling ? " and turn on cooling" : " and turn off cooling"; request += bothHeatingAndCooling ? " and turn on both" : ""; std::cout << request << std::endl; }

void outputRequest(bool turnOnHeating, bool turnOnCooling) {
  std::string request = turnOnHeating ? "Turn on heating" : "Turn off heating";
  request += turnOnCooling ? " and turn on cooling" : " and turn off cooling";
  std::cout << request << std::endl;
}

