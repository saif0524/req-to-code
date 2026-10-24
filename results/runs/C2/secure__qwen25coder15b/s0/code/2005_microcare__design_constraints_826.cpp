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

struct ClientDetails; using SyndromeDetails = ClientDetails::SyndromeDetails;
struct LabTestDetails {  std::string lab_test_details; };

ClientDetails get_client_details(const std::string& voucher_no);
SyndromeDetails get_syndrome_details(const std::string& voucher_no);
LabTestDetails get_lab_test_details(const std::string& voucher_no);
DrugsDetails get_drugs_details(const std::string& voucher_no);
SuccessOfTreatment get_success_of_treatment(const std::string& voucher_no);

struct ClientDetails {  std::string address;  SyndromeDetails syndrome_details;  LabTestDetails lab_test_details;  DrugsDetails drugs_details;  SuccessOfTreatment success_of_treatment; };

SyndromeDetails get_syndrome_details(const std::string& voucher_no, ClientDetails client_details) {  return client_details.syndrome_details; }

struct ClientDetails {  std::string address;  SyndromeDetails syndrome_details;  LabTestDetails lab_test_details;  DrugsDetails drugs_details;  SuccessOfTreatment success_of_treatment;  LabTestDetails get_lab_test_details(const std::string& voucher_no) {    if (voucher_no.empty() || voucher_no.isspace()) {      return LabTestDetails(

struct DrugsDetails { std::string drugs_details; };

struct SuccessOfTreatment { std::string success_of_treatment; };

