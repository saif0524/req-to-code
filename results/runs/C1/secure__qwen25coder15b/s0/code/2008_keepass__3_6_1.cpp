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

struct Entry; struct Group;
struct Entry { std::string name; }; struct Group { std::map<std::string, Entry> entries; }; void addEntryToSubgroup(const std::string& entryName, Group& subgroup) { if (subgroup.entries.find(entryName) == subgroup.entries.end()) { subgroup.entries.insert({entryName, Entry()}); return {

void createGroup(const std::string& name, Group& parentGroup);
void createSubgroup(const std::string& name, Group& parentGroup);
void addEntryToGroup(const std::string& entryName, Group& group);
void addEntryToSubgroup(const std::string& entryName, Group& subgroup);

bool createGroup(const std::string& name, Group& parentGroup) {
  if (parentGroup.createGroup(name)) {
    return true;
  } else {
    return false;
  }
}

struct Entry { std::string name; }; struct Group { std::map<std::string, Entry> entries; }; void addEntryToGroup(const std::string& entryName, Group& group) { if (group.entries.find(entryName) == group.entries.end()) { group.entries.insert({entryName, Entry()}); return {"reason": "Entry added successfully"}; } else { return {"reason": "Entry already exists in group"}; } }

struct Entry { std::string name; }; struct Group { std::map<std::string, Entry> entries; }; void addEntryToSubgroup(const std::string& entryName, Group& subgroup) { if (subgroup.entries.find(entryName) == subgroup.entries.end()) { subgroup.entries.insert({entryName, Entry()}); return {

