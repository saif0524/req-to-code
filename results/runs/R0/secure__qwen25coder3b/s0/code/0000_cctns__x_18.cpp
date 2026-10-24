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

bool check_availability(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& planned_downtime, const std::string& unplanned_downtime, const std::string& incidents, const std::string& restoration_time) {
  // Validate input parameters
  if (start_time.empty() || end_time.empty() || days.empty() || planned_downtime.empty() || unplanned_downtime.empty() || incidents.empty() || restoration_time.empty()) {
    return false;
  }

  // Calculate total planned downtime
  int planned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, planned_downtime);

  // Calculate total unplanned downtime
  int unplanned_downtime_hours = calculate_downtime_hours(start_time, end_time, days, unplanned_downtime);

  // Check if total downtime exceeds planned downtime limit
  if (planned_downtime_hours > planned_downtime) {
    return false;
  }

  // Check if total downtime exceeds unplanned downtime limit
  if (unplanned_downtime_hours > unplanned_downtime) {
    return false;
  }

  // Check if number of incidents exceeds limit
  if (std::stoi(incidents) > 10) {
    return false;
  }

  return true;
}

int calculate_downtime_hours(const std::string& start_time, const std::string& end_time, const std::string& days, const std::string& downtime) {
  // Parse start and end times
  std::tm start_tm = {}, end_tm = {};
  std::istringstream(start_time) >> std::get_time(&start_tm, "%H:%M");
  std::istringstream(end_time) >> std::get_time(&end_tm, "%H:%M");

  // Calculate total downtime hours
  int total_downtime_hours = 0;
  for (const char& day : days) {
    if (day == 'M' || day == 'T' || day == 'W' || day == 'R' || day == 'F') {
      total_downtime_hours += (end_tm.tm_hour - start_tm.tm_hour) * 24 + (end_tm.tm_min - start_tm.tm_min);
    }
  }

  return total_downtime_hours;
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

bool validate_downtime(const std::string& downtime) {
  // Parse downtime as an integer
  int total_downtime_hours = std::stoi(downtime);

  // Check if total downtime exceeds planned downtime limit
  if (total_downtime_hours > planned_downtime) {
    return false;
  }

  // Check if total downtime exceeds unplanned downtime limit
  if (total_downtime_hours > unplanned_downtime) {
    return false;
  }

  // Check if number of incidents exceeds limit
  if (std::stoi(incidents) > 10) {
    return false;
  }

  return true;
}

bool check_restoration_time(const std::string& restoration_time) {
  // Validate input parameters
  if (restoration_time.empty()) {
    return false;
  }

  // Parse restoration time
  std::tm restoration_tm = {};
  std::istringstream(restoration_time) >> std::get_time(&restoration_tm, "%H:%M");

  // Check if restoration time is valid
  if (std::tm::mktime(&restoration_tm) == -1) {
    return false;
  }

  // Check if restoration time is within the allowed range
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

