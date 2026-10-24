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

void check_temperature(int TSET, int TD, int UT, int T, int LO, int LT, int UO);

void check_temperature(int TSET, int TD, int UT, int T, int LO, int LT, int UO) {
  if (T < TSET - TD && T > UT) {
    // Turn on heating unit
    // Turn on cooling unit
  } else if (T < LT) {
    // Turn on heating unit
  } else if (T > UO) {
    // Turn on cooling unit
  } else if (T < LO) {
    // Turn on heating unit
  } else {
    // Turn on cooling unit
  }
}

