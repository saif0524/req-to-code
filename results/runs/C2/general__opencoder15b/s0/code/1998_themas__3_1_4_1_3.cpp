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

void checkTemperature(int temperature, int setTemperature, int overTempValue, int overTempLimit);

void checkTemperature(int temperature, int setTemperature, int overTempValue, int overTempLimit) {
    int LO = setTemperature - overTempValue;
    int UO = setTemperature + overTempValue;

    if (temperature > LO && temperature < UO) {
        // Temperature is within the set temperature range
        std::cout << "Temperature is within the set temperature range.";
    } else if (temperature <= LO) {
        // Temperature is lower than the lower limit
        std::cout << "Temperature is lower than the lower limit.";
    } else if (temperature >= UO) {
        // Temperature is higher than the upper limit
        std::cout << "Temperature is higher than the upper limit.";
    } else {
        // Temperature is within the over temperature limit
        std::cout << "Temperature limit has been exceeded.";
    }
}

