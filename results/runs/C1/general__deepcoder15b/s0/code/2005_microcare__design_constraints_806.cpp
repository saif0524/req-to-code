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

bool check_id_exists(int id, unordered_set<int> &id_set);
void add_id(int id, unordered_set<int> &id_set);
void add_name(string name, unordered_set<int> &name_set);
bool check_name_exists(string name, unordered_set<int> &name_set, unordered_set<int> &id_set);
void displayWarning(string name, unordered_set<int> &name_set);

bool check_id_exists(int id, unordered_set<int> &id_set) {
  unordered_set<int> id_set_other; 
  bool exists = false;
  for (int element : id_set_other) {
    if (element == id) {
      exists = true;
      break;
    }
  }
  return exists;
  }
  

void add_id(int id, unordered_set<int> &id_set) {
  for (int element : id_set) {
    if (element == id) {
      return;
    }
    id_set.insert(id);
  }
  }

void add_name(std::string name, std::unordered_set<int> &name_set) {
  for (int element : name_set) {
    if (element == name) {
      continue;
    }
  }
  if (name_set.empty()) {
    name_set.insert(name);
  }
}

bool check_name_exists(string name, unordered_set<int> &name_set) {
  for (int element : name_set) {
    if (element == name) {
      return true; // Name exists in the map
    }
  }
  return false; // Name does not exist in the map
  }

void displayWarning(string name, unordered_set<int> &name_set) {
    for (int i = 0; i < name_set.size(); i++) {
        if (name_set[i] == name) {
            // Return a message indicating the warning
            return "Warning: Duplicate name found in the name set for {price}";
        }
    }
}

