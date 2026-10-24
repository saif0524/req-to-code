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

.cpp
std::string
currentReading
maxPossible is a new variable that should be defined in the function.

double read_temp(SensorType sensor, double currentReading);
void set_temp_setpoint(double currentTemp, double setPoint);
void set_temp_setpoint_to(double targetTemp);
double calculate_heating_required(double currentTemp, double desiredTemp, double maxPossible);
double calculate_cooling_required(double currentTemp, double desiredTemp);

double read_temp(SensorType sensor, double currentReading) {  double sensorValue = (double) sensor.value;  return sensorValue; }

double set_temp_setpoint(double currentTemp, double setPoint) { currentReading = setPoint; return currentReading; }

double set_temp_setpoint_to(double targetTemp) { currentReading = targetTemp; return 0.0; }

double calculate_heating_required(double currentTemp, double desiredTemp, double maxPossible) {
  if (desiredTemp > currentTemp) {
    double required = (desiredTemp - currentTemp) / maxPossible;
    return required;
  } else {
    return -1.0;
  }
}

double calculate_cooling_required(double currentTemp, double desiredTemp) {  if (desiredTemp > currentTemp) {    double required = (desiredTemp - currentTemp) / maxPossible;    return required;  } else {    return -1.0;  } }

