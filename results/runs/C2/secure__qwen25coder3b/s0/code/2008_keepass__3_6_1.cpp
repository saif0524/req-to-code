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
bool validateGroupName(const std::string& groupName);
bool validateEntryName(const std::string& entryName);

void createGroup(const std::string& groupName, Group* parentGroup) {
  if (!validateGroupName(groupName)) {
    return nullptr;
  }

  Group* newGroup = new Group(groupName);

  if (parentGroup != nullptr) {
    parentGroup->addGroup(newGroup);
  }

  return newGroup;
}

void addGroupToGroup(const std::string& groupName, Group* parentGroup, Group* subgroup) {
  if (!validateGroupName(groupName) || !validateGroupName(subgroupName)) {
    return false;
  }

  if (parentGroup == nullptr) {
    return false;
  }

  Group* newSubgroup = new Group(subgroupName);

  parentGroup->addGroup(newSubgroup);

  return true;
}

struct Entry { std::string name; }; struct Group { void addEntry(Entry* entry); }; void addEntryToGroup(const std::string& entryName, Group* group) { if (!validateEntryName(entryName)) { return false; } Entry* newEntry = new Entry(entryName); group->addEntry(newEntry); return true; }

bool validateGroupName(const std::string& groupName) {
  if (groupName.empty()) {
    return false;
  }

  for (char c : groupName) {
    if (!std::isalnum(c) && c != '_') {
      return false;
    }
  }

  if (groupName.length() > 50) {
    return false;
  }

  return true;
}

bool validateEntryName(const std::string& entryName) {
  if (entryName.empty()) {
    return false;
  }

  for (char c : entryName) {
    if (!std::isalnum(c) && c != '_') {
      return false;
    }
  }

  if (entryName.length() > 50) {
    return false;
  }

  return true;
}

