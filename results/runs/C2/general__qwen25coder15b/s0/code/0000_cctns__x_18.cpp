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

struct tm;

void set_system_availability(const std::string& start_time, const std::string& end_time, const std::vector<std::string>& weekdays, int planned_downtime, int unplanned_downtime, int max_incidents, int max_unplanned_downtime, int max_software_failure_time);
bool check_system_availability(const std::string& current_time);
void handle_unplanned_downtime(const std::string& current_time);
void restore_system(const std::string& current_time);

void set_system_availability(const std::string& start_time, const std::string& end_time, const std::vector<std::string>& weekdays, int planned_downtime, int unplanned_downtime, int max_incidents, int max_unplanned_downtime, int max_software_failure_time) {
  if (!check_system_availability(start_time, end_time, weekdays)) {
    handle_unplanned_downtime(start_time);
  }
  if (is_system_down()) {
    restore_system(start_time);
  }
}

bool is_system_down() {
  // Implementation details depend on the specific system and its restoration process
}

void restore_system(const std::string& current_time) {
  std::time_t current_time_t = std::time(nullptr);
  std::tm current_time_tm = *std::localtime(&current_time_t);

  int current_hour = current_time_tm.tm_hour;
  int current_minute = current_time_tm.tm_min;

  int start_hour = std::stoi(start_time.substr(0, 2));
  int start_minute = std::stoi(start_time.substr(2, 2));
  int end_hour = std::stoi(end_time.substr(0, 2));
  int end_minute = std::stoi(end_time.substr(2, 2));

  if (current_hour < start_hour || (current_hour == start_hour && current_minute < start_minute)) {
    return;
  }

  if (current_hour > end_hour || (current_hour == end_hour && current_minute > end_minute)) {
    return;
  }

  // Restore the system within the allowed time frame
  // Implementation details depend on the specific system and its restoration process
}

struct tm {
  int tm_sec;  // seconds (0-59)
  int tm_min;  // minutes (0-59)
  int tm_hour;  // hours (0-23)
  int tm_mday;  // day of the month (1-31)
  int tm_mon;   // month (0-11)
  int tm_year;  // year (since 1900)
  int tm_wday;  // day of the week (0-6, Sunday is 0)
  int tm_yday;  // day of the year (0-365)
  int tm_isdst; // daylight saving time flag
};

bool check_system_availability(const std::string& current_time) {
  std::time_t current_time_t = std::time(nullptr);
  std::tm current_time_tm = *std::localtime(&current_time_t);

  int current_hour = current_time_tm.tm_hour;
  int current_minute = current_time_tm.tm_min;

  int start_hour = std::stoi(start_time.substr(0, 2));
  int start_minute = std::stoi(start_time.substr(2, 2));
  int end_hour = std::stoi(end_time.substr(0, 2));
  int end_minute = std::stoi(end_time.substr(2, 2));

  if (current_hour < start_hour || (current_hour == start_hour && current_minute < start_minute)) {
    return false;
  }

  if (current_hour > end_hour || (current_hour == end_hour && current_minute > end_minute)) {
    return false;
  }

  return true;
}

void handle_unplanned_downtime(const std::string& current_time, const std::string& start_time, const std::string& end_time) {
  std::time_t current_time_t = std::time(nullptr);
  std::tm current_time_tm = *std::localtime(&current_time_t);

  int current_hour = current_time_tm.tm_hour;
  int current_minute = current_time_tm.tm_min;

  int start_hour = std::stoi(start_time.substr(0, 2));
  int start_minute = std::stoi(start_time.substr(2, 2));
  int end_hour = std::stoi(end_time.substr(0, 2));
  int end_minute = std::stoi(end_time.substr(2, 2));

  if (current_hour < start_hour || (current_hour == start_hour && current_minute < start_minute)) {
    return false;
  }

  if (current_hour > end_hour || (current_hour == end_hour && current_minute > end_minute)) {
    return false;
  }

  return true;
}

void restore_system(const std::string& current_time) {
  using namespace std;

  std::time_t current_time_t = std::time(nullptr);
  std::tm current_time_tm = *std::localtime(&current_time_t);

  int current_hour = current_time_tm.tm_hour;
  int current_minute = current_time_tm.tm_min;

  int start_hour = std::stoi(start_time.substr(0, 2));
  int start_minute = std::stoi(start_time.substr(2, 2));
  int end_hour = std::stoi(end_time.substr(0, 2));
  int end_minute = std::stoi(end_time.substr(2, 2));

  if (current_hour < start_hour || (current_hour == start_hour && current_minute < start_minute)) {
    return;
  }

  if (current_hour > end_hour || (current_hour == end_hour && current_minute > end_minute)) {
    return;
  }

  // Restore the system within the allowed time frame
}

