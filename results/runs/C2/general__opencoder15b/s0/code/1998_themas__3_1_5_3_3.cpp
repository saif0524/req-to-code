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

std::map<std::string, bool> status_map;

void send_heating_request(const std::string& unit_id, bool is_on);
void receive_heating_request(const std::string& unit_id, bool is_on);
void process_heating_request(const std::string& unit_id, bool is_on);
std::string get_heating_status(const std::string& unit_id);
void set_heating_status(const std::string& unit_id, bool is_on);

void send_heating_request(const std::string& unit_id, bool is_on) {
    // Implementation of handling the incoming request to turn on or off a heating or cooling unit
    receive_heating_request(unit_id, is_on);
}

void receive_heating_request(const std::string& unit_id, bool is_on) {
    process_heating_request(unit_id, is_on);
    send_heating_request(unit_id, is_on);
}

void process_heating_request(const std::string& unit_id, bool is_on) {
    // Implementation of handling the incoming request to turn on or off a heating or cooling unit
    receive_heating_request(unit_id, is_on);
}

std::string get_heating_status(const std::string& unit_id) {
    if (status_map.find(unit_id) != status_map.end()) {
        return std::to_string(status_map[unit_id]);
    } else {
        return "Unit not found";
    }
}

void set_heating_status(const std::string& unit_id, bool is_on) {
     // Implementation of setting the status of a heating or cooling unit
     if (status_map.find(unit_id) != status_map.end()) {
         status_map[unit_id] = is_on;
     } else {
         status_map[unit_id] = is_on;
     }
}

