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

std::string get_vsp_name( std::string claim );
bool is_st_code_valid( std::string code );
std::string get_st_name( std::string code, std::string name );
bool is_st_type_valid( std::string type );
bool is_qualification_valid( std::string qualification );

std::string get_vsp_name(std::string claim) {
    std::stringstream ss(claim);
    std::string name = ss.str();
    return name;
    }

bool is_st_code_valid(std::string code) {
  return (code.empty() || code.length() < 1 || code.length() > 100);
}

bool is_st_type_valid(std::string type) {
  return (type.empty() || type.length() < 1 || type.length() > 1);
}

bool is_st_name_valid(std::string name, std::string code) {
  std::stringstream ss(code);
  std::string name_part;
  std::getline(ss, name_part, ' ');
  return (name_part == name);
}

std::string get_st_name(std::string code, std::string name) { std::stringstream ss(code); std::string name_part; std::getline(ss, name_part, ' '); return name_part; }

bool is_st_type_valid(std::string type) {
  if (type.empty() || type.length() < 1 || type.length() > 100) {
    return false;
  }
  return true;
  }

bool is_qualification_valid(std::string qualification) {
    if (qualification.empty()) {
        return false;
    }
    if (qualification.length() < 1 || qualification.length() > 100) {
        return false;
    }
    return true;
    }
    

