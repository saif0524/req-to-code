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
std::pair<Data, Data> remove_data(std::pair<Group, Group> group, Data data);
std::vector<Group> list_groups();

std::pair<Group, Group> create_group(std::string name) {
    Group g(name);
    Group empty_g();
    return std::make_pair(g, empty_g);
    }

std::pair<Subgroup, Subgroup> create_subgroup(std::pair<Group, Group> group, std::string name) {
  Subgroup new_subgroup(name);
  return {group.first, new_subgroup};
  }

std::pair<Data, Data> remove_data(std::pair<Group, Group> group, Data data) {
  Group g = group.first;
  if (g.data.find(data) != g.data.end()) {
    size_t index = g.data.find(data);
    g.data.erase(index);
  }
  return std::make_pair(g.first, g.second);
  }
  

vector<pair<Group, string>> list_groups(const vector<Group>& groups) {
  vector<pair<Group, string>> result;
  for (auto& g : groups) {
    result.emplace_back(g, create_group(g.first).second.name);
  }
  return result;
  }

