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

struct MISUFieldOffice; using MISUFieldOfficeSubmitClaim = void(MISUFieldOffice*, const std::string&, const std::string&, int, int, const std::vector<std::string>&);

void submit_claim(const std::string& vsp_name, const std::string& date_of_submission, int no_of_mentioned_forms, int no_of_available_forms);
void capture_details(std::vector<std::string>& treatment_form_no);

void submit_claim(const std::string& vsp_name, const std::string& date_of_submission, int no_of_mentioned_forms, int no_of_available_forms) {
  std::vector<std::string> treatment_form_no;
  capture_details(treatment_form_no);
  MISUFieldOffice::submit_claim(vsp_name, date_of_submission, no_of_mentioned_forms, no_of_available_forms, treatment_form_no);
}

