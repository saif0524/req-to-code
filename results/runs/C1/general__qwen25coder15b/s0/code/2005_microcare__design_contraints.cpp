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

bool validate_staff_name(const std::string& name);
void create_staff(const std::string& name, const std::string& qualification, const std::string& staff_type);
std::string generate_staff_code(const std::string& vsp_code, const std::string& staff_type);
void navigate_to_staff_type_master();

bool validate_staff_name(const std::string& name) {
  return staff_name_exists(name);
}

void create_staff(const std::string& name, const std::string& qualification, const std::string& staff_type) {
  if (validate_staff_name(name)) {
    return "Staff name already exists";
  }

  std::string vsp_code = get_vsp_code();
  std::string staff_code = generate_staff_code(vsp_code, staff_type);

  navigate_to_staff_type_master(staff_type);
}

std::string generate_staff_code(const std::string& vsp_code, const std::string& staff_type) {
  std::time_t current_time = std::time(nullptr);
  std::string current_date_time = std::ctime(&current_time);
  return vsp_code + staff_type + current_date_time.substr(0, 3);
}

