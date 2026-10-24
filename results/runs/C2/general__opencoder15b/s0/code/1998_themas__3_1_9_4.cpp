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

void displayThermostats() {
    // Get the list of available thermostats
    std::vector<std::string> thermostats = getThermostats();

    // Get the list of valid temperatures
    std::vector<int> temperatures = getValidTemperatures();

    // Display the available thermostats and their individual current temperature settings
    for (int i = 0; i < thermostats.size(); i++) {
     std::cout << "Thermostat: " << thermostats[i] << " Current Temperature: " << temperatures[i] << std::endl;
    }
}

