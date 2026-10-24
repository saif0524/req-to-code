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

void initialize_system();
void read_temperature_values();
void read_temperature_settings();
void determine_heating_or_cooling_unit();
void turn_on_heating_or_cooling_unit();

void initialize_system() {
  // Turn off all units
  turn_off_all_units();

  // Read current temperature values and settings
  read_temperature_values();
  read_temperature_settings();

  // Determine if a heating or cooling unit needs to be turned on
  if (determine_heating_or_cooling_unit()) {
    // Issue a request to turn on the appropriate heating or cooling unit
    turn_on_heating_or_cooling_unit();
  }
}

void read_temperature_values() {
  // Iterate through the list of thermostats
  for (auto& thermostat : thermostats) {
    // Call the read_temperature_value function for each thermostat
    read_temperature_value(thermostat);
  }
}

void read_temperature_settings() {
  // Iterate through the list of thermostats
  for (auto& thermostat : thermostats) {
    // Call the read_temperature_value function for each thermostat
    read_temperature_value(thermostat);
  }
}

void determine_heating_or_cooling_unit() {
  // Iterate through the list of thermostats
  for (auto& thermostat : thermostats) {
    // Read the current temperature settings from the thermostat
    int current_temperature = read_temperature_value(thermostat);

    // Read the desired temperature settings for heating and cooling
    int desired_heating_temperature = get_desired_heating_temperature(thermostat);
    int desired_cooling_temperature = get_desired_cooling_temperature(thermostat);

    // Determine if a heating or cooling unit needs to be turned on
    if (current_temperature > desired_heating_temperature) {
      // Issue a request to turn on the appropriate heating unit
      turn_on_heating_unit(thermostat);
    } else if (current_temperature < desired_cooling_temperature) {
      // Issue a request to turn on the appropriate cooling unit
      turn_on_cooling_unit(thermostat);
    }
  }
}

void turn_on_heating_or_cooling_unit() {
  // Iterate through the list of thermostats
  for (auto& thermostat : thermostats) {
    // Read the current temperature settings from the thermostat
    int current_temperature = read_temperature_value(thermostat);

    // Read the desired temperature settings for heating and cooling
    int desired_heating_temperature = get_desired_heating_temperature(thermostat);
    int desired_cooling_temperature = get_desired_cooling_temperature(thermostat);

    // Determine if a heating or cooling unit needs to be turned on
    if (current_temperature > desired_heating_temperature) {
      // Issue a request to turn on the appropriate heating unit
      turn_on_heating_unit(thermostat);
    } else if (current_temperature < desired_cooling_temperature) {
      // Issue a request to turn on the appropriate cooling unit
      turn_on_cooling_unit(thermostat);
    }
  }
}

