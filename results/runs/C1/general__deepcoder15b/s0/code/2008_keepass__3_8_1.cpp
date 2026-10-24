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

int getGroup(int groupId);
Group deleteGroup(Group group);

int getGroup(int groupId) {
    for (auto group : group) {
        if (group.id == groupId) {
            return group.id;
        }
    }
    return -1;
}

bool deleteGroup(const std::string& groupKey, Group group) {
  int groupId = getGroup(groupKey);
  if (groupId != -1 && groupKey == groupId) {
    groups.erase(groups.begin() + groupId, groups.end() + groupId);
    return true;
  }
  return false;
}

