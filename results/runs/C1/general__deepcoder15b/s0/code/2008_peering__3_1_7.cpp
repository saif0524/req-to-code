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

// declarations for shared data
// Your added declarations here, if any needed

std::pair<std::vector<std::object>, std::vector<std::string>> handle_service-registration(std::string service_id);
bool check_resourceAllocation(std::object resource);
bool reserveResource(std::object resource, int time);
void handleResourceFailure(std::string resource, std::string message);
std::object getResourceType(std::object resource);

std::pair<std::vector<std::object>, std::vector<std::string>> handle_service-registration(std::string service_id) {
    std::vector<std::object> first_vector;
    std::string first_part = service_id.substr(0, 3);
    for (char c : first_part) {
        first_vector.push_back(std::object{c});
    }
    std::string second_part = service_id.substr(3);
    std::vector<std::string> second_vector;
    for (char c : second_part) {
        second_vector.push_back(std::string{c});
    }
    return std::make_pair(first_vector, second_vector);
    }
    

bool check_resourceAllocation(std::string resource) {
  if (resource == nullptr) {
    return false;
  }
  return true;
  }

bool reserveResource(object resource, int time) {
    return time <= resource_time;
}

void handleResourceFailure(std::string resource, std::string message) {
  ResourceFailureReason res;

  if (resource == nullptr) {
    res.status = -1;
    res.reason = "unknown resource failure"
    return;
  }

  res.status = 0;
  res.reason = "valid resource"
  return;
}

std::string getResourceType(std::object resource)
{
    if (resource == nullptr)
    {
        return "null"
    }
    
    const ResourceFailureReason& rfr = ResourceFailureReason::getResourceFailureReasonForType(resource);
    
    if (rfr)
    {
        int status = rfr.status;
        return resource_type_map.find(status).second;
    }
    
    return "unknown"
}

