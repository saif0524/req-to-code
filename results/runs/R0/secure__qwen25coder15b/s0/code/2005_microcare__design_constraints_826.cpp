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

ClientDetails get_client_details(const std::string& voucher_no);
SyndromeDetails get_syndrome_details(const std::string& voucher_no);
LabTestDetails get_lab_test_details(const std::string& voucher_no);
DrugsDetails get_drugs_details(const std::string& voucher_no);
SuccessOfTreatment get_success_of_treatment(const std::string& voucher_no);

ClientDetails get_client_details(const std::string& voucher_no) {
  ClientDetails client_details;
  client_details = ClientDetails(voucher_no);
  return client_details;
}

SyndromeDetails get_syndrome_details(const std::string& voucher_no) {  return client_details.syndrome_details; }

LabTestDetails get_lab_test_details(const std::string& voucher_no) {  return ClientDetails(voucher_no); }

DrugsDetails get_drugs_details(const std::string& voucher_no) {
  if (voucher_no.empty() || voucher_no.isspace()) {
    return DrugsDetails("Invalid voucher number");
  }
  ClientDetails client_details = get_client_details(voucher_no);
  return client_details.drugs_details;
}

SuccessOfTreatment get_success_of_treatment(const std::string& voucher_no) {
  if (voucher_no.empty() || voucher_no.isspace()) {
    return SuccessOfTreatment("Invalid voucher number");
  }
  ClientDetails client_details = get_client_details(voucher_no);
  return client_details.drugs_details;
}

