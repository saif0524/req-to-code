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

std::vector<std::string> get_coe_components();
std::vector<std::string> get_interface_details();

class InternalInterfaces {
public:
  const std::vector<std::string> get_coe_components() const {
    static const std::vector<std::string> coe_components = {
      "Component1",
      "Component2",
      "Component3"
    };
    return coe_components;
  }
};

std::vector<std::string> get_interface_details() { static std::vector<std::string> interface_details = { "Detailed information about interface 1", "Detailed information about interface 2", "Detailed information about interface 3" }; return interface_details; }

