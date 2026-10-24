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

void createGroup(const std::string& groupName, Group* parentGroup);
void addGroupToGroup(const std::string& groupName, Group* parentGroup, Group* subgroup);
void addEntryToGroup(const std::string& entryName, Group* group);

void createGroup(const std::string& groupName, Group* parentGroup) {
  Group* newGroup = new Group(groupName);
  parentGroup->addGroup(newGroup);
  return newGroup;
}

void addGroupToGroup(const std::string& groupName, Group* parentGroup, Group* subgroup) {
  Group* newSubgroup = new Group(groupName);
  parentGroup->addGroup(newSubgroup);
}

void addEntryToGroup(const std::string& entryName, Group* group) {
  Entry* newEntry = new Entry(entryName);
  group->addEntry(newEntry);
}

