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

void registerPlugin(const std::string& pluginName, const std::function<void()>& pluginFunction);
void unregisterPlugin(const std::string& pluginName);
void callPlugin(const std::string& pluginName);
std::vector<std::string> getPluginList();
std::string getPluginDocumentation(const std::string& pluginName);

void registerPlugin(const std::string& pluginName, const std::function<void()>& pluginFunction) {
  if (pluginName.empty()) {
    return "Error: Plugin name cannot be empty";
  }
  pluginMap[pluginName] = pluginFunction;
}

void unregisterPlugin(const std::string& pluginName) {
  if (pluginName.empty()) {
    return "Error: Plugin name cannot be empty";
  }
  pluginMap.erase(pluginName);
  return "Plugin unregistered successfully";
}

void callPlugin(const std::string& pluginName) {
  if (pluginName.empty()) {
    return "Error: Plugin name cannot be empty";
  }
  auto it = pluginMap.find(pluginName);
  if (it != pluginMap.end()) {
    it->second();
    return "Plugin called successfully";
  } else {
    return "Error: Plugin not found";
  }
}

std::vector<std::string> getPluginList() {
  std::vector<std::string> pluginList;
  for (const auto& pair : pluginMap) {
    pluginList.push_back(pair.first);
  }
  return pluginList;
}

std::string getPluginDocumentation(const std::string& pluginName) {
  if (pluginName.empty()) {
    return "Error: Plugin name cannot be empty";
  }
  auto it = pluginMap.find(pluginName);
  if (it != pluginMap.end()) {
    return it->second;
  } else {
    return "Error: Plugin not found";
  }
}

