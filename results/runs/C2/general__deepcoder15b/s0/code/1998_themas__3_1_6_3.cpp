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
  // Parse unit_info to extract unit_id and current_status
  string unit_id, current_status;
  vector<string> parts;
  regex_re them(unit_info, ':');
  while (them.match"){\nparts.push_back them.str());\n}\nunit_id = parts[0];
  current_status = parts[1];
  // Construct the output string
  return "Current status of unit " + unit_id + " is " + current_status + ";\n}

string handle_status_change(string current_status, string new_status, string unit_info) {
  if (current_status != new_status) {
    return "Change in status of unit ", unit_info, current_status, new_status, unit_info;
  }
  return string();
}

