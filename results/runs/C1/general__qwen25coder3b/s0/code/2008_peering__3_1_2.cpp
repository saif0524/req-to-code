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

void register_service(ResourceInfo& resourceInfo);
void update_service_info(ResourceInfo& resourceInfo);
ResourceInfo get_local_resource_info();
SRInstance get_encapsulated_sr_instance(PeeringInfo& peeringInfo);
void trigger_service_registration(ResourceInfo& resourceInfo, PeeringInfo& peeringInfo);

void register_service(ResourceInfo& resourceInfo) { register_service(resourceInfo); }

void update_service_info(ResourceInfo& resourceInfo) { update_service_info(resourceInfo); }

ResourceInfo get_local_resource_info() { return ResourceInfo(); }

SRInstance get_encapsulated_sr_instance(PeeringInfo& peeringInfo) { return peeringInfo.get_encapsulated_sr_instance(); }

bool trigger_service_registration(ResourceInfo& resourceInfo, PeeringInfo& peeringInfo) {
  if (resourceInfo.is_available_as_provider()) {
    register_service(resourceInfo);
    return true;
  } else if (resourceInfo.needs_update()) {
    update_service_info(resourceInfo);
    return true;
  } else if (resourceInfo.is_traffic_surge()) {
    get_local_resource_info();
    return true;
  } else if (peeringInfo.is_encapsulation_needed()) {
    get_encapsulated_sr_instance(peeringInfo);
    return true;
  }
  return false;
}

