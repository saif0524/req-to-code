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

bool compareTemperature(double reportedTemp, double tempSetting, double od);
std::string determineTemperatureStatus(double reportedTemp, double tempSetting, double od);

bool compareTemperature(double reportedTemp, double tempSetting, double od) {
  double LO = tempSetting - od;
  double UO = tempSetting + od;
  return reportedTemp == LO || reportedTemp == UO || LO == reportedTemp == UO;
}

std::string determineTemperatureStatus(double reportedTemp, double tempSetting, double od) {
  if (compareTemperature(reportedTemp, tempSetting, od)) {
    return "Temperature Limit Exceeded";
  } else {
    return "Temperature Normal";
  }
}

