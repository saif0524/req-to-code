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

struct DistributorMaster;

std::string get_distributor_code();
std::string get_distributor_name();
std::string get_distributor_type();
std::string get_distributor_proprietor_name();
std::string get_distributor_designation();

std::string distributor_code; std::string get_distributor_code() { return distributor_code; }

std::string distributor_name; std::string get_distributor_name() { return distributor_name; }

struct DistributorMaster {
  std::string distributor_code;
  std::string distributor_name;
  std::string distributor_type;
  std::string distributor_proprietor_name;
  std::string distributor_designation;

  std::string get_distributor_type() { return distributor_type; }
};

struct DistributorMaster {
  std::string distributor_code;
  std::string distributor_name;
  std::string distributor_type;
  std::string distributor_proprietor_name;
  std::string distributor_designation;

  std::string get_distributor_type() { return distributor_type; }
};
std::string get_distributor_proprietor_name() { return distributor_proprietor_name; }

struct DistributorMaster {  std::string distributor_code;  std::string distributor_name;  std::string distributor_type;  std::string distributor_proprietor_name;  std::string distributor_designation;  std::string get_distributor_type() { return distributor_type; } };

