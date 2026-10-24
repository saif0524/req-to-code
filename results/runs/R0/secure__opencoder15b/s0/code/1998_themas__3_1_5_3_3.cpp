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

void send_heating_request(const std::string& unit_id, bool is_on);
void process_heating_request(const std::string& unit_id, bool is_on);
bool validate_heating_request(const std::string& unit_id, bool is_on);
void handle_heating_request(const std::string& unit_id, bool is_on);
std::string get_heating_request_response(const std::string& unit_id, bool is_on);

void send_heating_request(const std::string& unit_id, bool is_on) {
  // Implementation of sending a heating or cooling unit request.
}

void process_heating_request(const std::string& unit_id, bool is_on) {
   if (validate_heating_request(unit_id, is_on)) {
       handle_heating_request(unit_id, is_on);
   }
}

bool validate_heating_request(const std::string& unit_id, bool is_on) {
    if (unit_id.empty()) {
        return false;
    }
    if (is_on != true && is_on != false) {
        return false;
    }
    return true;
}

void handle_heating_request(const std::string& unit_id, bool is_on) {
    if (validate_heating_request(unit_id, is_on)) {
        // Implementation of turning on or off the heating or cooling unit.
    }
}

std::string get_heating_request_response(const std::string& unit_id, bool is_on) {
    if (validate_heating_request(unit_id, is_on)) {
        handle_heating_request(unit_id, is_on);
    }
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

