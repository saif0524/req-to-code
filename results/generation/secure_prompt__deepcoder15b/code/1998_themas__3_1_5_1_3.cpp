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

int check_running_status(int unit_id) -> bool;
bool get_max_units_running(int max_count) -> bool;
void handle_turn_off_request(int unit_id, bool current_state, vector<int>& queue) -> void;
void submit_on_request(int unit_id, bool current_state) -> void;

int check_running_status(int unit_id) -> bool {
    // Assuming the system has a set or map to track running units
    // For example, if a global set 'running_units' is maintained, check if unit_id is in it
    return (running_units.count >= unit_id + 1);
    }
    // Note: This implementation is incomplete as it requires knowledge of how running_units is managed
    // The actual implementation would depend on the system's data structures and their initialization
    return false;
    

bool get_max_units_running(int max_count) -> bool {
  int count = 0;
  for (int i = 1; i <= max_count; i++) {
    if (check_running_status(i)) {
      count ++;
    }
  }
  return (count <= max_count);
  }
  

void handle_turn_off_request(int unit_id, bool current_state, vector<int>& queue) -> void {
  if (queue.find(unit_id) != queue.end()) {
    queue.erase(unit_id);
  }
  if (current_state) {
    if (queue.find(unit_id) != queue.end()) {
      queue.erase(unit_id);
    }
    if (!check_running_status(unit_id)) {
      submit_on_request(unit_id, current_state);
    }
    else {
      queue.erase(unit_id);
    }
  } else {
    if (queue.find(unit_id) != queue.end()) {
      queue.erase(unit_id);
    }
    if (!check_running_status(unit_id)) {
      submit_on_request(unit_id, current_state);
    }
    else {
      queue.erase(unit_id);
    }
  }
  }
  

void submit_on_request(int unit_id, bool current_state) -> void {
  if (check_running_status(unit_id)) {
    return; // Unit is already running, skip submission
  }
  if (!queue.empty()) {
    queue.erase(queue.begin() + queue.size() - 1);
  }
  if (current_state) {
    submit_on_request(unit_id, current_state);
  }
  }
  

