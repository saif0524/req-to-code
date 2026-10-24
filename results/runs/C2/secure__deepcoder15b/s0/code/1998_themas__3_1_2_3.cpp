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
double getThermostatSetTemp(const Thermostat& t);
bool needsHeating(double current_temp, double set_temp);
void startHeating(Thermostat& t);

vector<int> indices;
  vector<Thermostat> getThermostatTemperatures(const vector<Thermostat>& thetas) \ \ { \ \  vector<Thermostat> result; \ \  for (int i = 0; i < thetas.size(); i++) \ \ { \ \    const Thermostat& t = thetas[i]; \ \    result.push_back(getThermostatCurrentTemp(i)); \ \  } \ \  return result; \ \ }

double getThermostatCurrentTemp(const Thermostat& t) { return t.current_temp; }

double getThermostatSetTemp(const Thermostat& t) { return t.getSetTemp(); }

bool needsHeating(double current_temp, double set_temp) {
  double difference = set_temp - current_temp;
  return difference > 0;
  }

void startHeating(Thermostat& t) {
  double current_temp = t.getThermostatCurrentTemp();
  if (current_temp < t.getThermostatSetTemp()) {
    t.startHeating();
  }
  return;
  }

