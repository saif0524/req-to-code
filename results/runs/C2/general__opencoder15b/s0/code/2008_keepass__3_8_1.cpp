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

void delete_group_subgroup(GroupSubgroup* group_subgroup);

void delete_group_subgroup(GroupSubgroup* group_subgroup) {
    // Iterate through the group/subgroup list
    for (auto it = group_subgroup_list.begin(); it != group_subgroup_list.end(); ++it) {
      // Check if the current group/subgroup matches the provided group/subgroup
      if (*it == group_subgroup) {
        // Remove the group/subgroup from the list
        group_subgroup_list.erase(it);
        return "Group/subgroup deleted";
     }
    }
    return "Group/subgroup not found";
}

