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

void registerPlugIn(std::string name, std::string description, std::string version, std::string author, std::string email, std::string website, std::string apiVersion, std::string descriptionFile, std::string iconFile);
std::vector<std::string> getPlugInList();
std::string getPlugInInfo(std::string name);
std::string callPlugInFunction(std::string name, std::string functionName, std::string parameters);
std::string getSharedDeclarations();

void registerPlugIn(std::string name, std::string description, std::string version, std::string author, std::string email, std::string website, std::string apiVersion, std::string descriptionFile, std::string iconFile) {
  // Create a new PlugIn object with the provided parameters
  PlugIn plugIn(name, description, version, author, email, website, apiVersion, descriptionFile, iconFile);

  // Add the plug-in to the system's registry
  systemRegistry.addPlugIn(plugIn);

  // Return a JSON string with a success message
  return "{" + name + ": {"success": true}";
}

std::vector<std::string> getPlugInList() {
   std::vector<std::string> plugInList;
   for (auto& plugIn : systemRegistry.getPlugIns()) {
      plugInList.push_back(plugIn.getName());
   }
   return plugInList;
}

std::string getPlugInInfo(std::string name) {
    PlugIn* plugIn = systemRegistry.getPlugIn(name);
    if (plugIn == nullptr) {
        return "{error: Plug-in not found}";
    }
    return "{name: " + plugIn->getName() + ", description: " + plugIn->getDescription() + ", version: " + plugIn->getVersion() + ", author: " + plugIn->getAuthor() + ", email: " + plugIn->getEmail() + ", website: " + plugIn->getWebsite() + ", apiVersion: " + plugIn->getApiVersion() + ", descriptionFile: " + plugIn->getDescriptionFile() + ", iconFile: " + plugIn->getIconFile() + "}";
}

std::string callPlugInFunction(std::string name, std::string functionName, std::string parameters) {
   PlugIn* plugIn = systemRegistry.getPlugIn(name);
   if (plugIn == nullptr) {
       return "{error: Plug-in not found}";
   }
   // Call the function from the plug-in
   std::string result = plugIn->callFunction(functionName, parameters);
   return result;
}

std::string getSharedDeclarations() {
    std::string declarations = "{");
    for (auto& declaration : systemRegistry.getSharedDeclarations()) {
        declarations += declaration + ", ";
    }
    declarations += "}";
    return declarations;
}

