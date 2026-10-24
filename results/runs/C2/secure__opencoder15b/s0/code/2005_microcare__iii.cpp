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

void CaptureVoucherDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment);
std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsByDistributor(const std::string& distributor_name);
std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsBySalesman(const std::string& salesman_name);
std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsByBatchNo(const std::string& batch_no);
void AllocateVouchers(const std::string& distributor_name, const std::string& salesman_name, int no_of_vouchers, double wholesale_price);

void CaptureVoucherDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment) {
  // Retrieve the list of available vouchers
  std::vector<std::tuple<std::string, std::string, int, double>> available_vouchers = GetSalesDetailsByBatchNo("all");
  // Iterate through the available vouchers
  for (const auto& voucher : available_vouchers) {
    if (std::get<2>(voucher) >= no_of_vouchers) {
      // Allocate the required number of vouchers to the salesman and distributor
      // ...
    }
  }
}

std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsByDistributor(const std::string& distributor_name) { 
  std::vector<std::tuple<std::string, std::string, int, double>> sales_details; 
  // Retrieve sales details for the given distributor 
  // ... 
  return sales_details; 
}

std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsBySalesman(const std::string& salesman_name) { 
   std::vector<std::tuple<std::string, std::string, int, double>> sales_details; 
   // Retrieve sales details for the given salesman 
   // ... 
   return sales_details; 
}

std::vector<std::tuple<std::string, std::string, int, double>> GetSalesDetailsByBatchNo(const std::string& batch_no) { 
   std::vector<std::tuple<std::string, std::string, int, double>> sales_details; 
   // Retrieve sales details for the given batch number 
   // ... 
   return sales_details; 
}

void AllocateVouchers(const std::string& distributor_name, const std::string& salesman_name, int no_of_vouchers, double wholesale_price) { 
    // Retrieve the list of available vouchers 
    std::vector<std::tuple<std::string, std::string, int, double>> available_vouchers = GetSalesDetailsByBatchNo("all"); 
    // Iterate through the available vouchers 
    for (const auto& voucher : available_vouchers) { 
        if (std::get<2>(voucher) >= no_of_vouchers) { 
            // Allocate the required number of vouchers to the salesman and distributor 
            // ... 
        } 
    } 
}

