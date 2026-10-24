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

None added or needed

double get_heating_state() -> bool;
int get_heating_state(), bool get_is_tooth_on() -> void, double get_temperature() -> double;

static bool get_heating_state() { static bool is_heating_off = true; return !current_heating_temp < desired_heating_temp; }

bool get_heating_state() -> bool { static double current_heating_temp = 22.0; static bool is_heating_off = true; return !is_heating_off; }

