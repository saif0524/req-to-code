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

using std::string; using std::vector; using std::join; using std::system;

void openKeePass();
void selectGroupSubgroup(const std::string& groupName, const std::string& subGroupName);
void typeSearchWord(const std::string& searchWord);
void selectSearchFields(const std::vector<std::string>& fields);
void clickOK();

void openKeePass() { system(" KeePass.exe"); }

void selectGroupSubgroup(const std::string& groupName, const std::string& subGroupName) { system(" KeePass.exe /selectgroup " + groupName + " /selectsubgroup " + subGroupName + " /type " + join(fields, " /type ")); }

void typeSearchWord(const std::string& searchWord, const std::string& groupName, const std::string& subGroupName) { system(" KeePass.exe /selectgroup " + groupName + " /selectsubgroup " + subGroupName + " /type " + searchWord); }

using std::string; using std::vector; using std::join; using std::system; void selectSearchFields(const std::string& groupName, const std::string& subGroupName) { system(" KeePass.exe /selectgroup " + groupName + " /selectsubgroup " + subGroupName + " /type " + join(fields, " /type ")); }

void clickOK() { system(" KeePass.exe /selectgroup /selectsubgroup /type /type"); }

