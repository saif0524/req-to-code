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

std::string get_distributor_name();
std::string get_sales_man_name();
std::string get_sales_return_date();
double get_sales_return_amount();
int get_number_of_vouchers_returned();

std::string get_distributor_name() { return VoucherManagementSystem::get_distributor_name(); }

std::string get_sales_man_name() { return VoucherManagementSystem::get_sales_man_name(); }

std::string get_sales_return_date() { return VoucherManagementSystem::get_sales_return_date(); }

double get_sales_return_amount() { return VoucherManagementSystem::get_number_of_vouchers_returned() * VoucherManagementSystem::get_whole_sale_rate(); }

int get_number_of_vouchers_returned() { return VoucherManagementSystem::get_number_of_vouchers_returned() * VoucherManagementSystem::get_whole_sale_rate(); }

