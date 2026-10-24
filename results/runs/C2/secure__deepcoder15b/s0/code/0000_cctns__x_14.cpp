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

bool is_admin(User user);
void add_user_to_groups(User user, vector<group> groups);
void set_user_profile(User user);
void change_security_attributes(User user);
void handle_access_request(User user, vector<case> cases);

bool is_admin(User user) {
  return user.is_admin;
  }

void add_user_to_groups(User user, const vector<group>& groups) {
  for (const auto& group : groups) {
    group.add_user(user);
  }
  }

void set_user_profile(User user, const UserProfile& profile) {
  profile = profile_storage(user);
  profile.set_profile(user_profile);
  }

void change_security_attributes(User user) {
  if (!is_admin(user)) {
    return; 
  }

  // Get current security attributes
  auto currentAttributes = get_security_attributes(user);

  // Create new security attribute configuration
  struct newAttributes {
    // Set new security attributes
  }
  newAttributes.newAttr = { ... }; 

  // Update the user's profile with new attributes
  profile_storage(user).profile = newAttributes.newAttr;
  // Log the change
  log(1);
  return;
  }

void handle_access_request(User user, vector<case> cases) {
  if (!is_admin(user)) {
    return;
  }

  if (user.is_admin && user.is_super_user) {
    if (is_admin(user)) {
      for (const auto& group : user.groups) {
        if (group.add_user(user)) {
          return;
        }
      }
      return;
    }

    if (user.is_admin && user.is_super_user) {
      // Handle case based on security level
      if (user.security_level >= high) {
        log(

