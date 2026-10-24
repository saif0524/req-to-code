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

Thermostat
void displayThermostat(Thermostat& thermostat)
void setThermostat(Thermostat& thermostat, double temperature)
double getThermostat(Thermostat& thermostat)

void displayThermostat(Thermostat& thermostat);
void setThermostat(Thermostat& thermostat, double temperature);
double getThermostat(Thermostat& thermostat);

void setThermostat(Thermostat& thermostat, double temperature){
	thermostat.temperature = temperature;
}

