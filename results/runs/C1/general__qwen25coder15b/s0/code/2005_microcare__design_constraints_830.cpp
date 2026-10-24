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

bool is_system_admin() const; void save_user_info(const std::string& group_name, const std::string& user_name, const std::string& password);

void create_user_group(const std::string& group_name, const std::string& user_name, const std::string& password, const std::string& verify_password);
void create_user(const std::string& user_name, const std::string& password, const std::string& verify_password);

void create_user_group(const std::string& group_name, const std::string& user_name, const std::string& password, const std::string& verify_password) {
  if (!is_system_admin()) {
    return;
  }
  if (password != verify_password) {
    return;
  }
  save_user_info(group_name, user_name, password);
}

void create_user(const std::string& user_name, const std::string& password, const std::string& verify_password) {
  if (!is_system_admin()) {
    return;
  }
  if (password != verify_password) {
    return;
  }
  save_user_info(user_name, password);
}

