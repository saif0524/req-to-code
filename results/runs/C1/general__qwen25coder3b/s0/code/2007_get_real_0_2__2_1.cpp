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

void updateSiteVersion(int currentVersion, int newVersion);
bool checkForFutureVersion(int currentVersion);
std::string generateVersionUpdateLog(int currentVersion, int newVersion);
void notifySiteAdmins(const std::string& logMessage);
void updateSiteConfiguration(int newVersion);

void updateSiteVersion(int currentVersion, int newVersion) { currentVersion = newVersion; }

bool checkForFutureVersion(int currentVersion) { return currentVersion < 2; }

std::string generateVersionUpdateLog(int currentVersion, int newVersion) { return "Version updated from " + std::to_string(currentVersion) + " to " + std::to_string(newVersion); }

void notifySiteAdmins(const std::string& logMessage) { std::cout << logMessage << std::endl; }

void updateSiteConfiguration(int currentVersion, int newVersion) { updateSiteVersion(currentVersion, newVersion); std::string logMessage = generateVersionUpdateLog(currentVersion, newVersion); notifySiteAdmins(logMessage); }

