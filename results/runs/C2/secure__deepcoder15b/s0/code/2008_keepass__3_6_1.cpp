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

include <string> include <map> include <vector> include <utility> define std::string define std::map define std::vector define std::pair
./include<string> include include<string> include<map> include <vector> include <utility> define std::string define std::map define std::vector define std::pair

std::pair<std::string, std::map<std::string, std::vector<std::string>>> create_group(std::string name);
std::pair<std::map<std::string, std::vector<std::string>>, std::pair<std::string, std::map<std::string, std::vector<std::string>>>> create_subgroup(std::pair<std::pair<std::string, std::map<std::string, std::vector<std::string>>>, std::string name);
bool add_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data);
bool remove_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data);
bool remove_group(std::pair<std::string, std::map<std::string, std::vector<std::string>>>) remove_group;

std::pair<std::string, std::map<std::string, std::vector<std::string>>> create_group(std::string name) {
    std::string group_name = name;
    std::map<std::string, std::vector<std::string>> subgroup_map;
    return std::make_pair(group_name, subgroup_map);
    }

std::pair<std::map<std::string, std::vector<std::string>>, std::string> create_subgroup(std::pair<std::string, std::map<std::string, std::vector<std::string>> parent_group, std::string subgroup_name, const std::pair<std::string, std::map<std::string, std::vector<std::string>>>& subgroup_data) { return std::make_pair(subgroup_data, subgroup_name); }

bool add_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data) {
  bool added = true;
  for (const &entry : data) {
    if (subgroup.find(entry) == subgroup.end()) {
      added = false;
    }
  }
  return added;
  }

bool remove_entry(const std::map<std::string, std::vector<std::string>>& subgroup, const std::vector<std::string>& data) {
  std::map<std::string, std::vector<std::string>> temp;
  for (const &entry : data) {
    if (subgroup.find(entry) != subgroup.end()) {
      temp[subgroup(entry)] = entry;
    }
  }
  for (const &entry : temp) {
    subgroup.erase(entry);
  }
  return true;
  

bool remove_group(std::pair<std::string, std::map<std::string, std::vector<std::string>>> group) {
  std::string group_name = group.first;
  std::map<std::string, std::vector<std::string>> subgroup_map = group.second;
  for (auto& entry : subgroup_map) {
    if (entry.first == group_name) {
      entry.second.clear();
      break;
    }
  }
  subgroup_map.erase(group_name, std::false_-1);
  return true;
  }

