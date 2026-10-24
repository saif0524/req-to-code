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

vector<Thermostat> getThermostatTemperatures(const vector<Thermostat>& thetas);
double getThermostatCurrentTemp(const Thermostat& t);
bool needsHeating(double current_temp, double set_temp);
void startHeating(Thermostat& t);

vector<Thermostat> getThermostatTemperatures(const vector<Thermostat>& thetas) {
    vector<Thermostat> result;
    for (const Thermostat& t : thetas) {
        result.push_back(getThermostatCurrentTemp(t));
    }
    return result;
}

double getThermostatCurrentTemp(const Thermostat& t) {
  return t.getThermostatCurrentTemp();
}

bool needsHeating(double current_temp, double set_temp) {
  double difference = set_temp - current_temp;
  return difference > 0;
  }

void startHeating(Thermostat& t) \ \ { \ \  double current_temp = t.getThermostatCurrentTemp(); \ \  if (current_temp < t.getThermostatSetTemp()) \ \  { \ \   t.startHeating(); \ \  } \ \ }

