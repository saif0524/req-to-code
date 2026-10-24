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

vector<int> ids -> bool, int?;
string name -> bool;
int id, string name -> bool;
void;

bool check_for_duplicated_ids(const std::vector<int>& ids) {
  if (ids.empty()) {
    return false;
  }

  std::set<int> seen;
  for (size_t i = 0; i < ids.size(); ++i) {
    int id = ids[i];
    if (id == std::numeric_limits<int>::max() + 1 || id == std::numeric_limits<int>::min() - 1) {
      return false;
    }
    if (seen.find(id) != seen.end()) {
      return i;
    } else {
      seen.insert(id);
    }
  }
  return false;
  }

  

bool stringNameAllowed(string name) {
  static const set<string> allowed = {"allowed1", "allowed2"};
  return (allowed.find(name) != set::npos);
  }

bool function(int id) {
  if (!stringNameAllowed(name)) {
    return false;
  }
  set<string> names;
  if (names.find(name) != names.end()) {
    return true;
  }
  names.insert(name);
  return false;
}

void includeDifferentiatingIndicator(int id, string name) {
  if (!stringNameAllowed(name)) {
    return false;
  }
  if (id != names[0]) {
    return true;
  }
  return false;
  }

