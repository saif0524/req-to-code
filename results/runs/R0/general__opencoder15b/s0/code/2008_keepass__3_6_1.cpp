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

void add_group(const std::string& name, const std::string& parent_group_name);
void add_subgroup(const std::string& name, const std::string& parent_group_name);
void create_group(const std::string& name, const std::string& parent_group_name);
void create_subgroup(const std::string& name, const std::string& parent_group_name);
void add_entry(const std::string& name, const std::string& group_name);

void add_group(const std::string& name, const std::string& parent_group_name) {
  // Check if the parent group exists
  if (!group_exists(parent_group_name)) {
    return error("Parent group does not exist");
  }

  // Create a new group
  Group new_group(name, parent_group_name);

  // Add the new group as a child group of the parent group
  parent_group.children.push_back(new_group);
}

void add_subgroup(const std::string& name, const std::string& parent_group_name) {
  // Check if the parent group exists
  if (!group_exists(parent_group_name)) {
    return error("Parent group does not exist");
  }

  // Create a new group
  Group new_group(name, parent_group_name);

  // Add the new group as a child group of the parent group
  parent_group.children.push_back(new_group);
}

void create_group(const std::string& name, const std::string& parent_group_name) {
  // Check if the parent group exists
  if (!group_exists(parent_group_name)) {
    return error("Parent group does not exist");
  }

  // Create a new group
  Group new_group(name, parent_group_name);

  // Add the new group as a child group of the parent group
  parent_group.children.push_back(new_group);
}

void create_subgroup(const std::string& name, const std::string& parent_group_name) {
  // Check if the parent group exists
  if (!group_exists(parent_group_name)) {
    return error("Parent group does not exist");
  }

  // Create a new group
  Group new_group(name, parent_group_name);

  // Add the new group as a child group of the parent group
  parent_group.children.push_back(new_group);
}

void add_entry(const std::string& name, const std::string& group_name) {
  // Check if the group exists
  if (!group_exists(group_name)) {
    return error("Group does not exist");
  }

  // Create a new entry
  Entry new_entry(name, group_name);

  // Add the new entry to the specified group
  group.children.push_back(new_entry);
}

