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

double getThermostatTemperature(int thermostatId);
void setThermostatTemperature(int thermostatId, double temperature);
bool getHeatingUnitStatus(int heatingUnitId);
bool getCoolingUnitStatus(int coolingUnitId);
void sendSignalToHeatingUnit(int heatingUnitId, int signal);

double getThermostatTemperature(int thermostatId) { return getThermostatTemperature(thermostatId); }

void setThermostatTemperature(int thermostatId, double temperature) { setThermostatTemperature(thermostatId, temperature); }

bool getHeatingUnitStatus(int heatingUnitId) { sendSignalToHeatingUnit(heatingUnitId, 1); return getHeatingUnitStatus(heatingUnitId); }

bool getCoolingUnitStatus(int coolingUnitId) { sendSignalToHeatingUnit(coolingUnitId, 2); return getHeatingUnitStatus(coolingUnitId); }

bool sendSignalToHeatingUnit(int heatingUnitId, int signal) { return true; }

