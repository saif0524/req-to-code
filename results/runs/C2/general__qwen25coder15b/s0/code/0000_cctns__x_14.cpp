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

class MyClass {
public:
  bool is_admin();
  bool check_access_control(const std::string& user, const std::string& case_id);
  void set_access_control(const std::string& user, const std::string& group, bool is_admin);
};

void set_access_control(const std::string& user, const std::string& group, bool is_admin);
void add_user_to_group(const std::string& user, const std::string& group);
void remove_user_from_group(const std::string& user, const std::string& group);
void set_case_access(const std::string& user, const std::string& case_id, bool can_access);
bool check_case_access(const std::string& user, const std::string& case_id);

void set_access_control(const std::string& user, const std::string& group, bool is_admin) {
  if (is_admin) {
    add_user_to_group(user, group);
  }
}

void add_user_to_group(const std::string& user, const std::string& group) {
  if (is_admin()) {
    add_user_to_group(user, group);
  }
}

void remove_user_from_group(const std::string& user, const std::string& group) {
  if (!is_admin()) {
    return;
  }
  remove_user_from_group(user, group);
}

void set_case_access(const std::string& user, const std::string& case_id, bool can_access) {
  MyClass my_class;
  if (my_class.is_admin()) {
    my_class.set_access_control(user, case_id, can_access);
  }
}

bool check_case_access(const std::string& user, const std::string& case_id) {
  if (is_admin()) {
    return check_access_control(user, case_id);
  } else {
    return false;
  }
}

