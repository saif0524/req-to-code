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

using ResourcePtr = std::shared_ptr<Resource>; std::vector<ResourcePtr> resources;
struct SRInstance;
std::vector<SRInstance> srInstances;

void registerResource(const Resource& resource);
void updateResource(const Resource& resource);
void requestLocalResources(const Resource& resource);
void encapsulateSRInstance(const Resource& resource);

void registerResource(const Resource& resource) {
  bool found = false;
  for (const auto& r : resources) {
    if (r == resource) {
      r.update(resource);
      found = true;
      break;
    }
  }
  if (!found) {
    resources.push_back(resource);
  }
}

void updateResource(const Resource& resource) {
  bool found = false;
  for (const auto& r : resources) {
    if (r == resource) {
      r.update(resource);
      found = true;
      break;
    }
  }
  if (!found) {
    return;
  }
}

void requestLocalResources(const Resource& resource) {
  bool found = false;
  for (const auto& r : resources) {
    if (r == resource) {
      r.requestLocalResources();
      found = true;
      break;
    }
  }
  if (!found) {
    return;
  }
}

struct SRInstance {
  Resource resource;
  char status;
};

void encapsulateSRInstance(const Resource& resource) {
  SRInstance srInstance;
  srInstance.resource = resource;
  srInstance.status = 'pending';
  srInstances.push_back(srInstance);
}

