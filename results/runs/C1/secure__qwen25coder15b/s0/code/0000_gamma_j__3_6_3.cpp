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

struct PluginInfo {
  std::string name;
  std::string version;
  std::string description;
};
std::vector<PluginInfo> plugins;
struct PluginRequest {
  std::string pluginName;
  std::string method;
  std::map<std::string, std::string> params;
};

void registerPlugin(const std::string& pluginName, const std::string& pluginVersion, const std::string& pluginDescription);
void unregisterPlugin(const std::string& pluginName);
PluginInfo getPluginInfo(const std::string& pluginName);
std::vector<PluginInfo> listPlugins();
void processPluginRequest(const PluginRequest& request);

void registerPlugin(const std::string& pluginName, const std::string& pluginVersion, const std::string& pluginDescription) {
  // Create a new PluginInfo object with the provided parameters
  PluginInfo pluginInfo(pluginName, pluginVersion, pluginDescription);

  // Add the new plugin to the system
  plugins.push_back(pluginInfo);
}

void unregisterPlugin(const std::string& pluginName) {
  // Search for the plugin in the list of plugins
  auto it = std::find(plugins.begin(), plugins.end(), pluginName);

  // If the plugin is found, remove it from the list
  if (it != plugins.end()) {
    plugins.erase(it);
  } else {
    // Return a message indicating that the plugin was not found
    return "Plugin not found";
  }
}

PluginInfo getPluginInfo(const std::string& pluginName) {
  // Search for the plugin in the list of plugins
  auto it = std::find(plugins.begin(), plugins.end(), pluginName);

  // If the plugin is found, create a PluginInfo object with the provided parameters and return it
  if (it != plugins.end()) {
    return PluginInfo(pluginName, plugins[it - plugins.begin()].version, plugins[it - plugins.begin()].description);
  } else {
    // Return a message indicating that the plugin was not found
    return "Plugin not found";
  }
}

std::vector<PluginInfo> listPlugins() const {  std::vector<PluginInfo> plugins;  for (const auto& plugin : this->plugins) {    plugins.push_back(PluginInfo(plugin.name, plugin.version, plugin.description));  }  return plugins; }

void processPluginRequest(const PluginRequest& request) {
  // Check if the plugin exists in the system
  auto it = std::find(plugins.begin(), plugins.end(), request.pluginName);

  // If the plugin does not exist, return a message indicating that the plugin was not found
  if (it == plugins.end()) {
    return Json::object({
      "status": "failure",
      "message": "Plugin not found"
    });
  }

  // If the plugin exists, process the request by calling the appropriate method on the plugin object
  switch (request.method) {
    case "GET":
      return it->second->get(request.params);
    case "POST":
      return it->second->post(request.params);
    case "PUT":
      return it->second->put(request.params);
    case "DELETE":
      return it->second->delete(request.params);
    default:
      return Json::object({
        "status": "failure",
        "message": "Invalid method"
      });
  }
}

