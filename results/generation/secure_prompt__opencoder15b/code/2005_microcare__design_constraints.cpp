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

create_voucher(std::string voucher_name, int quantity, int min_quantity, std::string expiry_date);
prepare_voucher(int voucher_id, std::string new_expiry_date);
hold_voucher(int voucher_id);
amend_voucher(int voucher_id, std::string new_expiry_date);
validate_input(std::string voucher_name, int quantity, int min_quantity, std::string expiry_date);

void create_voucher(std::string voucher_name, int quantity, int min_quantity, std::string expiry_date) {
  // Your implementation here
}

void prepare_voucher(int voucher_id, std::string new_expiry_date) {
  // Validate the input
  if (voucher_id < 1 || !std::regex_match(new_expiry_date, std::regex(R"((3[01]|[12][0-9]|0[1-9]|1[0-9]|2[0-9]|3[01])[-](1[0-2]|0[1-9])[-](?:[0-9]{2})?[0-9]{3})"))) {
    // Return an error message or throw an exception
  }
  // Update the expiry date of the voucher
  // Your implementation here
}

void hold_voucher(int voucher_id) { 
   // Your implementation here 
}

void amend_voucher(int voucher_id, std::string new_expiry_date) { 
    // Validate the input
    if (voucher_id < 1 || !std::regex_match(new_expiry_date, std::regex(R"(3[01]|[12][0-9]|0[1-9]|1[0-9]|2[0-9]|3[01])[-](1[0-2]|0[1-9])[-](?:[0-9]{2})?[0-9]{3} )"))) { 
        // Return an error message or throw an exception
    } 
    // Update the expiry date of the voucher
    // Your implementation here
}

void validate_input(std::string voucher_name, int quantity, int min_quantity, std::string expiry_date) { 
   if (voucher_name.empty() || voucher_name.find_first_of("~!@#$%^&*()_+=-`|\";:<>,./?[\n] ") != std::string::npos) { 
      return "Invalid voucher name"; 
   } 
   if (quantity < min_quantity) { 
      return "Quantity is too low"; 
   } 
   if (!std::regex_match(expiry_date, std::regex(R"((3[01]|[12][0-9]|0[1-9]|1[0-9]|2[0-9]|3[01])[-](1[0-2]|0[1-9])[-](?:[0-9]{2})?[0-9]{3})"))) { 
      return "Invalid expiry date"; 
   } 
   return "Success"; 
}

