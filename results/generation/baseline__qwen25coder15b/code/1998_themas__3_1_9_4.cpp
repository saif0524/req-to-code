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

void displayThermostats();
void selectThermostat(int index);
void selectTemperature(int index);

void displayThermostats() {
  // Access the necessary data structures and variables
  Thermostat* thermostat = getThermostat();
  Temperature* temperature = getTemperature();

  // Retrieve the available thermostats and their current temperature settings
  int numThermostats = getNumThermostats();
  int numTemperatures = getNumTemperatures();

  // Print the information to the console
  for (int i = 0; i < numThermostats; i++) {
    cout << thermostat[i].name << ' ' << thermostat[i].currentTemperature << endl;
  }
}

void selectThermostat(int index) {
  // Access the necessary data structures and variables
  Thermostat* thermostat = getThermostat();
  Temperature* temperature = getTemperature();

  // Retrieve the available thermostats and their current temperature settings
  int numThermostats = getNumThermostats();
  int numTemperatures = getNumTemperatures();

  // Set the selected thermostat variable to the thermostat object at the specified index
  selectedThermostat = &thermostat[index];

  // Print a confirmation message to the console
  cout << "Thermostat 

void selectTemperature(int index) {
  // Access the necessary data structures and variables
  Thermostat* thermostat = getThermostat();
  Temperature* temperature = getTemperature();

  // Retrieve the available thermostats and their current temperature settings
  int numThermostats = getNumThermostats();
  int numTemperatures = getNumTemperatures();

  // Set the selected thermostat variable to the thermostat object at the specified index
  selectedTemperature = &thermostat[index];

  // Print a confirmation message to the console
  cout << "Temperature 

