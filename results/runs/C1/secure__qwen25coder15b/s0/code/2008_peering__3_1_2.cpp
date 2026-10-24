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

struct ResourceInfo {
  bool isNew;
};

void registerResource(const ResourceInfo& info);
void updateResource(const ResourceInfo& info);
void requestResources(const ResourceInfo& info);
void encapsulateSR(const ResourceInfo& info);

void registerResource(const ResourceInfo& info) {
  if (info.isNew) {
    updateResource(info);
  } else {
    updateResource(info);
  }
}

void updateResource(const ResourceInfo& info) {
  if (info.isNew) {
    registerResource(info);
  } else {
    updateResource(info);
  }
}

void requestResources(const ResourceInfo& info) { if (info.isNew) { registerResource(info); } else { updateResource(info); } }

void encapsulateSR(const ResourceInfo& info) { if (info.isNew) { registerResource(info); } else { updateResource(info); } }

