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

void selectEntry(Entry* entry);
void changePassword(Entry* entry, const std::string& newPassword);
bool validateRepeatPassword(const std::string& password, const std::string& repeatPassword);

bool selectEntry(Entry* entry) { return entry != nullptr; }

void changePassword(Entry* entry, const std::string& newPassword) { if (!selectEntry(entry)) { return; } if (!validateRepeatPassword(newPassword, entry->getRepeatPassword())) { return; } entry->setPassword(newPassword); entry->setRepeatPassword(newPassword); }

bool validateRepeatPassword(const std::string& password, const std::string& repeatPassword) { return password == repeatPassword; }

