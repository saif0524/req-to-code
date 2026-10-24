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
void addEntryToGroup(const std::string& entryName, Group& group);
void addEntryToSubgroup(const std::string& entryName, Group& subgroup);

void createGroup(const std::string& name, Group& parentGroup) {
  Group newGroup(name);
  addEntryToGroup(name, newGroup);
}

void createSubgroup(const std::string& name, Group& parentGroup) {
  Group newGroup(name);
  addEntryToGroup(name, newGroup);
}

void addEntryToGroup(const std::string& entryName, Group& group) {
  createEntry(entryName);
  addEntryToGroup(entryName, group);
}

void addEntryToSubgroup(const std::string& entryName, Group& subgroup) {
  createEntry(entryName);
  addEntryToGroup(entryName, subgroup);
}

