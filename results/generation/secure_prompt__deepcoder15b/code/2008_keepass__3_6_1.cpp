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

[std::pair<std::string, std::map<std::string, std::vector<std::string>>>, std::pair<std::string, std::map<std::string, std::vector<std::string>>>]

std::pair<std::string, std::map<std::string, std::vector<std::string>>> create_group(std::string name);
std::pair<std::map<std::string, std::vector<std::string>>, std::pair<std::string, std::map<std::string, std::vector<std::string>>>> create_subgroup(std::pair<std::pair<std::string, std::map<std::string, std::vector<std::string>>>, std::string name);
bool add_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data);
bool remove_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data);

std::pair<std::string, std::map<std::string, std::vector<std::string>>> create_group(std::string name) {
    std::string group_name = name;
    std::map<std::string, std::vector<std::string>> subgroup_map;
    return std::make_pair(group_name, subgroup_map);
    }

std::pair<std::string, std::map<std::string, std::vector<std::string>>> create_subgroup(std::pair<std::string, std::map<std::string, std::vector<std::string>> group, std::string name, const std::pair<std::string, std::map<std::string, std::vector<std::string>>>& subgroup) {
    std::map<std::string, std::vector<std::string>> new_subgroup_map = subgroup;
    std::pair<std::string, std::map<std::string, std::vector<std::string>>> new_group_pair = {name, new_subgroup_map};
    return std::make_pair(new_subgroup_map, new_group_pair);
}

// Reasoning: The function creates a new subgroup within the specified group by copying the subgroup map from the provided subgroup. It then returns a new pair containing this subgroup map and another pair that includes the original group name and the subgroup map. This ensures that the subgroup is correctly nested within the specified group as required.

// Testing: The function should correctly create a subgroup within a group. For example, if group is 

bool add_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data) {
  std::map<std::string, std::vector<std::string>> subgroup_map = subgroup;
  std::vector<std::string> new_data;
  bool added = true;

  for (const &entry : data) {
    if (subgroup_map.find(entry) == subgroup_map.end()) {
      new_data.push_back(entry);
      added = true;
    } else {
      subgroup_map.erase(entry);
      new_data.erase(new_data.begin() + subgroup_map.find(entry) + 1);
      added = false;
    }
  }

  if (new_data.size() == data.size()) {
    return true;
  }

  return false;
  }
  

bool remove_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data) {
    std::map<std::string, std::vector<std::string>> temp;

    for (const &entry : data) {
        if (subgroup.find(entry) != subgroup.end()) {
            temp[subgroup entry] = entry;
        }
    }

    for (const &entry : temp) {
        subgroup.erase(entry);
    }

    return true;
    }

