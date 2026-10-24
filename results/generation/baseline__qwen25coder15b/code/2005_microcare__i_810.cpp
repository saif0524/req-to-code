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

std::string get_vsp_code(const VSPMaster& vsp_master);
std::string get_vsp_name(const VSPMaster& vsp_master);
std::string get_physical_address(const VSPMaster& vsp_master);
std::string get_communication_address(const VSPMaster& vsp_master);
std::string get_health_sub_district(const VSPMaster& vsp_master);

std::string get_vsp_code(const VSPMaster& vsp_master) { return vsp_master.vsp_code; }

std::string get_vsp_name(const VSPMaster& vsp_master) { return vsp_master.vsp_name; }

std::string get_physical_address(const VSPMaster& vsp_master) { return vsp_master.physical_address; }

std::string get_communication_address(const VSPMaster& vsp_master) { return vsp_master.physical_address; }

std::string get_health_sub_district(const VSPMaster& vsp_master) { return vsp_master.health_sub_district; }

