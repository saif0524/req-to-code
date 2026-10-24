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

void generate_event(const std::string& thermostat_id, const std::string& unit_id);

void generate_event(const std::string& thermostat_id, const std::string& unit_id) {
   // Create a new event with a description of the event type (a request denied event)
   std::string event_description = "Request denied event: Thermostat ID: " + thermostat_id + ", Unit ID: " + unit_id;
   // Create a new system event
   SystemEvent new_event(event_description);
   // Add the new event to the system event log
   system_event_log.push_back(new_event);
}

