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

vector<string> reorder_data(vector<string> input);
vector<pair<int, string>> manage_peering_groups(vector<pair<int, string>> current_groups);
vector<pair<int, string>> handle_peering_disband(vector<pair<int, string>> current_groups);

vector<string> reorder_data(vector<string> input) {
  // Extract the key for each string, which is the first word
  auto get_key = [](const string& s) {
    size_t space_pos = s.find('');
    if (space_pos == string::npos) return s;
    return s.substr(0, space_pos);
  };

  // Sort the input based on the extracted key
  sort(input.begin(), input.end(), [](const string& a, const string& b) {
    return get_key(a) < get_key(b);
  });

  return input;
  }

vector<pair<int, string>> manage_peering_groups(vector<pair<int, string>> current_groups) {
    sort(current_groups.begin(), current_groups.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first;
    });
    return current_groups;
    }

vector<pair<int, string>> handle_peering_disband(vector<pair<int, string>> current_groups) {
    sort(current_groups.begin(), current_groups.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    });
    return current_groups;
    }

