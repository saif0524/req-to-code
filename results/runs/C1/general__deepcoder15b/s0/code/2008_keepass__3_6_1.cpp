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

std::pair<Group, Group> create_group(std::string name);
std::pair<Subgroup, Subgroup> create_subgroup(std::pair<Group, Group> group, std::string name);
std::pair<Data, Data> add_data(std::pair<Group, Group> group, Data data);
std::pair<Data, Data> remove_data(std::pair<Group, Group> group, Data data);
std::vector<Group> list_groups();

std::pair<Subgroup, Subgroup> create_subgroup(std::pair<Group, Group> group, std::string name) {
  Subgroup new_subgroup(name);
  return { group.first, new_subgroup};
  }
std::pair<Data, Data> add_data(std::pair<Group, Group> group, Data data) {
  Group g = group.first;
  if (g.data.find(data) != g.data.end()) {
    size_t index = g.data.find(data);
    g.data.erase(index);
  }
  return std::make_pair(g.first, g.second);
  }
std::vector<Group> list_groups(const std::vector<Group>& groups) {
  std::vector<Group> result;
  for (auto& g : groups) {
    result.emplace_back(g, create_group(g.first).second.name);
  }
  return result;
  }
std::pair<std::pair<Group, Group>, std::pair<Group, Group>> create_group(std::string name) {
  Group g(name);
  return { {g, g} };
  }

std::pair<Subgroup, Subgroup> create_subgroup(std::pair<Group, Group> group, std::string name) {
  Subgroup new_subgroup(name);
  return {group.first, new_subgroup};
  }

pair<Data, Data> add_data(std::pair<Group, Group> group, Data data) {
  pair<Data, Data> result;
  Group g = group.first;
  Data existing = g.data.find(data);
  if (existing != g.data.end()) {
    size_t index = g.data.find(data);
    g.data.erase(index);
    result = make_pair(g.first, data);
  } else {
    result = make_pair(g.first, data);
  }
  return result;
  }
  

std::pair<Data, Data> remove_data(std::pair<Group, Group> group, Data data) {
  Group g = group.first;
  if (g.data.find(data) != g.data.end()) {
    size_t index = g.data.find(data);
    g.data.erase(index);
  }
  return std::make_pair(g.first, g.second);
  }
  

vector<Group> list_groups(const vector<Group>& groups) {
  vector<Group> result;
  for (auto& g : groups) {
    result.emplace_back(g);
  }
  return result;
  }

