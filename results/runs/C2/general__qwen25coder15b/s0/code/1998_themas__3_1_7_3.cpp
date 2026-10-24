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
  int alarm_type_int = std::stoi(alarm_type);
  switch (alarm_type_int) {
    case 0:
      record_alarm_event("temperature");
      break;
    case 1:
      record_alarm_event("temperature_limit");
      break;
    default:
      // Handle invalid alarm type
      break;
  }
}

