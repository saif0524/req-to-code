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

[struct ThermostatData] // Data structure to hold temperature setting and current temperature

int isTemperatureSettingValid(int setting);
int isCurrentTemperatureValid(int temp);
bool determineOverallStatus(int setting, int temp);

int isTemperatureSettingValid(int setting) {
    if (setting >= 0 && setting <= 100) {
        return 1;
    } else {
        return 0;
    }
}

int isCurrentTemperatureValid(int temp) {
    if (temp < 0) {
        return 0;
    } else if (temp > 100) {
        return 0;
    } else {
        return 1;
    }
    }

bool determineOverallStatus(int setting, int temp) {
    return isTemperatureSettingValid(setting) && isCurrentTemperatureValid(temp);
    }

