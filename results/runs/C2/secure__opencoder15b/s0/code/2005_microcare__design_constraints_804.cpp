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

std::vector<std::string> get_districts();
std::vector<std::string> get_subdistricts(std::string district);
std::vector<std::string> get_counties(std::string subdistrict);
std::vector<std::string> get_sales_history(std::string distributor_name);
std::string get_distributor_details(std::string distributor_name);

std::vector<std::string> get_districts() {
   std::vector<std::string> districts;
   std::string query = "SELECT district FROM distributors;";
   // Execute the query and store the results in `districts`.
   return districts;
}

std::vector<std::string> get_subdistricts(std::string district) {
  std::vector<std::string> subdistricts;
  std::string query = "SELECT subdistrict FROM distributors WHERE district = ?;";
  // Execute the query and store the results in `subdistricts`.
  return subdistricts;
}

std::vector<std::string> get_counties(std::string subdistrict) {
   std::vector<std::string> counties;
   std::string query = "SELECT county FROM distributors WHERE subdistrict = ?;";
   // Execute the query and store the results in `counties`.
   return counties;
}

std::vector<std::string> get_sales_history(std::string distributor_name) {
   std::vector<std::string> sales_history;
   std::string query = "SELECT * FROM sales WHERE distributor_name = ?;";
   // Execute the query and store the results in `sales_history`.
   return sales_history;
}

std::vector<std::string> get_districts() {
   std::vector<std::string> districts;
   std::string query = "SELECT district FROM distributors;";
   // Execute the query and store the results in `districts`.
   return districts;
}

