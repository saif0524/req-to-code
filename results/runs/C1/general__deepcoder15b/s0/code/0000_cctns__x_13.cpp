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

int user_id, int case_id, int access_level -> bool;
string event_type, string event_time, string event_date, string event_details -> void;
vector<event> list_of_events -> void;
int user_id, int case_id, string attempt_time -> bool;
vector<event> event_list -> void;

int check_user Denied Access(int user_id, int case_id, string attempt_time) {
    static int caseRequiredLevel = 2; // Set according to case's access requirements
    int userLevel = getUserAccessLevel(user_id);
    return userLevel < caseRequiredLevel;
}

vector<string> event_list_to_event_list(const vector<string>& events) {
  static vector<string> event_list;
  for (const auto& e : events) {
    event_list.push_back(e);
  }
  reverse(event_list.begin(), event_list.end());
  return event_list;
}

