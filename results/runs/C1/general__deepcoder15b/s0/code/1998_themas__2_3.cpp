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

string current_status(string status);
void status_update(bool is_system_operating);
void safetyWarning(int temperature);
void efficiency_check(int energy_usage, int time);
void report_generation(string time, string temperature);

std::string status_update(std::bool_ is_system_operating) {
  if (is_system_operating) {
    return "System is operating: current status";
  } else {
    return "System is not operating: current status";
  }
  }

std::string safetyWarning(int temperature) {
  const int _threshold = 5; // Threshold below which a warning is generated
  if (temperature < _threshold) {
    return std::string(std::to_string(temperature) + " below the threshold, need recalibration);\n}\nreturn "No temperature below threshold, system is operational";\n}
  

std::string efficiency_check(int energy_usage, int time) {
    double efficiency = energy_usage / time;
    if (efficiency >= 0.8) {
        return "System efficiency: High, current status: System is operating";
    } else {
        return "System efficiency: Low, current status: System is not operating";
    }
    }

