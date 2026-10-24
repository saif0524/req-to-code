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

void openKeePass();
void selectGroupSubgroup(const std::string& groupName, const std::string& subGroupName);
void typeSearchWord(const std::string& searchWord);
void selectSearchFields(const std::vector<std::string>& fields);
void clickOK();

void openKeePass() {
  system("start KeePass.exe");
}

void selectGroupSubgroup(const std::string& groupName, const std::string& subGroupName) {
  system("start KeePass.exe /selectgroupsubgroup " + groupName + " " + subGroupName);
}

void typeSearchWord(const std::string& searchWord) {
  system("start KeePass.exe /selectgroupsubgroup " + groupName + " " + subGroupName);
  system("start KeePass.exe /type " + searchWord);
  system("start KeePass.exe /clickok");
}

void selectSearchFields(const std::vector<std::string>& fields) {
  for (const auto& field : fields) {
    system("start KeePass.exe /selectgroupsubgroup " + groupName + " " + subGroupName + " /type " + field + " /clickok");
  }
}

void clickOK() {
  system("start KeePass.exe /selectgroupsubgroup " + groupName + " " + subGroupName + " /type " + searchWord + " /clickok");
}

