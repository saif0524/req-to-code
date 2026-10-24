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

extern std::vector<std::unique_ptr<UIElement>> uiElements;

void selectGroupOrSubgroup(GroupOrSubgroup& selectedGroupOrSubgroup);
void deleteGroupOrSubgroup(GroupOrSubgroup& groupOrSubgroup);
bool confirmDeletion(const GroupOrSubgroup& groupOrSubgroup);
void executeDeletion(GroupOrSubgroup& groupOrSubgroup);
void updateUI();

void selectGroupOrSubgroup(GroupOrSubgroup& selectedGroupOrSubgroup) {
  // Display available groups and subgroups in the UI
  // Example: displayGroupsAndSubgroups();
  // Wait for user to select a group or subgroup
  // Example: userSelectsGroupOrSubgroup(selectedGroupOrSubgroup);
  updateUI();
}

void deleteGroupOrSubgroup(GroupOrSubgroup& groupOrSubgroup) {
  if (confirmDeletion(groupOrSubgroup)) {
    // Implement deletion logic here
    // Example: deleteGroup(groupOrSubgroup);
    updateUI();
  }
}

bool confirmDeletion(const GroupOrSubgroup& groupOrSubgroup) {
  // Display confirmation dialog or prompt
  // Example: bool confirmed = displayConfirmationDialog(groupOrSubgroup);
  // Return the user's response
  return confirmed;
}

bool executeDeletion(GroupOrSubgroup& groupOrSubgroup) { return deleteGroupOrSubgroup(groupOrSubgroup); }

void updateUI() {
  for (auto& element : uiElements) {
    if (element->isGroupOrSubgroup(groupOrSubgroup)) {
      element->remove();
    }
  }
}

