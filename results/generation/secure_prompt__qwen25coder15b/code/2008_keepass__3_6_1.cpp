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
  if (parentGroup.createGroup(name)) {
    return {"reason": "Group created successfully"};
  } else {
    return {"reason": "Failed to create group"};
  }
}

void createSubgroup(const std::string& name, Group& parentGroup) {
  if (parentGroup.createGroup(name)) {
    return {

void addEntryToGroup(const std::string& entryName, Group& group) {
  if (group.entries.find(entryName) == group.entries.end()) {
    group.entries.insert({entryName, Entry()});
    return {
      "reason": "Entry added successfully"
    };
  } else {
    return {
      "reason": "Entry already exists in group"
    };
  }
}

void addEntryToSubgroup(const std::string& entryName, Group& subgroup) {
  if (subgroup.entries.find(entryName) == subgroup.entries.end()) {
    subgroup.entries.insert({entryName, Entry()});
    return {
      "reason": "Entry added successfully"
    };
  } else {
    return {
      "reason": "Entry already exists in group"
    };
  }
}

