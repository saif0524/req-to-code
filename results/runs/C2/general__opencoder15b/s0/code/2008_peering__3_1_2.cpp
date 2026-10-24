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

void registerService(const std::string& serviceName, const std::string& serviceType, const std::string& serviceDescription);
void updateResourceInfo(const std::string& resourceId, const std::string& resourceType, const std::string& resourceDescription);
void requestLocalResourceInfo(const std::string& resourceId);
void wrapResourceInfo(const std::string& resourceId, const std::string& resourceInfo);
void unregisterService(const std::string& serviceId);

void registerService(const std::string& serviceName, const std::string& serviceType, const std::string& serviceDescription) {
    // Create a new service object
    Service service(serviceName, serviceType, serviceDescription);
    // Add the service object to the network's service registry
    network.addService(service);
}

void updateResourceInfo(const std::string& resourceId, const std::string& resourceType, const std::string& resourceDescription) {
     // Update the resource information for the given resource ID
     Resource resource(resourceId, resourceType, resourceDescription);
     // Add the updated resource information to the network's resource registry
     network.addResource(resource);
}

void requestLocalResourceInfo(const std::string& resourceId) {
      // Retrieve the local resource information for the given resource ID
      ResourceInfo resourceInfo = network.getLocalResourceInfo(resourceId);

      // Wrap the local and delegated external resource information in an SR instance
      SR sr(resourceId, resourceInfo);

      // Return JSON object of the SR instance
      return sr.toJson();
}

void wrapResourceInfo(const std::string& resourceId, const std::string& resourceInfo) {
  SR sr(resourceId, resourceInfo);
  // Return the JSON object of the SR instance
  return sr.toJson();
}

void unregisterService(const std::string& serviceId) {
      // Check if the service exists in the network's service registry
      if (network.hasService(serviceId)) {
         // Remove the service from the network's service registry
         network.removeService(serviceId);
         // Return a JSON object indicating the successful unregistration
         return Json::object({{{"status", "success"}});
     }
     // Return a JSON object indicating the failure to unregister the service
     return Json::object({{{"status", "failure"}});
}

