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

std::string identify_event_type(const std::string& event_description);
std::string format_event_message(const std::string& event_type, const std::string& event_description, const std::string& current_time);
void record_event(const std::string& event_type, const std::string& event_description, const std::string& current_time);
std::string get_current_time();

std::string identify_event_type(const std::string& event_description) {
  if (event_description.find("error") != std::string::npos) {
    return "error";
  } else if (event_description.find("warning") != std::string::npos) {
    return "warning";
  } else if (event_description.find("information") != std::string::npos) {
    return "information";
  } else {
    return "unknown";
  }
}

std::string format_event_message(const std::string& event_type, const std::string& event_description, const std::string& current_time) {
  if (event_type == "error") {
    return "Error: " + event_description + " at " + current_time;
  } else if (event_type == "warning") {
    return "Warning: " + event_description + " at " + current_time;
  } else if (event_type == "information") {
    return "Information: " + event_description + " at " + current_time;
  } else {
    return "Unknown event: " + event_description + " at " + current_time;
  }
}

void record_event(const std::string& event_type, const std::string& event_description, const std::string& current_time) {
  std::string event_message = format_event_message(event_type, event_description, current_time);
  std::ofstream file("C:\\Users\\Username\\Documents\\EventLog.accdb", std::ios::app);
  if (file.is_open()) {
    file << event_message << std::endl;
    file.close();
  } else {
    std::cerr << "Error: Unable to open file" << std::endl;
  }
}

std::string get_current_time() {  using namespace std::chrono;  std::time_t current_time = system_clock::to_time_t(system_clock::now());  std::ofstream file(

