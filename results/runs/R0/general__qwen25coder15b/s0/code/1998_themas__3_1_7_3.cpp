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

void detect_alarm(const std::string& alarm_type);
void record_alarm_event(const std::string& alarm_type);

void detect_alarm(const std::string& alarm_type) {
  switch (alarm_type) {
    case "temperature":
      record_alarm_event("temperature");
      break;
    case "temperature_limit":
      record_alarm_event("temperature_limit");
      break;
    default:
      // Handle invalid alarm type
      break;
  }
}

void record_alarm_event(const std::string& alarm_type) {
  // Log the alarm event in the system's log
  // Example: log_event(alarm_type);
}

