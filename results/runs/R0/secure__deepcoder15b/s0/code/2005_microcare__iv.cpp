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

int form_number = 1; int voucher_number = 1; int visit_count = 1; string address[] = {

int check_form_for_mandatory_info(int form_number, int voucher_number, int visit_count, int patient_type, string address, string contact_no, string doctor_name, string note, bool &rejected ClaimStatus);
void mark_claim_as_rejected(int form_number, string vsp_name, int voucher_number, int visit_count, string patient_type, string patient_name, int doctor_count, int doctor_name, string note, bool &rejected ClaimStatus);
void capture_data(int form_number, int voucher_number, int visit_count, string patient_type, string patient_name, int doctor_count, int doctor_name, string note, string address, string contact_no, string doctor_name, int patient_type, int doctor_count, string claim_amount);
void output_data(string master_info, string transaction_data);
void send_back_form(int form_number, string vsp_name);

int check_form_for_mandatory_info(int form_number, int voucher_number, int visit_count, int patient_type, string address, string contact_no, string doctor_name, string note, bool &rejected ClaimStatus) {
  // Check if all mandatory fields are present in the form
  bool isFormValid = true;
  if (form_number < 1 || form_number > 1) {
    isFormValid = false;
  }
  if (voucher_number < 1) {
    isFormValid = false;
  }
  if (!is_valid_address address) {
    isFormValid = false;
  }
  if (!is_valid_contact_no contact_no) {
    isFormValid = false;
  }
  if (!is_valid_doctor_name doctor_name) {
    isFormValid = false;
  }
  if (!is_valid_note note) {
    isFormValid = false;
  }
  if (!is_valid_claim_amount claim_amount) {
    isFormValid = false;
  }

  if (!isFormValid) {
    return;
  }

  // If all mandatory fields are present, mark the claim as rejected
  rejected ClaimStatus = true;
  return;
  }
  

void mark_claim_as_rejected(int form_number, string vsp_name, int voucher_number, int visit_count, string patient_type, string patient_name, int doctor_count, int doctor_name, string note, bool &rejected ClaimStatus) {
  if (check_form_for_mandatory_info(form_number, voucher_number, visit_count, patient_type, address, contact_no, doctor_name, note, rejected ClaimStatus)) {
    rejected ClaimStatus = true;
  }
  }
  

capture_data form_number:1, voucher_number:1, visit_count:1, patient_type:?, patient_name:?, doctor_count:1, doctor_name:?, note: ?, address: [?, ?, ?, ?, ?, ?, ?, ?, ?, ?], contact_no: ?, claim_amount: ?

output_data

function send_back_form(int form_number, string vsp_name) returns string:
  - Validates form_number is within allowed range
  - Sends form back to VSP
  - Returns JSON with reasoning and code

