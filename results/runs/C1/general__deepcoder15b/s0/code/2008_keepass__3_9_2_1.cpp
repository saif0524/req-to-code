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

string search_input(string search);
vector<int> select_fields(const vector<string>& field_names);
void retrieve_results(string search, const vector<int>& field_indices, vector<vector<string>>& results);

vector<int> select_fields(const vector<string>& field_names) {
  vector<int> result;
  for (int i = 0; i < field_names.size(); i++) {
    result.push_back(i);
  }
  return result;
  }
  

void retrieve_results(string search, const vector<int>& field_indices, vector<vector<string>>& results) {
  vector<string> filtered_results;
  for (int i = 0; i < results.size(); i++) {
    if (field_indices[i] < results.size() && results[i][field_indices[i]] == search) {
      filtered_results.push_back({
        "field": field_indices[i],
        "value": results[i][field_indices[i]]
      });
    }
  }
  vector<string> result_json;
  for (const auto& item : filtered_results) {
    result_json.push_back({
      "field": item "field",
      "value": item "value"
    });
  }
  return result_json;
}

