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

std::map<std::string, std::string> pluginMap;

std::string buildCustomPlugin(const std::string& pluginName, const std::vector<std::string>& pluginFeatures);
bool validatePluginName(const std::string& pluginName);
bool validatePluginFeatures(const std::vector<std::string>& pluginFeatures);
void registerPlugin(const std::string& pluginName, const std::string& pluginCode);
std::string getPluginCode(const std::string& pluginName);

std::string buildCustomPlugin(const std::string& pluginName, const std::vector<std::string>& pluginFeatures) {
  if (!validatePluginName(pluginName)) {
    return "Invalid plugin name";
  }
  if (!validatePluginFeatures(pluginFeatures)) {
    return "Invalid plugin features";
  }
  std::string pluginCode = pluginName + "_";
  for (const auto& feature : pluginFeatures) {
    pluginCode += feature + ";";
  }
  return pluginCode;
}

bool validatePluginName(const std::string& pluginName) {
  if (pluginName.empty()) {
    return false;
  }
  if (!std::all_of(pluginName.begin(), pluginName.end(), [](char c) { return std::isalnum(c) || c == '_'; })) {
    return false;
  }
  if (pluginName.length() > 50) {
    return false;
  }
  return true;
}

bool validatePluginFeatures(const std::vector<std::string>& pluginFeatures) { if (pluginFeatures.empty()) { return false; } for (const auto& feature : pluginFeatures) { if (!validatePluginFeatures(feature)) { return false; } } return true; }

void registerPlugin(const std::string& pluginName, const std::string& pluginCode) {
  if (!validatePluginName(pluginName)) {
    return;
  }
  if (!validatePluginFeatures(pluginFeatures)) {
    return;
  }
  pluginMap[pluginName] = pluginCode;
}

std::string getPluginCode(const std::string& pluginName) { if (!validatePluginName(pluginName)) { return ""; } return pluginMap[pluginName]; }

