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

void check_temperature(double temperature, double set_temperature, double over_temperature_limit, double operating_days);

int check_temperature(double temperature, double set_temperature, double over_temperature_limit, double operating_days) {
    double difference = temperature - set_temperature;
    if (difference > over_temperature_limit) {
     return 1;
    } else {
     return 0;
    }
}

