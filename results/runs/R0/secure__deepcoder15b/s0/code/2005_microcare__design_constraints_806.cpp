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

vector<int> ids -> bool, int?
    : Find the first duplicate ID in the vector and return its index.
    : Initialize an empty set to track seen IDs.
    : Loop through each element in ids with its index.
    : For each element, check if it's in the set.
    : If it is, return the current index as the duplicate index.
    : If it's not, add it to the set.
    : If no duplicates found after checking all elements, return false.

bool stringNameAllowed(string name) {
  static set<string> allowed = {"allowed1", "allowed2"};
  return (allowed.find(name) != set::npos);
}

bool function(int id, string name) {
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
  set<string> names;
  names.insert(name);
  return true;
  }

