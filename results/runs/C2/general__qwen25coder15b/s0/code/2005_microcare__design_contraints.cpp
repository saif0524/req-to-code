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

  std::string vsp_code = get_vsp_code(staff_type);
  std::string staff_code = generate_staff_code(vsp_code, staff_type);

  navigate_to_staff_type_master(staff_type);
}

std::string generate_staff_code(const std::string& vsp_code, const std::string& staff_type) {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  std::chrono::time_point::time_since_epoch time_since_epoch = now.time_since_epoch();
  std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(time_since_epoch);
  std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time_since_epoch % std::chrono::seconds(1));
  std::string formatted_time = std::to_string(seconds.count()) + '.' + std::to_string(milliseconds.count());
  return vsp_code + staff_type + formatted_time.substr(0, 3);
}

void navigate_to_staff_type_master() {
  StaffTypeMaster::navigate_to_staff_type_master();
}

