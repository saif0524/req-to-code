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

bool detect_temperature(double temperature);
void generate_beeps(double frequency, int duration);
void record_alarm_event(const std::string& event);
void handle_alarm_request(double temperature);

bool detect_temperature(double temperature) {
  if (temperature < 0 || temperature > 100) {
    return false; // Temperature is invalid
  }
  return true; // Temperature is valid
}

void generate_beeps(double frequency, int duration) {
  if (!detect_temperature(frequency)) {
    std::cout << "Invalid frequency" << std::endl;
    return;
  }

  for (int i = 0; i < duration; i++) {
    std::cout << "Beep" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
  }
}

void record_alarm_event(const std::string& event) {
  // Open a file to write the alarm event
  std::ofstream file("alarm_events.txt", std::ios::app);

  // Write the alarm event to the file
  file << event << std::endl;

  // Close the file
  file.close();
}

void handle_alarm_request(double temperature) {
  if (!detect_temperature(temperature)) {
    generate_beeps(500, 300); // Invalid temperature, generate 500 Hz beeps for 300 ms
    record_alarm_event("Invalid temperature"); // Record the alarm event
  } else if (temperature > 100) {
    generate_beeps(1000, 1500); // Temperature limit exceeded, generate 1000 Hz beeps for 1500 ms
    record_alarm_event("Temperature limit exceeded"); // Record the alarm event
  } else {
    generate_beeps(500, 300); // Valid temperature, generate 500 Hz beeps for 300 ms
    record_alarm_event("Valid temperature"); // Record the alarm event
  }
}

