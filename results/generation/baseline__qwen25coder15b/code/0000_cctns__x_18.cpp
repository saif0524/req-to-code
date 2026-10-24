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

void handle_unplanned_downtime(const std::string& current_time) {
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

