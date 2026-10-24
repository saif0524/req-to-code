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

struct<info> get_entity_info(int entity_id)
struct<info> retrieve_entity_info(int entity_id)

void update_entity_info(int entity_id, vector<string> new_info);
bool validate_entity_info(int entity_id);

vector<string> update_entity_info(int entity_id, vector<string> new_info) {
  vector<string> current_info = get_doi(entity_id);
  vector<string> updated_info(current_info.begin(), current_info.end());
  for (size_t i = 0; i < current_info.size(); i++) {
    updated_info[i] = new_info[i];
  }
  return updated_info;
}

bool validate_entity_info(int entity_id) {
  vector<string> current_info = get_doi(entity_id);
  // Assuming expected_values is a predefined vector<string> that contains the expected information
  // For example, if expected_values is {

