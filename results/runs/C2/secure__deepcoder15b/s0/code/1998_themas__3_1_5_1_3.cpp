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
void submit_off_request(int unit_id, bool current_state, vector<int>& queue) -> void;

bool check_running_status(int unit_id) -> bool {
  return (running_units.count >= unit_id + 1);
  }

bool get_max_units_running(int max_count) -> bool {
  if (max_count <= 0) {
    return false;
  }
  int count = 0;
  for (int i = 1; i <= max_count; ++i) {
    if (check_running_status(i)) {
      count ++;
    }
  }
  return count <= max_count;
  }
  "reasoning": "The function now correctly handles cases where max_count is zero or negative by returning false. It counts the units from 1 to max_count and returns whether the count is within the allowed maximum.",
  

void handle_turn_off_request(int unit_id, bool current_state, vector<int>& queue) -> bool {
  if (!queue.empty()) {
    queue.pop_front();
  }
  return true; // Assuming the request was processed, return true
  }

void submit_on_request(int unit_id, bool current_state) -> void {
  if (!check_running_status(unit_id)) {
    if (!queue.empty()) {
      queue.erase(queue.begin() + queue.size() - 1);
    }
    return;
  }
  return;
}

void submit_off_request(int unit_id, bool current_state, vector<int>& queue) -> void {
  if (queue.empty()) {
    queue.push_back(unit_id);
  } else {
    queue.pop_front();
  }
  }
  

