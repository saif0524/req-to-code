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

int current, int new;
bool saveChanges;
bool confirmToUnlock;

int new(int current) {
  if (new < 1 || new > 26) {
    return -1;
  }
  return new;
  }
  

bool saveChanges() {
  return true;
}

bool confirmToUnlock() {
  int newLang = new();
  if (newLang >= 1 && newLang <= 26) {
    return true;
  }
  return false;
}

