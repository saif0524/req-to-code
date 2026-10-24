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

bool check_id_exists(int id, unordered_set<int> &id_set) {
    bool exists = false;
    for (int element : id_set) {
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
      return; // ID already exists
    }
    id_set.insert(id);
  }
  }

void add_name(string name, unordered_set<int> &name_set) {
    for (int element : name_set) {
        if (element == name) {
            continue;
        }
    }
    if (name_set.empty()) {
        name_set.insert(name);
    }
}

bool check_name_exists(string name, unordered_set<int> &name_set, unordered_set<int> &id_set) {
  for (int element : name_set) {
    if (element == name) {
      return true; // Name exists in the map
    }
  }
  return false; // Name does not exist in the map
  }
  "reasoning": [
    "The function check_name_exists checks if a given name exists in the name_set.\n",
    "We loop through each element in name_set and compare it with the given name.\n",
    "If a match is found, the function returns true indicating the name exists.\n",
    "If no match is found after checking all elements, the function returns false indicating the name does not exist.\n"
  ],
  

