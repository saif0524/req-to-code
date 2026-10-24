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

registerService(std::string service_name, std::string service_description, std::string protocol);

std::string registerService(std::string service_name, std::string service_description, std::string protocol) {
  // Implementation of the function
  // Add the service to the SR-mediator's service registry
  // Return a JSON object with the 'code' property
  return "{" + "code": "Service registered successfully" + "}";
}

