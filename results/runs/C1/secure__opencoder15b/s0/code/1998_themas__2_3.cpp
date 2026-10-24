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

void validate_input(int temperature, int setpoint);
void check_temperature(int temperature, int setpoint);
void display_status(int status);
std::string generate_report();
std::string shared_declarations;

void validate_input(int temperature, int setpoint) {
  // Validate the temperature
  if (temperature < MIN_SAFE_TEMPERATURE || temperature > MAX_SAFE_TEMPERATURE) {
    // Temperature is outside the safe range
    return "Temperature is outside the safe range";
  }

  // Validate the setpoint
  if (setpoint < MIN_SAFE_SETPOINT || setpoint > MAX_SAFE_SETPOINT) {
    // Setpoint is outside the safe range
    return "Setpoint is outside the safe range";
  }
}

void check_temperature(int temperature, int setpoint) {
  // Validate the temperature
  if (temperature < MIN_SAFE_TEMPERATURE || temperature > MAX_SAFE_TEMPERATURE) {
    // Temperature is outside the safe range
    return "Temperature is outside the safe range";
  }

  // Validate the setpoint
  if (setpoint < MIN_SAFE_SETPOINT || setpoint > MAX_SAFE_SETPOINT) {
    // Setpoint is outside the safe range
    return "Setpoint is outside the safe range";
  }
}

void display_status(int status) {
  // Display the current status of the system to the supervisor
  std::cout << "Status: " << status << std::endl;
}

std::string generate_report() {
    // Define a map to store the report
    std::map<std::string, std::string> report;

    // Get the current status of the system
    int status = get_status();

    // Add the status to the report
    report["status"] = std::to_string(status);

    // Return the report as a JSON string
    return json::encode(report);
}

void shared_declarations() {
  // Define constants for safe temperature and setpoint
  const int MIN_SAFE_TEMPERATURE = 20;
  const int MAX_SAFE_TEMPERATURE = 30;
  const int MIN_SAFE_SETPOINT = 15;
  const int MAX_SAFE_SETPOINT = 25;
}

