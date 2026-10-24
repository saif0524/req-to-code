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

bool initialize_active_tab(const bool &is_app_running);
void switch_tab(int tab_id);
std::vector<UserData> get_user_data() const;

bool initialize_active_tab(const bool &is_app_running) {
  return is_app_running;
  }

void switch_tab(int tab_id) {
  bool should_switch = initialize_active_tab();
  if (should_switch) {
    switch_tab(0);
  } else {
    switch_tab(1);
  }
  return;
  }
  "reasoning": [
    "1. Call initialize_active_tab() to determine if the current tab should be active"
    "2. Based on the result, call switch_tab with either 0 or 1"
    "3. Return"
    "4. This ensures the correct tab is active"
  ]

vector<UserData> get_user_data(int tab_id) const {
  bool is_active = initialize_active_tab(tab_id);
  if (is_active) {
    return active_data[tab_id];
  } else {
    return active_data[0];
  }
  return active_data[0];
  }
  "reasoning": [
    "1. Call initialize_active_tab with the given tab_id to determine if it's active.\n"2. If active, return the corresponding user data from active_data using tab_id.
    "3. If not active, return a default data (e.g., active_data[0]) as a fallback.\n"4. This ensures the correct data is retrieved based on the active tab"\n],\n

