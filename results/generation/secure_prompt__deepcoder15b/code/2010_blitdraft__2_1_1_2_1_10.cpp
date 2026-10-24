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

std::array<User, 1> User Users[1]
struct User { int ID; char Role[2]; }

std::string CheckUserStatus(User user) -> std::string;

std::string CheckUserStatus(User user) -> std::string {
  int user_id = user.ID;
  if (user_id < 1 || user_id > 99999) {
    return "Error: User ID is invalid. ID must be between 1 and 99999.";
  }
  char role[2];
  if (user.Role != "Active" && user.Role != "Inactive") {
    return "Error: Role is invalid. Role must be 'Active' or 'Inactive'.\n};\nreturn "User status verified. User is active/inactive as expected."\n}

