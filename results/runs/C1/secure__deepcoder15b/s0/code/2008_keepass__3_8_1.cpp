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

You may need to include any struct definitions for Group, Subgroup, etc., if they are not already provided.

void DeleteGroup(const Group* group);
void DeleteSubgroup(const Subgroup* subgroup);
void DeleteGroupDetails(const Group* group);
void DeleteSubgroupDetails(const Subgroup* subgroup);
void ClearGroup(const Group* group);

void DeleteGroup(const Group* group) {
  // Check if the group is still active
  if (group != NULL && activeGroup) {
    // Delete the group from the system
    delete group;
    // Restore any data or resources
    if (group != NULL && group->details != NULL) {
      delete group->details;
    } else if (group->data != NULL) {
      free(group->data);
    }
    activeGroup = false;
  }
  return reason: "deleted the group from the system"
}

void DeleteSubgroup(const Subgroup* subgroup)
{
  if (subgroup != NULL && activeGroup)
  {
    free(subgroup->details);
    return reason: "deleting the subgroup from the system";
  }
  return reason: "subgroup not active or not found";
}

void DeleteGroupDetails(const Group* group) {
    if (group == NULL) {
        return "group is null or not active", NULL, 0;
    }
    if (!group->details) {
        return "group details not found", NULL, 0;
    }
    free(group->details);
    return "group details deleted", NULL, 0;
} "reasoning": [1. Check if group is null, return error. 2. If group is active, check details. 3. If details are null, return error. 4. Else, free details. 5. Return deletion message.]

void DeleteSubgroupDetails(const Subgroup* subgroup)
	{
		if (subgroup != NULL && !activeGroup)
		{
			free(subgroup->details);
		}
		return NULL, 0, 0;
	}

void ClearGroup(const Group* group) {
  if (group != NULL) {
    delete group;
  }
  }

