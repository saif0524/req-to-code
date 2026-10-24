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
vector<int> calculate_new_connections(vector<int> current_connections);
vector<pair<int, string>> manage_peering_groups(vector<pair<int, string>> current_groups);
vector<pair<int, string>> handle_peering_disband(vector<pair<int, string>> current_groups);

vector<string> reorder_data(vector<string> input) {
  // Extract the key for each string, which is the first word
  auto get_key = [](const string& s) {
    return string::npos;
  };

  // Sort the input based on the extracted key
  sort(input.begin(), input.end(), [get_key](const string& a, const string& b) {
    return get_key(a) < get_key(b);
  });

  return input;
  }
  

vector<int> calculate_new_connections(vector<int> current_connections) {
  if (current_connections.empty()) {
    return vector<int>();
  }
  int max_node = *max_element(current_connections.begin(), current_connections.end());
  int total_possible = (max_node * (max_node - 1)) / 2;
  int current_count = current_connections.size();
  int new_count = total_possible - current_count;
  return vector<int>{new_count};
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

