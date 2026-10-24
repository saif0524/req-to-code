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

static std::map<std::string, std::string> documentationMap;

void registerPlugin(const std::string& pluginName, const std::function<void()>& pluginFunction);
void unregisterPlugin(const std::string& pluginName);
std::vector<std::string> getPluginList();
void callPlugin(const std::string& pluginName);
std::string getPluginDocumentation(const std::string& pluginName);

void registerPlugin(const std::string& pluginName, const std::function<void()>& pluginFunction) { static std::map<std::string, std::function<void()>> pluginMap; pluginMap[pluginName] = pluginFunction; }

void unregisterPlugin(const std::string& pluginName) { static std::map<std::string, std::function<void()>> pluginMap; pluginMap.erase(pluginName); }

std::vector<std::string> getPluginList() { static std::map<std::string, std::function<void()>> pluginMap; std::vector<std::string> result; for (const auto& [pluginName, _] : pluginMap) { result.push_back(pluginName); } return result; }

void callPlugin(const std::string& pluginName) {
  static std::map<std::string, std::function<void()>> pluginMap;
  if (pluginMap.find(pluginName) != pluginMap.end()) {
    pluginMap[pluginName]();
  } else {
    throw std::runtime_error("Plugin not found");
  }
}

std::string getPluginDocumentation(const std::string& pluginName) {
  static std::map<std::string, std::string> documentationMap;
  if (documentationMap.find(pluginName) != documentationMap.end()) {
    return documentationMap[pluginName];
  } else {
    throw std::runtime_error("Plugin not found");
  }
}

