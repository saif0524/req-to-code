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

int handle_error(int errorCode): bool;
int manage_state(int state): bool;
int handle_input(int action): bool;

bool handle_error(int errorCode) {
  if (errorCode < 0 || errorCode > 1000) {
    return false;
  } else {
    return true;
  }
  }

int manage_state(int state): bool {
  if (state == null) {
    return false;
  }
  if (state < 1) {
    return false;
  }
  if (state > 1000) {
    return false;
  }
  return true;
  }
  

int handle_input(int action): bool {
  if (action < 0 || action > 1000) {
    return false; 
  } else {
    if (is_number(action)) {
      return true; 
    } else {
    } 
  }
  }

