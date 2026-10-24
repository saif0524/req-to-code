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

bool check_system_availability(const std::string& start_time, const std::string& end_time, const std::string& weekdays, const std::string& days_per_year, const std::string& downtime_limit, const std::string& unplanned_downtime_limit, const std::string& incident_limit, const std::string& restore_time);
void update_system_status(bool is_available);
void handle_system_failure(const std::string& failure_type, const std::string& failure_details);

bool check_system_availability(const std::string& start_time, const std::string& end_time, const std::string& weekdays, const std::string& days_per_year, const std::string& downtime_limit, const std::string& unplanned_downtime_limit, const std::string& incident_limit, const std::string& restore_time) {
  // Check if the system is available based on the given time and availability rules
  bool is_available = true;

  // Check if the planned downtime for the system exceeds the specified limit
  if (is_available && planned_downtime > downtime_limit) {
    log_system_event("Planned downtime exceeded", "Planned downtime: " + planned_downtime + " hours, Limit: " + downtime_limit + " hours");
    is_available = false;
  }

  // Check if the unplanned downtime for the system exceeds the specified limit
  if (is_available && unplanned_downtime > unplanned_downtime_limit) {
    log_system_event("Unplanned downtime exceeded", "Unplanned downtime: " + unplanned_downtime + " hours, Limit: " + unplanned_downtime_limit + " hours");
    is_available = false;
  }

  // Check if the number of incidents of unplanned downtime for the system exceeds the specified limit
  if (is_available && incidents > incident_limit) {
    log_system_event("Incident limit exceeded", "Incidents: " + incidents + " per rolling three month period, Limit: " + incident_limit + " incidents");
    is_available = false;
  }

  // Check if the system is down based on the availability check
  if (is_available && !is_system_available(start_time, end_time, weekdays, days_per_year)) {
    log_system_event("System down", "System is not available from " + start_time + " to " + end_time + ", on weekdays: " + weekdays + ", days per year: " + days_per_year);
    is_available = false;
  }

  return is_available;
}

void update_system_status(bool is_available) {
  if (!is_available) {
    log_system_event("System down", "System is not available from 

void handle_system_failure(const std::string& failure_type, const std::string& failure_details) {
  if (!is_system_available(start_time, end_time, weekdays, days_per_year)) {
    log_system_event("System down", "System is not available from " + start_time + " to " + end_time + ", on weekdays: " + weekdays + ", days per year: " + days_per_year);
    restore_system(failure_type, failure_details);
  }
}

void restore_system(const std::string& failure_type, const std::string& failure_details) {
  if (!is_system_available(start_time, end_time, weekdays, days_per_year)) {
    log_system_event("System down", "System is not available from " + start_time + " to " + end_time + ", on weekdays: " + weekdays + ", days per year: " + days_per_year);
    restore_system(failure_type, failure_details);
  }
}

