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

void set_user_access(int user_id, int case_id, int access_level);
int get_user_access(int user_id, int case_id);
void add_user_to_group(int user_id, int group_id);
void remove_user_from_group(int user_id, int group_id);
void set_group_access(int group_id, int access_level);

void set_user_access(int user_id, int case_id, int access_level) {
     // Check if the user is already a member of the group
     if (!is_user_in_group(user_id, case_id)) {
         // Add the user to the group
         add_user_to_group_list(user_id, case_id);
         // Update the group's access level
         set_group_access(case_id, get_user_access(user_id, case_id));
     }
}

int get_user_access(int user_id, int case_id) {
    // Check if the user is already a member of the group
    if (!is_user_in_group(user_id, case_id)) {
        // Add the user to the group
        add_user_to_group_list(user_id, case_id);
        // Update the group's access level
        set_group_access(case_id, get_user_access(user_id, case_id));
    }
    return get_user_access(user_id, case_id);
}

void add_user_to_group(int user_id, int group_id) {
     // Check if the user is already a member of the group
     if (!is_user_in_group(user_id, group_id)) {
         // Add the user to the group
         add_user_to_group_list(user_id, group_id);
         // Update the group's access level
         set_group_access(group_id, get_user_access(user_id, group_id));
     }
}

void remove_user_from_group(int user_id, int group_id) {
     // Check if the user is already a member of the group
     if (!is_user_in_group(user_id, group_id)) {
         // Add the user to the group
         add_user_to_group_list(user_id, group_id);
         // Update the group's access level
         set_group_access(group_id, get_user_access(user_id, group_id));
     }
}

void set_group_access(int group_id, int access_level) {
     // Check if the user is already a member of the group
     if (!is_user_in_group(user_id, group_id)) {
         // Add the user to the group
         add_user_to_group_list(user_id, group_id);
         // Update the group's access level
         set_group_access(group_id, get_user_access(user_id, group_id));
     }
}

