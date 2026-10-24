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

  // Create a new group with the given name under the parent group
  Group new_group(name, parent_group_name);
  db.add_group(new_group);
  return success("Group added");
}

void add_subgroup(const std::string& name, const std::string& parent_group_name) {
  // Check if the parent group exists
  if (!group_exists(parent_group_name)) {
    return error("Parent group does not exist");
  }

  // Create a new subgroup with the given name under the parent group
  Group new_subgroup(name, parent_group_name);
  db.add_group(new_subgroup);
  return success("Subgroup added");
}

void create_group(const std::string& name, const std::string& parent_group_name) {
   // Check if the parent group exists
   if (!group_exists(parent_group_name)) {
     return error("Parent group does not exist");
   }

   // Create a new group with the given name under the parent group
   Group new_group(name, parent_group_name);
   db.add_group(new_group);
   return success("Group added");
}

void create_subgroup(const std::string& name, const std::string& parent_group_name) {
    // Check if the parent group exists
    if (!group_exists(parent_group_name)) {
        return error("Parent group does not exist");
    }

    // Create a new subgroup with the given name under the parent group
    Group new_subgroup(name, parent_group_name);
    db.add_group(new_subgroup);
    return success("Subgroup added");
}

void add_entry(const std::string& name, const std::string& group_name) {
    // Check if the parent group exists
    if (!group_exists(parent_group_name)) {
        return error("Parent group does not exist");
    }

    // Create a new entry with the given name under the parent group
    Entry new_entry(name, parent_group_name);
    db.add_entry(new_entry);
    return success("Entry added");
}

