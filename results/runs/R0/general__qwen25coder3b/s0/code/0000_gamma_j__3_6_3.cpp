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
std::vector<std::string> getPluginList();
void callPlugin(const std::string& pluginName);
std::string getPluginDocumentation(const std::string& pluginName);

void registerPlugin(const std::string& pluginName, const std::function<void()>& pluginFunction) {
  pluginMap[pluginName] = pluginFunction;
}

void unregisterPlugin(const std::string& pluginName) { pluginMap.erase(pluginName); }

std::vector<std::string> getPluginList() { std::vector<std::string> result; for (const auto& [pluginName, _] : pluginMap) { result.push_back(pluginName); } return result; }

void callPlugin(const std::string& pluginName) {
  if (pluginMap.find(pluginName) != pluginMap.end()) {
    pluginMap[pluginName]();
  } else {
    throw std::runtime_error("Plugin not found");
  }
}

std::string getPluginDocumentation(const std::string& pluginName) {
  if (documentationMap.find(pluginName) != documentationMap.end()) {
    return documentationMap[pluginName];
  } else {
    throw std::runtime_error("Plugin not found");
  }
}

