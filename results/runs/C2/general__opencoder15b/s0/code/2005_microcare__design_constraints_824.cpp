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

bool check_voucher_sold(int distributor_id, int voucher_id);
bool validate_sales_return(int distributor_id, int voucher_id);
std::string get_sales_return_details(int distributor_id, int voucher_id);
bool update_sales_return(int distributor_id, int voucher_id, std::string return_date);
std::string get_sales_return(int distributor_id);

bool check_voucher_sold(int distributor_id, int voucher_id) {
     std::vector<std::string> sales_returns = get_sales_return(distributor_id);
     for (std::string sr : sales_returns) {
         std::vector<int> voucher_details = split_string(sr, " ");
         if (voucher_details[0] == voucher_id) {
             return false;
         }
     }
     return true;
}

bool validate_sales_return(int distributor_id, int voucher_id) {
     std::vector<std::string> sales_returns = get_sales_return(distributor_id);
     for (std::string sr : sales_returns) {
         std::vector<int> voucher_details = split_string(sr, " ");
         if (voucher_details[0] == voucher_id) {
             return false;
         }
     }
     return true;
}

std::string get_sales_return_details(int distributor_id, int voucher_id) {
     std::string sales_return = get_sales_return(distributor_id);
     std::vector<std::string> voucher_details = split_string(sales_return, " ");
     for (std::string sr : voucher_details) {
         std::vector<int> details = split_string(sr, " ");
         if (details[0] == voucher_id) {
             return "Voucher not found in sales return";
         }
     }
     return "";
}

bool update_sales_return(int distributor_id, int voucher_id, std::string return_date) {
  if (!check_voucher_sold(distributor_id, voucher_id)) {
    std::string sales_return = get_sales_return(distributor_id);
    std::vector<std::string> voucher_details = split_string(sales_return, " ");
    for (std::string sr : voucher_details) {
      std::vector<int> details = split_string(sr, " ");
      if (details[0] == voucher_id) {
        return false;
      }
    }
    return true;
  }
  return false;
}

std::string get_sales_return(int distributor_id) {
     std::string sales_return = get_sales_return(distributor_id);
     std::vector<std::string> voucher_details = split_string(sales_return, " ");
     for (std::string sr : voucher_details) {
         std::vector<int> details = split_string(sr, " ");
         if (details[0] == voucher_id) {
             return "Voucher not found in sales return";
         }
     }
     return "";
}

