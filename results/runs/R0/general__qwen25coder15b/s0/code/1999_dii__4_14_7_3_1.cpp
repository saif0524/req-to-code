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

std::vector<CoeComponentInfo> get_coe_component_info(const std::string& component_name);
void update_coe_component_info(const std::string& component_name, const CoeComponentInfo& new_info);
std::vector<CoeComponentInfo> list_coe_components();
void create_coe_component(const CoeComponentInfo& new_info);
void delete_coe_component(const std::string& component_name);

std::vector<CoeComponentInfo> get_coe_component_info(const std::string& component_name) {
  return get_coe_component_info(component_name);
}

void update_coe_component_info(const std::string& component_name, const CoeComponentInfo& new_info) {
  CoeComponentInfo existing_info = get_coe_component_info(component_name);
  if (existing_info.empty()) {
    delete_coe_component(component_name);
    create_coe_component(new_info);
  } else {
    existing_info = new_info;
    create_coe_component(existing_info);
  }
}

std::vector<CoeComponentInfo> list_coe_components() {
  std::vector<CoeComponentInfo> coe_components = get_coe_component_info("*");
  return coe_components;
}

void create_coe_component(const CoeComponentInfo& new_info) {
  delete_coe_component(new_info.component_name);
  create_coe_component(new_info);
}

void delete_coe_component(const std::string& component_name) {
  CoeComponentInfo existing_info = get_coe_component_info(component_name);
  if (!existing_info.empty()) {
    existing_info = get_coe_component_info(component_name);
    update_coe_component_info(component_name, existing_info);
    create_coe_component(existing_info);
  }
}

