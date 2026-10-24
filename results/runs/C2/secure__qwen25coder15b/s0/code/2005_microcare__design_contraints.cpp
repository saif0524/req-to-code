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

struct staff_type_master; using staff_type_master_t = staff_type_master; extern staff_type_master_t staff_type_master;

bool validate_staff_name(const std::string& name, const std::string& existing_name);
std::string create_staff_code(const std::string& vsp_code, const std::string& sc);
std::vector<std::string> get_staff_type_list();
void navigate_to_staff_type_master();

bool validate_staff_name(const std::string& name, const std::string& existing_name) {
  if (name == existing_name) {
    return false;
  }
  return true;
}

std::string create_staff_code(const std::string& vsp_code, const std::string& sc) {
  if (!validate_staff_name(name, existing_name)) {
    return "Error: Staff name already exists.";
  }
  std::string staff_code = vsp_code + sc + std::to_string(vsp_code.back() % 10) + std::to_string(sc.back() % 10);
  return staff_code;
}

std::vector<std::string> get_staff_type_list() {  return staff_type_master::get_staff_type_list(); }

void navigate_to_staff_type_master() {
  // Display a message or navigate to the Staff Type Master screen
  std::cout << "Navigate to Staff Type Master to select a new staff type." << std::endl;
}

