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

void delete_group_subgroup(Group* group, Group* subgroup);

void delete_group_subgroup(Group* group, Group* subgroup) {
    // Iterate through the group's subgroups
    for (int i = 0; i < group->subgroups.size(); i++) {
      if (group->subgroups[i] == subgroup) {
        // Remove the subgroup from the group's subgroups
        group->subgroups.erase(group->subgroups.begin() + i);
        break;
     }
    }
    // Check if the group is empty
    if (group->subgroups.empty()) {
      // Group is empty
     group->subgroups.clear();
    }
}

