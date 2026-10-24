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

int load_heating_units(int max_units): int;
int load_max_heating_units(int max_units): int;
static int max_units;

static int max_units; // Declares any necessary variables or constants shared across functions.

int load_heating_units(int max_units): int \n  return max_units; // Reads the maximum number of heating or cooling units from the initialization file and returns it.

int load_max_heating_units(int max_units) {
  if (max_units < 0) {
    return load_heating_units(max_units);
  }
  return max_units;
  }

static int max_units; // Declares any necessary variables or constants shared across functions.

int load_max_heating_units(int max_units) {
  if (max_units < 0) {
    return load_heating_units(max_units);
  }
  return max_units;
  }

