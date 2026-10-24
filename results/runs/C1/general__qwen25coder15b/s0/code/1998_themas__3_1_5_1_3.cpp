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

using HeatingCoolingUnit = /* define your struct or enum here */;
using submit_request_to_system = /* define your function here */;
using submit_request_to_lifo_queue = /* define your function here */;

bool is_max_units_running();
void add_to_queue(const HeatingCoolingUnit& unit);
void submit_request(const HeatingCoolingUnit& unit);
void process_queue();

bool is_max_units_running() {
  // Check if the maximum number of heating or cooling units is already running
  return max_units_running;
}

void add_to_queue(const HeatingCoolingUnit& unit) {
  // Add a heating or cooling unit request to the LIFO queue
  if (!is_max_units_running()) {
    queue.push(unit);
  } else {
    add_to_queue_to_lifo_queue(unit);
  }
}

void submit_request(const HeatingCoolingUnit& unit) {
  // Submit a request to turn on a heating or cooling unit
  if (!is_max_units_running()) {
    submit_request_to_system(unit);
  } else {
    submit_request_to_lifo_queue(unit);
  }
}

void process_queue() {
  // Check the queue of waiting heating and cooling requests and submit requests as needed
  while (!queue.empty()) {
    HeatingCoolingUnit unit = queue.front();
    queue.pop();
    if (unit.thermostat_needs_heating_or_cooling()) {
      submit_request_to_system(unit);
    } else {
      submit_request_to_lifo_queue(unit);
    }
  }
}

void add_to_queue(const HeatingCoolingUnit& unit) {
  if (!is_max_units_running()) {
    queue.push(unit);
  } else {
    add_to_queue_to_lifo_queue(unit);
  }
}

void submit_request(const HeatingCoolingUnit& unit) {
  if (!is_max_units_running()) {
    submit_request_to_system(unit);
  } else {
    add_to_queue_to_lifo_queue(unit);
  }
}

void process_queue() {
  using HeatingCoolingUnit = /* define your struct or enum here */;
  using submit_request_to_system = /* define your function here */;
  using submit_request_to_lifo_queue = /* define your function here */;

  while (!queue.empty()) {
    HeatingCoolingUnit unit = queue.front();
    queue.pop();
    if (unit.thermostat_needs_heating_or_cooling()) {
      submit_request_to_system(unit);
    } else {
      submit_request_to_lifo_queue(unit);
    }
  }
}

