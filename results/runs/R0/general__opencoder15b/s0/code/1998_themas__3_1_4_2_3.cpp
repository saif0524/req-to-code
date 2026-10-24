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

void checkConditions(int TSET, int TD, int T, int UT, int LO, int LT, int UO);
void processRequest(int TSET, int TD, int T, int UT, int LO, int LT, int UO);

void checkConditions(int TSET, int TD, int T, int UT, int LO, int LT, int UO) {
  if (T >= TSET - TD && T <= TSET + TD) {
    // The current temperature is satisfied
    // Output request to turn off both heating and cooling units
  } else {
    if (T > UT) {
      // The temperature is above the upper trigger value
      // Output request to turn on the heating unit if LO is true
    } else if (T < LT) {
      // The temperature is below the lower trigger value
      // Output request to turn on the cooling unit if UT is true
    }
  }
}

void processRequest(int TSET, int TD, int T, int UT, int LO, int LT, int UO) {
  if (T >= TSET - TD && T <= TSET + TD) {
    // The current temperature is satisfied
    // Output request to turn off both heating and cooling units
  } else {
    if (T > UT) {
      // The temperature is above the upper trigger value
      // Output request to turn on the heating unit if LO is true
    } else if (T < LT) {
      // The temperature is below the lower trigger value
      // Output request to turn on the cooling unit if UT is true
    }
  }
}

