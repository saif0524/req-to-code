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

void create_distributor(const std::string& distributor_code, const std::string& name, const std::string& business_type, const std::string& proprietor_name, const std::string& designation, const std::string& address, const std::string& contact_no, const std::string& email_id, const std::string& status);
std::optional<DistributorDetails> get_distributor_details(const std::string& distributor_code);
void update_distributor_status(const std::string& distributor_code, const std::string& new_status);
std::vector<DistributorDetails> list_all_distributors();

void create_distributor(const std::string& distributor_code, const std::string& name, const std::string& business_type, const std::string& proprietor_name, const std::string& designation, const std::string& address, const std::string& contact_no, const std::string& email_id, const std::string& status) {
  bool created = database::create_distributor(distributor_code, name, business_type, proprietor_name, designation, address, contact_no, email_id, status);
  if (created) {
    std::optional<DistributorDetails> distributor_details = database::get_distributor_details(distributor_code);
    if (distributor_details.has_value()) {
      database::update_distributor_status(distributor_code, status);
    }
  }
  std::vector<DistributorDetails> all_distributors = database::list_all_distributors();
}

std::optional<DistributorDetails> get_distributor_details(const std::string& distributor_code) {
  std::optional<DistributorDetails> distributor_details = database::get_distributor_details(distributor_code);
  if (distributor_details.has_value()) {
    database::update_distributor_status(distributor_code, status);
  }
  return distributor_details;
}

void update_distributor_status(const std::string& distributor_code, const std::string& new_status) {
  std::optional<DistributorDetails> distributor_details = get_distributor_details(distributor_code);
  if (distributor_details.has_value()) {
    database::update_distributor_status(distributor_code, new_status);
  }
  return distributor_details;
}

std::vector<DistributorDetails> list_all_distributors() {
  std::vector<DistributorDetails> all_distributors = database::list_all_distributors();
  for (auto& distributor : all_distributors) {
    database::update_distributor_status(distributor.distributor_code, distributor.status);
  }
  return all_distributors;
}

