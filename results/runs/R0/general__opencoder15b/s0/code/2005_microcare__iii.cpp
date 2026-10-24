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

void CaptureSalesDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment);
void GenerateVoucherDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment);
std::vector<std::string> GetDistributorSalesDetails(const std::string& distributor_name);
std::vector<std::string> GetSalesmanSalesDetails(const std::string& salesman_name);
std::vector<std::string> GetBatchNoSalesDetails(const std::string& batch_no);

void CaptureSalesDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment) {
  // Your implementation here
}

void CaptureSalesDetails(const std::string& distributor_name, const std::string& salesman_name, const std::string& date, int no_of_vouchers, double wholesale_price, const std::string& mode_of_payment) {
  // Your implementation here
}

std::vector<std::string> GetDistributorSalesDetails(const std::string& distributor_name) {
   // Your implementation here
}

std::vector<std::string> GetSalesmanSalesDetails(const std::string& salesman_name) {
    std::vector<std::string> salesman_sales_details;
    for (const auto& sales_details : sales_details_vector) {
        std::string distributor_name = sales_details[0];
        std::string salesman_name_from_sales_details = sales_details[1];
        if (salesman_name_from_sales_details == salesman_name) {
            salesman_sales_details.push_back(sales_details);
        }
    }
    return salesman_sales_details;
}

std::vector<std::string> GetBatchNoSalesDetails(const std::string& batch_no) {
    std::vector<std::string> batch_sales_details;
    for (const auto& sales_details : sales_details_vector) {
        std::string batch_no_from_sales_details = sales_details[2];
        if (batch_no_from_sales_details == batch_no) {
            batch_sales_details.push_back(sales_details);
        }
    }
    return batch_sales_details;
}

