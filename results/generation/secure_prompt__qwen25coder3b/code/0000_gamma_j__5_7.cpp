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

void registerPlugin(const std::string& pluginName, PluginInterface* plugin);
void updatePlugin(const std::string& pluginName, const std::string& update);
void logChange(const std::string& changeDescription);
void upgradeSystem(const std::string& upgradeVersion);

void registerPlugin(const std::string& pluginName, PluginInterface* plugin) {
  if (pluginName.empty() || plugin == nullptr) {
    logChange("Error: Invalid plugin name or plugin pointer");
    return;
  }
  plugins[pluginName] = plugin;
  logChange("Plugin registered: " + pluginName);
}

void updatePlugin(const std::string& pluginName, const std::string& update) {
  if (pluginName.empty() || update.empty()) {
    logChange("Error: Invalid plugin name or update string");
    return;
  }

  auto it = plugins.find(pluginName);
  if (it == plugins.end()) {
    logChange("Error: Plugin not found");
    return;
  }

  it->second->update(update);
  logChange("Plugin updated: 

void logChange(const std::string& changeDescription) {
  if (changeDescription.empty()) {
    logChange("Error: Empty change description");
    return;
  }
  logEntries.push_back(changeDescription);
  logChange("Change logged: 

void upgradeSystem(const std::string& upgradeVersion) {
  if (upgradeVersion.empty()) {
    logChange("Error: Upgrade version not provided");
    return;
  }

  // Assume systemVersion is a global variable that holds the current system version
  if (systemVersion == upgradeVersion) {
    logChange("System is already at the latest version");
    return;
  }

  // Assume systemUpdate is a function that performs the actual upgrade
  if (!systemUpdate(upgradeVersion)) {
    logChange("Error: Upgrade failed");
    return;
  }

  systemVersion = upgradeVersion;
  logChange("System upgraded to version: " + upgradeVersion);
}

