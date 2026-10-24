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

void createGroup(const std::string& name, Group& parentGroup);
void createSubgroup(const std::string& name, Group& parentGroup);
void addEntryToSubgroup(const std::string& entryName, Group& subgroup);

void createGroup(const std::string& name, Group& parentGroup) {
  createGroup(name);
  addEntryToGroup(name, parentGroup);
}

void createSubgroup(const std::string& name, Group& parentGroup) {
  Group newGroup(name);
  addEntryToGroup(name, newGroup);
}

void addEntryToSubgroup(const std::string& entryName, Group& subgroup) {
  createEntry(entryName);
  addEntryToGroup(entryName, subgroup);
}

