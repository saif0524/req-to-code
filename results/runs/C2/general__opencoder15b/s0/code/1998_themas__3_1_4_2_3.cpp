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
  if (T < LT) {
    // The current temperature is below the lower trigger value
    processRequest(TSET, TD, T, UT, LO, LT, UO);
  } else if (T > UO) {
    // The current temperature is above the upper trigger value
    processRequest(TSET, TD, T, UT, LO, LT, UO);
  } else {
    // The current temperature is within the range of the lower and upper trigger values
    if (T < TSET) {
      // The current temperature is below the set temperature
      processRequest(TSET, TD, T, UT, LO, LT, UO);
    } else {
      // The current temperature is above the set temperature
      processRequest(TSET, TD, T, UT, LO, LT, UO);
    }
  }
}

void processRequest(int TSET, int TD, int T, int UT, int LO, int LT, int UO) {
  if (T < LT) {
    // The current temperature is below the lower trigger value
    processRequest(TSET, TD, T, UT, LO, LT, UO);
  } else if (T > UO) {
    // The current temperature is above the upper trigger value
    processRequest(TSET, TD, T, UT, LO, LT, UO);
  } else {
    // The current temperature is within the range of the lower and upper trigger values
    if (T < TSET) {
      // The current temperature is below the set temperature
      processRequest(TSET, TD, T, UT, LO, LT, UO);
    } else {
      // The current temperature is above the set temperature
      processRequest(TSET, TD, T, UT, LO, LT, UO);
    }
  }
}

