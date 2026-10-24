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

std::function<std::string(std::string resource)> fetchAndUpdateResource;
std::function<bool(std::string resource>> checkLocalResourceAvailable;

static string latestResource = "";

string fetchAndUpdateResource(string resource) {
    if (!latestResource.empty()) {
        latestResource = resource;
    }
    return latestResource;
 }

static function<bool(string resource>> checkLocalResourceAvailable {
  if (!latestResource.empty()) {
    return latestResource == resource;
  }
  return false;
  }

