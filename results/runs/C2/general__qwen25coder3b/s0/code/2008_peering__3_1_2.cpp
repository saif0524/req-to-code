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

ResourceInfo update_service_info(ResourceInfo& resourceInfo) { resourceInfo.update(); return resourceInfo; }

struct ResourceInfo { int id; std::string name; }; ResourceInfo get_local_resource_info() { return ResourceInfo{1, "LocalResource"}; }

SRInstance get_encapsulated_sr_instance(PeeringInfo& peeringInfo) { return peeringInfo.get_encapsulated_sr_instance(); }

bool trigger_service_registration(ResourceInfo& resourceInfo, PeeringInfo& peeringInfo) { return false; }

