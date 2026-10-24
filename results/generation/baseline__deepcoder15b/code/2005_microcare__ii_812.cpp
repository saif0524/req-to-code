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

std::string get_vsp_name(std::string claim) {
  std::stringstream ss(claim);
  std::string name;
  std::getline(ss, name, 0);
  return name;
  }

bool is_st_code_valid(std::string code) {
  int len = code.length();
  return (len >= 1 && len <= 100);
  },
  

std::string get_st_name(std::string code, std::string name) {
  std::stringstream ss(code);
  std::string name_part;
  std::getline(ss, name_part, ' ');
  return name_part;
  },
  

