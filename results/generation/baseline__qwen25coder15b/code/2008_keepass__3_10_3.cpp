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

void createGroup(const std::string& groupName);
void addEntryToGroup(const std::string& groupName, const Entry& entry);
bool validatePassword(const std::string& password, const std::string& repeatPassword);

void createGroup(const std::string& groupName) {
  if (!validatePassword(groupName, groupName)) {
    return false;
  }
  createGroup(groupName);
  addEntryToGroup(groupName, Entry());
  return true;
}

void addEntryToGroup(const std::string& groupName, const Entry& entry) {
  if (!validatePassword(groupName, groupName)) {
    return false;
  }
  createGroup(groupName);
  addEntryToGroup(groupName, entry);
  return true;
}

bool validatePassword(const std::string& password, const std::string& repeatPassword) {
  return password == repeatPassword;
}

