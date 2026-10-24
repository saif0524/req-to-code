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

struct<info> get_entity_info(int entity_id);
void update_entity_info(int entity_id, vector<string> new_info);
bool validate_entity_info(int entity_id);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi);
void update_entity_info(int entity_id, vector<string> new_info);
void get_doi(int entity_id, vector<string> new_doi());

vector<string> get_doi(int entity_id);
void update_entity_info(int entity_id, vector<string> new_info);
bool validate_entity_info(int entity_id);

vector<string> get_doi(int entity_id) {
  vector<string> current_info = get_entity_info(entity_id);
  vector<string> dois;
  for (auto& info : current_info) {
    size_t pos = info.find(

vector<string> update_entity_info(int entity_id, vector<string> new_info) {
  vector<string> current_info = get_doi(entity_id);
  vector<string> updated_info(current_info.begin(), current_info.end());
  for (size_t i = 0; i < updated_info.size(); i++) {
    if (i < new_info.size()) {
      updated_info[i] = new_info[i];
    }
    else {
      updated_info[i] = string(1, ' '); // Handle new_info size if necessary
    }
  }
  return updated_info;
}

bool validate_entity_info(int entity_id) { vector<string> current_info = get_doi(entity_id); return current_info.empty(); }

