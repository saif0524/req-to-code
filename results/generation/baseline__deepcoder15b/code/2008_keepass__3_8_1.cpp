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
    int foundGroup = -1;
    for (auto group : groups) {
        if (group.id == groupId) {
            foundGroup = group.id;
            break;
        }
    }
    return foundGroup;
}

bool deleteGroup(Group group) {
    int groupId = getGroup(group);
    if (groupId != -1) {
        groups.erase(groups.begin() + groupId, groups.end() + groupId);
    }
    return true;
}

