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

bool validate_password(const std::string& password, const std::string& repeat_password);
void display_error_message(const std::string& message);

bool validate_password(const std::string& password, const std::string& repeat_password) {
  return password == repeat_password;
}

void display_error_message(const std::string& message) {
  std::cout << message << std::endl;
}

