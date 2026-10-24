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
std::string wrapResourceInfo(const std::string& resourceInfo);

std::string wrapResourceInfo(const std::string& resourceInfo) {
  // Create an SR instance with the resource information
  Json::Value srInstance;
  srInstance["resourceInfo"] = resourceInfo;
  // Serialize the SR instance to a JSON string
  std::string srInstanceJson = srInstance.toStyledString();
  return srInstanceJson;
}

