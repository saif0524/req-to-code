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

std::queue<int> unit_queue;

bool can_honor_request(int max_units, int current_units);
void add_to_queue(std::queue<int>& queue, int unit_id);
void generate_on_request(int unit_id);
void check_queue(std::queue<int>& queue, int thermostat_id);
void process_request(int request_type, int unit_id, int max_units, int current_units, std::queue<int>& queue, int thermostat_id);

bool can_honor_request(int max_units, int current_units) {
  return current_units < max_units;
}

bool add_to_queue(std::queue<int>& queue, int unit_id) { return queue.empty() || queue.size() < max_units; }

void generate_on_request(int unit_id) { process_request(1, unit_id, max_units, current_units, unit_queue, thermostat_id); }

void check_queue(std::queue<int>& queue, int thermostat_id) { return; }

void process_request(int request_type, int unit_id, int max_units, int current_units, std::queue<int>& queue, int thermostat_id) {
  if (request_type == 1) { // Turn on request
    if (can_honor_request(max_units, current_units)) {
      // Process the request directly
      // For example: turn_on_unit(unit_id);
    } else {
      add_to_queue(queue, unit_id);
    }
  } else if (request_type == 0) { // Turn off request
    check_queue(queue, thermostat_id);
  }
}

