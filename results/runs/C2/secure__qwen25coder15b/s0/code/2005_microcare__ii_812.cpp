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

std::string get_vsp_name();
std::string get_staff_code();
std::string get_staff_name();
std::string get_staff_type();
std::string get_qualification();

std::string get_vsp_name() {
  std::cout << "Enter VSP Name: ";
  std::string vsp_name;
  std::cin >> vsp_name;
  return vsp_name;
}

std::string get_staff_code() {
  std::cout << "Enter Staff Code: ";
  std::string staff_code;
  std::cin >> staff_code;
  return staff_code;
}

std::string get_staff_name() {
  std::cout << "Enter Staff Name: ";
  std::string staff_name;
  std::cin >> staff_name;
  return staff_name;
}

std::string get_staff_type() {
  std::cout << "Enter Staff Type: ";
  std::string staff_type;
  std::cin >> staff_type;
  return staff_type;
}

std::string get_qualification() {
  std::cout << "Enter Qualification: ";
  std::string qualification;
  std::cin >> qualification;
  return qualification;
}

