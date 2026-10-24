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

UserGroup* user_group: UserGroup* = add_user(UserGroup* group, string username, string password);
string group: string = get_users(UserGroup* group);
string group: string = validate_user(UserGroup* group, string username, string password);

3 to 6 short steps explaining how and why you implement it this way, and code: the complete function definition only.

string group: string = get_users(UserGroup* group)

string validate_user(UserGroup* group, string username, string password) {
    if (get_user(group, username) != NULL) {
        if (password == group->password) {
            return 

