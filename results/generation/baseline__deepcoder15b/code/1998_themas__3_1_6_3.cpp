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

double generate_hc_signal(double unit_value, string status);
string output_status(string unit_info);
string handle_status_change(string current_status, string new_status, string unit_info);

double generate_hc_signal(double unit_value, string status) {
  if (status == "ON") {
    return unit_value;
  } else {
    return 0.0;
  }
  }

string output_status(string unit_info) { 
  size_t status_pos = unit_info.find_last_of(

string handle_status_change(string current_status, string new_status, string unit_info) {
  if (current_status != new_status) {
    return "Change in status of unit ", unit_info, current_status, new_status, unit_info;
  }
  return string();
}

