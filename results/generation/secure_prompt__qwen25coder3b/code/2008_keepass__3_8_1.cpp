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

void deleteGroupOrSubgroup(const GroupOrSubgroup& groupOrSubgroup);
GroupOrSubgroup selectGroupOrSubgroup();
bool confirmDeletion(const GroupOrSubgroup& groupOrSubgroup);
bool validateInput(const GroupOrSubgroup& groupOrSubgroup);
void handleDeletion(const GroupOrSubgroup& groupOrSubgroup);

void deleteGroupOrSubgroup(const GroupOrSubgroup& groupOrSubgroup) {
  if (!validateInput(groupOrSubgroup)) {
    return false;
  }
  handleDeletion(groupOrSubgroup);
  return true;
}

GroupOrSubgroup selectGroupOrSubgroup() {
  std::vector<GroupOrSubgroup> groups = getAllGroups();
  if (groups.empty()) {
    return GroupOrSubgroup();
  }
  std::cout << "Select a group or subgroup: " << std::endl;
  for (size_t i = 0; i < groups.size(); ++i) {
    std::cout << i + 1 << ". " << groups[i].getName() << std::endl;
  }
  int choice;
  std::cin >> choice;
  if (choice < 1 || choice > static_cast<int>(groups.size())) {
    std::cout << "Invalid choice. Please try again." << std::endl;
    return GroupOrSubgroup();
  }
  return groups[choice - 1];
}

bool confirmDeletion(const GroupOrSubgroup& groupOrSubgroup) {
  std::string confirmation;
  std::cout << "Are you sure you want to delete the group/subgroup " << groupOrSubgroup.getName() << "? (yes/no): " << std::endl;
  std::cin >> confirmation;
  if (confirmation == "yes" || confirmation == "y") {
    return true;
  } else if (confirmation == "no" || confirmation == "n") {
    return false;
  } else {
    std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
    return confirmDeletion(groupOrSubgroup);
  }
}

bool validateInput(const GroupOrSubgroup& groupOrSubgroup) {
  if (!groupOrSubgroup.existsInDatabase()) {
    std::cout << "Group or subgroup does not exist in the database." << std::endl;
    return false;
  }
  if (!groupOrSubgroup.hasDeletePermission()) {
    std::cout << "You do not have permission to delete this group or subgroup." << std::endl;
    return false;
  }
  return true;
}

void handleDeletion(const GroupOrSubgroup& groupOrSubgroup) {
  if (!groupOrSubgroup.existsInDatabase()) {
    std::cout << "Group or subgroup does not exist in the database." << std::endl;
    return;
  }
  if (!groupOrSubgroup.hasDeletePermission()) {
    std::cout << "You do not have permission to delete this group or subgroup." << std::endl;
    return;
  }
  try {
    groupOrSubgroup.deleteFromDatabase();
    std::cout << "Group or subgroup deleted successfully." << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Error deleting group or subgroup: " << e.what() << std::endl;
  }
}

