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

Plugin* createPlugin(const std::string& pluginName, const std::vector<std::string>& pluginFeatures);
void registerPlugin(Plugin* plugin);
Plugin* getPluginByName(const std::string& pluginName);
void updatePlugin(Plugin* plugin, const std::vector<std::string>& newFeatures);
void deletePlugin(Plugin* plugin);

class Plugin {
public:
  Plugin(const std::string& name, const std::vector<std::string>& features)
    : name(name), features(features) {}

  std::string name;
  std::vector<std::string> features;
};

Plugin* createPlugin(const std::string& pluginName, const std::vector<std::string>& pluginFeatures) {
  return new Plugin(pluginName, pluginFeatures);
}

void registerPlugin(Plugin* plugin) {
  plugins.push_back(plugin);
}

Plugin* getPluginByName(const std::string& pluginName) {
  for (auto plugin : plugins) {
    if (plugin->name == pluginName) {
      return plugin;
    }
  }
  return nullptr;
}

void updatePlugin(Plugin* plugin, const std::vector<std::string>& newFeatures) {
  if (plugin) {
    plugin->features = newFeatures;
  }
}

void deletePlugin(Plugin* plugin) {
  if (plugin) {
    auto it = std::find(plugins.begin(), plugins.end(), plugin);
    if (it != plugins.end()) {
      plugins.erase(it);
    }
  }
}

