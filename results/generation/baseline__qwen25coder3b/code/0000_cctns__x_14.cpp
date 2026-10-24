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

void setAccessControl(User& user, const std::vector<UserGroup>& groups);
std::vector<UserGroup> getUserGroups(const User& user);
void setUserRoles(User& user, const std::vector<Role>& roles);
std::vector<Role> getUserRoles(const User& user);
void setSecurityAttributes(User& user, const SecurityAttributes& attributes);

void setAccessControl(User& user, const std::vector<UserGroup>& groups) {
  for (const auto& group : groups) {
    user.addGroup(group);  // Assuming User has a method addGroup to add a group
  }
}

std::vector<UserGroup> getUserGroups(const User& user) { return user.getGroups(); }

void setUserRoles(User& user, const std::vector<Role>& roles) {
  for (const auto& role : roles) {
    user.addRole(role);  // Assuming User has a method addRole to add a role
  }
}

std::vector<Role> getUserRoles(const User& user) { return user.getUserRoles(); }

void setSecurityAttributes(User& user, const SecurityAttributes& attributes) {
  for (const auto& attribute : attributes) {
    user.applySecurityAttribute(attribute);  // Assuming User has a method applySecurityAttribute to apply an attribute
  }
}

