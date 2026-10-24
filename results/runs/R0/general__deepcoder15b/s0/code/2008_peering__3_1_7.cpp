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
    

bool check_resourceAllocation(std::object resource) {
  if (resource == nullptr) {
    return false;
  }
  return true;
  }

bool reserveResource(object resource, int time) {
    return (time <= resource_time);
    }

struct ResourceFailureReason {
    int status; // 0: valid, 1: invalid, -1: unknown
    string reason; // brief explanation
}

void handleResourceFailure(std::string resource, std::string message)
{
    ResourceFailureReason res;

    if (resource == nullptr)
    {
        res.status = -1;
        res.reason = 

std::map<int, std::string> resource_type_map = {
    {0, "string"},
    {1, "integer"},
    {-1, "boolean"}
};

std::object getResourceType(std::object resource)
{
    if (resource == nullptr)
    {
        return std::object{};
    }
    
    const ResourceFailureReason& rfr = ResourceFailureReason::getResourceFailureReasonForType(resource);
    
    if (rfr)
    {
        int status = rfr.status;
        return resource_type_map.find(status).second;
    }
    
    return resource;
}

