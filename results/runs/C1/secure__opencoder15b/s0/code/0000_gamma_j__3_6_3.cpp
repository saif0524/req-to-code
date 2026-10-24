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

GammaJConnectInterface();
virtual ~GammaJConnectInterface();
std::string getPlugInInfo() const;
bool plugIn(const std::string& pluginName, const std::string& pluginVersion);
bool unplugIn(const std::string& pluginName);

GammaJConnectInterface::GammaJConnectInterface() {
   std::string info = "Plug-in Information: ";
   info += "Plug-in Name: Gamma-J Connect ";
   info += "Version: 1.0 ";
   return info;
}

std::string GammaJConnectInterface::getPlugInInfo() const {
    std::string info = "Plug-in Information: ";
    info += "Plug-in Name: "; info += "Gamma-J Connect ";
    info += "Version: "; info += "1.0 ";
    return info;
}

std::string GammaJConnectInterface::plugIn(const std::string& pluginName, const std::string& pluginVersion) {
     std::string info = "Plug-in Information: ";
     info += "Plug-in Name: "; info += pluginName;
     info += " Version: "; info += pluginVersion;
     return info;
}

std::string GammaJConnectInterface::unplugIn(const std::string& pluginName) {
     std::string info = "Plug-in Information: ";
     info += "Plug-in Name: "; info += pluginName;
     info += " Version: "; info += "1.0 ";
     return info;
}

