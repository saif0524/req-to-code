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

bool compareTemperature(double reportedTemp, double tempSetting, double overTempOffset);
std::string determineTemperatureStatus(double reportedTemp, double tempSetting, double overTempOffset);

bool compareTemperature(double reportedTemp, double tempSetting, double overTempOffset) {
  double lowerOverTemp = tempSetting - overTempOffset;
  double upperOverTemp = tempSetting + overTempOffset;
  return reportedTemp <= lowerOverTemp || reportedTemp >= upperOverTemp;
}

std::string determineTemperatureStatus(double reportedTemp, double tempSetting, double overTempOffset) {
  double lowerOverTemp = tempSetting - overTempOffset;
  double upperOverTemp = tempSetting + overTempOffset;

  if (reportedTemp <= lowerOverTemp) {
    return "Overtemperature";
  } else if (reportedTemp >= upperOverTemp) {
    return "Overtemperature";
  } else if (reportedTemp == lowerOverTemp || reportedTemp == upperOverTemp) {
    return "Limit Exceeded";
  } else {
    return "Normal";
  }
}

