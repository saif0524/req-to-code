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

bool validate_input(const std::string& input);
std::map<std::string, std::string> fetch_voucher_details(const std::string& voucher_code);
bool refund_voucher(const std::string& voucher_code);
bool update_voucher_status(const std::string& voucher_code, const std::string& status);

bool validate_input(const std::string& input) {
  std::vector<std::string> voucher_codes = {"voucher1", "voucher2", "voucher3", "voucher4", "voucher5", "voucher6"};
  for (const auto& code : voucher_codes) {
    if (input == code) {
      return true;
    }
  }
  return false;
}

std::map<std::string, std::string> fetch_voucher_details(const std::string& voucher_code) {
  std::vector<std::string> voucher_codes = {"voucher1", "voucher2", "voucher3", "voucher4", "voucher5", "voucher6"};
  for (const auto& code : voucher_codes) {
    if (voucher_code == code) {
      return true;
    }
  }
  return false;
}

bool refund_voucher(const std::string& voucher_code) {
   std::vector<std::string> voucher_codes = {"voucher1", "voucher2", "voucher3", "voucher4", "voucher5", "voucher6"};
   for (const auto& code : voucher_codes) {
     if (voucher_code == code) {
       return true;
     }
   }
   return false;
}

std::map<std::string, std::string> fetch_voucher_details(const std::string& voucher_code) {
   std::vector<std::string> voucher_codes = {"voucher1", "voucher2", "voucher3", "voucher4", "voucher5", "voucher6"};
   for (const auto& code : voucher_codes) {
     if (voucher_code == code) {
       return true;
     }
   }
   return false;
}

bool update_voucher_status(const std::string& voucher_code, const std::string& status) {
    std::vector<std::string> voucher_codes = {"voucher1", "voucher2", "voucher3", "voucher4", "voucher5", "voucher6"};
    for (const auto& code : voucher_codes) {
        if (voucher_code == code) {
            return true;
        }
    }
    return false;
}

