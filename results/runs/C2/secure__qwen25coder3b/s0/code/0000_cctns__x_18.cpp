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

bool check_availability(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents, const std::string& restoration_time);
std::string calculate_downtime(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents, const std::string& restoration_time);
bool validate_downtime(const std::string& downtime);
bool check_restoration_time(const std::string& restoration_time);
bool check_incidents(const std::string& incidents);

int calculate_downtime_hours(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& downtime) {
  std::tm start_tm = {}, end_tm = {};
  std::istringstream(start_time) >> std::get_time(&start_tm, "%H:%M");
  std::istringstream(end_time) >> std::get_time(&end_tm, "%H:%M");

  int total_downtime_hours = 0;
  for (const char& day : days) {
    if (day == 'M' || day == 'T' || day == 'W' || day == 'R' || day == 'F') {
      total_downtime_hours += (end_tm.tm_hour - start_tm.tm_hour) * 24 + (end_tm.tm_min - start_tm.tm_min);
    }
  }

  return total_downtime_hours;
}

bool check_availability(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents, const std::string& restoration_time) {
  if (start_time.empty() || end_time.empty() || days.empty() || planned_downtime.empty() || unplanned_downtime.empty() || incidents.empty() || restoration_time.empty()) {
    return false;
  }

  int planned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, planned_downtime);
  int unplanned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, unplanned_downtime);

  if (planned_downtime_hours > planned_downtime) {
    return false;
  }

  if (unplanned_downtime_hours > unplanned_downtime) {
    return false;
  }

  if (std::stoi(incidents) > 10) {
    return false;
  }

  return true;
}

std::string calculate_downtime(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents, const std::string& restoration_time) {
  // Calculate total planned downtime hours
  int planned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, planned_downtime);

  // Calculate total unplanned downtime hours
  int unplanned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, unplanned_downtime);

  // Calculate total downtime hours
  int total_downtime_hours = planned_downtime_hours + unplanned_downtime_hours;

  // Return total downtime as a string
  return std::to_string(total_downtime_hours);
}

bool validate_downtime(const std::string& downtime, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents) {
  // Parse downtime as an integer
  int total_downtime_hours = std::stoi(downtime);

  // Check if total downtime exceeds planned downtime limit
  if (total_downtime_hours > std::stoi(planned_downtime)) {
    return false;
  }

  // Check if total downtime exceeds unplanned downtime limit
  if (total_downtime_hours > std::stoi(unplanned_downtime)) {
    return false;
  }

  // Check if number of incidents exceeds limit
  if (std::stoi(incidents) > 10) {
    return false;
  }

  return true;
}

bool check_restoration_time(const std::string& restoration_time) {
  if (restoration_time.empty()) {
    return false;
  }

  std::tm restoration_tm = {};
  std::istringstream(restoration_time) >> std::get_time(&restoration_tm, "%H:%M");

  if (std::mktime(&restoration_tm) == time_t(-1)) {
    return false;
  }

  if (restoration_tm.tm_hour < 0 || restoration_tm.tm_hour > 23 || restoration_tm.tm_min < 0 || restoration_tm.tm_min > 59) {
    return false;
  }

  return true;
}

bool check_incidents(const std::string& incidents) {
  // Validate input parameters
  if (incidents.empty()) {
    return false;
  }

  // Convert incidents to an integer
  int incident_count = std::stoi(incidents);

  // Check if incident count exceeds limit
  if (incident_count > 10) {
    return false;
  }

  return true;
}

