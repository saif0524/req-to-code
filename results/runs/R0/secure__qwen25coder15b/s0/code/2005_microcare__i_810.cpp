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

std::string get_vsp_code(const std::string& vsp_master);
std::string get_vsp_name(const std::string& vsp_master);
std::string get_physical_address(const std::string& vsp_master);
std::string get_communication_address(const std::string& vsp_master);
std::string get_health_sub_district(const std::string& vsp_master);

std::string get_vsp_code(const std::string& vsp_master) {
  size_t pos = vsp_master.find('VSP Code:');
  if (pos != std::string::npos) {
    pos += 9; // Skip 'VSP Code: ' to get the start of the VSP code
    size_t end = vsp_master.find(',', pos);
    if (end != std::string::npos) {
      return vsp_master.substr(pos, end - pos);
    }
  }
  return "VSP code not found";
}

std::string get_vsp_name(const std::string& vsp_master) {
  size_t pos = vsp_master.find('VSP Code:');
  if (pos != std::string::npos) {
    pos += 9; // Skip 'VSP Code: ' to get the start of the VSP code
    size_t end = vsp_master.find(',', pos);
    if (end != std::string::npos) {
      return vsp_master.substr(pos, end - pos);
    }
  }
  return "VSP code not found";
}

std::string get_physical_address(const std::string& vsp_master) {
  size_t pos = vsp_master.find('VSP Code:');
  if (pos != std::string::npos) {
    pos += 9; // Skip 'VSP Code: ' to get the start of the VSP code
    size_t end = vsp_master.find(',', pos);
    if (end != std::string::npos) {
      pos = end + 1; // Skip the comma after the VSP code
      size_t end2 = vsp_master.find(',', pos);
      if (end2 != std::string::npos) {
        return vsp_master.substr(pos, end2 - pos);
      }
    }
  }
  return "VSP code not found";
}

std::string get_communication_address(const std::string& vsp_master) {
  size_t pos = vsp_master.find('VSP Code:');
  if (pos != std::string::npos) {
    pos += 9; // Skip 'VSP Code: ' to get the start of the VSP code
    size_t end = vsp_master.find(',', pos);
    if (end != std::string::npos) {
      pos = end + 1; // Skip the comma after the VSP code
      size_t end2 = vsp_master.find(',', pos);
      if (end2 != std::string::npos) {
        return vsp_master.substr(pos, end2 - pos);
      }
    }
  }
  return "VSP code not found";
}

std::string get_health_sub_district(const std::string& vsp_master) {
  size_t pos = vsp_master.find('Health Sub-District:');
  if (pos != std::string::npos) {
    pos += 17; // Skip 'Health Sub-District: ' to get the start of the health sub-district
    size_t end = vsp_master.find(',', pos);
    if (end != std::string::npos) {
      return vsp_master.substr(pos, end - pos);
    }
  }
  return "Health sub-district not found";
}

