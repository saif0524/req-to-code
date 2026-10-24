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

double get_current_temp(double selected_thermostat);
double check_unit_status(double selected_unit);
void generate_event(double current_temp, double selected_thermostat, double selected_unit);

double get_current_temp(double selected_thermostat) {
    return selected_thermostat;
}

double check_unit_status(double selected_unit) {
    return !is_unit_running(selected_unit);
}

void generate_event(double current_temp, double selected_thermostat, double selected_unit) {
  struct event {
    string description;
    int selected_thermostat;
    bool unit_not_running;
  } event;
  event event_info = {
    to_string(current_temp),
    (int)selected_thermostat,
    !is_unit_running(selected_unit)
  };
  return event_info;
  }
  "reasoning" : [

