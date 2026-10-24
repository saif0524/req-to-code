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

void capture_distributor_name(std::string& distributor_name);
void capture_sales_man_name(std::string& sales_man_name);
void capture_sales_return_date(std::string& sales_return_date);
void capture_sales_return_amount(double& sales_return_amount);
void capture_number_of_vouchers_returned(int& number_of_vouchers_returned);

void capture_distributor_name(std::string& distributor_name) {
  std::cout << "Enter the name of the distributor: ";
  std::cin >> distributor_name;
}

void capture_sales_man_name(std::string& sales_man_name) {
  std::cout << "Enter the name of the sales man: ";
  std::cin >> sales_man_name;
}

void capture_sales_return_date(std::string& sales_return_date) {
  std::cout << "Enter the sales return date (YYYY-MM-DD): ";
  std::cin >> sales_return_date;
}

void capture_sales_return_amount(double& sales_return_amount) {
  std::cout << "Enter the sales return amount: ";
  std::cin >> sales_return_amount;
}

void capture_number_of_vouchers_returned(int& number_of_vouchers_returned) {
  std::cout << "Enter the number of vouchers returned: ";
  std::cin >> number_of_vouchers_returned;
}

