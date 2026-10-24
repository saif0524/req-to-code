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

void DisplayThermostats();
void SelectThermostat(int selectedThermostat);
void SelectTemperature(int selectedTemperature);

void DisplayThermostats() {
  // Display the available thermostats and their individual current temperature settings.
  std::map<std::string, int> thermostatsMap;
  for (int i = 0; i < thermostats.size(); i++) {
    thermostatsMap[std::to_string(i)] = thermostats[i];
  }
  return thermostatsMap;
}

void SelectThermostat(int selectedThermostat) {
   // Display the available thermostats and their individual current temperature settings.
   DisplayThermostats();

   // Select the selectedThermostat from the list of available thermostats.
   // This function should validate if selectedThermostat is within the range of available thermostats.
   if (selectedThermostat < 0 || selectedThermostat >= thermostats.size()) {
     // Handle invalid selection
     return;
   }

   // Save the selectedThermostat
   currentThermostat = selectedThermostat;
}

void SelectTemperature(int selectedTemperature) {
   // Display the available thermostats and their individual current temperature settings.
   DisplayThermostats();

   // Validate if selectedTemperature is within the range of valid temperatures.
   if (selectedTemperature < minValidTemperature || selectedTemperature > maxValidTemperature) {
     // Handle invalid selection
     return;
   }

   // Save the selectedTemperature
   currentTemperature = selectedTemperature;

   // Return JSON with the selected temperature and the reason for the selection
   std::map<std::string, int> json = {
     {"selected_temperature", currentTemperature},
     {"reason", "Temperature selected successfully."}
   };
   return json;
}

void SelectTemperature(int selectedTemperature) {
   // Display the available thermostats and their individual current temperature settings.
   DisplayThermostats();

   // Validate if selectedTemperature is within the range of valid temperatures.
   if (selectedTemperature < minValidTemperature || selectedTemperature > maxValidTemperature) {
     // Handle invalid selection
     return;
   }

   // Save the selectedTemperature
   currentTemperature = selectedTemperature;

   // Return JSON with the selected temperature and the reason for the selection
   std::map<std::string, int> json = {
     {"selected_temperature", currentTemperature},
     {"reason", "Temperature selected successfully."}
   };
   return json;
}

