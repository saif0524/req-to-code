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

int set_status_on(bool is_on);
int set_status_off(bool is_off);
void handle_observing_status(bool is_observing);

int set_status_on(bool is_on) {
  int status = 0;
  if (is_on) {
    status = 1;
  }
  return 1;
  }

int set_status_off(bool is_off) {
  return is_off ? 0 : 1;
  }

int handle_observing_status(bool is_observing) {
  if (is_observing) {
    return 1 - status;
  }
  return status;
  }

