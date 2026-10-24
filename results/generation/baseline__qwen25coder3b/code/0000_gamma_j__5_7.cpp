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

void registerPlugin(Plugin* plugin);
void updatePlugin(Plugin* plugin);
void logChange(const std::string& changeDescription);
void upgradeSystem();

void registerPlugin(Plugin* plugin) {
  plugins.push_back(plugin);
}

void updatePlugin(Plugin* plugin) {
  auto it = std::find(plugins.begin(), plugins.end(), plugin);
  if (it != plugins.end()) {
    *it = plugin;
    logChange("Updated plugin: " + plugin->getName());
    return true;
  }
  return false;
}

void logChange(const std::string& changeDescription) {
  changes.push_back(changeDescription);
}

void upgradeSystem() {
  for (auto& plugin : plugins) {
    updatePlugin(plugin);
  }
  logChange("System upgraded to latest version.");
}

