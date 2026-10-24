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
  // Your implementation here
  return "{" + "service_name": " + service_name + ", "service_description": " + service_description + ", "protocol": " + protocol + "}";\n}

