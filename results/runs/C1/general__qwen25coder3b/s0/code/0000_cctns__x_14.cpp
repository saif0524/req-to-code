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

void setAccessControl(User& user, const std::vector<UserGroup>& groups) { user.setGroups(groups); }

template<typename UserGroup, typename User>
std::vector<UserGroup> getUserGroups(const User& user) { return user.getGroups(); }

std::vector<Role> setUserRoles(User& user, const std::vector<Role>& roles) { return user.getUserRoles(); }

template<typename User, typename Role> std::vector<Role> getUserRoles(const User& user) { return user.getUserRoles(); }

void setSecurityAttributes(User& user, const SecurityAttributes& attributes) { return user.applySecurityAttribute(attributes); }

