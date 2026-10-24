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

void registerPlugin(const std::string& pluginName, const std::string& pluginVersion, const std::string& pluginDescription);
void unregisterPlugin(const std::string& pluginName);
std::vector<std::string> getPluginList() const;
void loadPlugin(const std::string& pluginName);
void unloadPlugin(const std::string& pluginName);

void registerPlugin(const std::string& pluginName, const std::string& pluginVersion, const std::string& pluginDescription) {
  std::vector<std::string> plugins;
  plugins.push_back(pluginName);
  plugins.push_back(pluginVersion);
  plugins.push_back(pluginDescription);
  return {"success": true, "reason": "Plugin registered successfully"};
}

void unregisterPlugin(const std::string& pluginName) {
  std::vector<std::string> plugins = getPluginList();
  auto it = std::find(plugins.begin(), plugins.end(), pluginName);
  if (it != plugins.end()) {
    plugins.erase(it);
  }
  return {

std::vector<std::string> getPluginList() const {
  return getPluginList();
}

void loadPlugin(const std::string& pluginName) {
  std::vector<std::string> plugins = getPluginList();
  auto it = std::find(plugins.begin(), plugins.end(), pluginName);
  if (it != plugins.end()) {
    plugins.erase(it);
  }
  return {
    "success": true,
    "reason": "Plugin loaded successfully"
  };
}

void unloadPlugin(const std::string& pluginName) {
  std::vector<std::string> plugins = getPluginList();
  auto it = std::find(plugins.begin(), plugins.end(), pluginName);
  if (it != plugins.end()) {
    plugins.erase(it);
  }
  return {
    "success": true,
    "reason": "Plugin unloaded successfully"
  };
}

