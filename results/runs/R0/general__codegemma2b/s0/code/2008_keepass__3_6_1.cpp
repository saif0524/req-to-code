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

void AddGroup(const QString& groupName);
void AddSubgroup(const QString& groupName, const QString& subgroupName);
void AddEntry(const QString& groupName, const QString& subgroupName, const QString& entryName);
void AddEntry(const QString& groupName, const QString& subgroupName, const QString& entryName, const QString& username, const QString& password, const QString& url, const QString& notes);
void AddEntry(const QString& groupName, const QString& subgroupName, const QString& entryName, const QString& username, const QString& password, const QString& url, const QString& notes, const QString& tags);






