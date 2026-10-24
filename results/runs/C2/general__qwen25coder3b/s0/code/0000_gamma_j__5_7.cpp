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

void registerPlugin(Plugin* plugin) { return; }

void updatePlugin(Plugin* plugin) { plugin->update(); }

class Plugin {
public:
  virtual ~Plugin() {}
  virtual void update() = 0;
};

class GammaJWebStore {
private:
  std::vector<Plugin*> plugins;
  std::vector<std::string> changes;

public:
  void registerPlugin(Plugin* plugin) { plugins.push_back(plugin); }
  void updatePlugin(Plugin* plugin) { plugin->update(); }
  void logChange(const std::string& changeDescription) { changes.push_back(changeDescription); }
  void upgradeSystem() {
    for (auto& plugin : plugins) {
      updatePlugin(plugin);
    }
    logChange("System upgraded to latest version.");
  }
};

class GammaJWebStore {
private:
  std::vector<Plugin*> plugins;
  std::vector<std::string> changes;

public:
  void registerPlugin(Plugin* plugin) { plugins.push_back(plugin); }
  void updatePlugin(Plugin* plugin) { plugin->update(); }
  void logChange(const std::string& changeDescription) { changes.push_back(changeDescription); }
  void upgradeSystem() {
    for (auto& plugin : plugins) {
      updatePlugin(plugin);
    }
    logChange("System upgraded to latest version.");
  }
};

