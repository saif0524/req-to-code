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

void check_form_mandatory(const TreatmentForm& form);
void mark_claim_rejected(const TreatmentForm& form);
void capture_transaction_details(const TreatmentForm& form);
void validate_hiv_details(const TreatmentForm& form);
void update_patient_status(const TreatmentForm& form);

void check_form_mandatory(const TreatmentForm& form) {
  if (!form.hasTreatmentFormNo()) {
    return send_back_to_vsp(form, "TreatmentFormNo is mandatory");
  }
  if (!form.hasClaimNo()) {
    return send_back_to_vsp(form, "ClaimNo is mandatory");
  }
  if (!form.hasSubmittedDate()) {
    return send_back_to_vsp(form, "SubmittedDate is mandatory");
  }
  if (!form.hasVSPName()) {
    return send_back_to_vsp(form, "VSPName is mandatory");
  }
  if (!form.hasVoucherNo()) {
    return send_back_to_vsp(form, "VoucherNo is mandatory");
  }
  if (!form.hasVisitCount()) {
    return send_back_to_vsp(form, "VisitCount is mandatory");
  }
  if (!form.hasPatientType()) {
    return send_back_to_vsp(form, "PatientType is mandatory");
  }
  if (!form.hasPatientName()) {
    return send_back_to_vsp(form, "PatientName is mandatory");
  }
  if (!form.hasAge()) {
    return send_back_to_vsp(form, "Age is mandatory");
  }
  if (!form.hasGender()) {
    return send_back_to_vsp(form, "Gender is mandatory");
  }
  if (!form.hasAddress()) {
    return send_back_to_vsp(form, "Address is mandatory");
  }
  if (!form.hasContactNo()) {
    return send_back_to_vsp(form, "ContactNo is mandatory");
  }
  if (!form.hasDoctorName()) {
    return send_back_to_vsp(form, "DoctorName is mandatory");
  }
  if (!form.hasDoctorsNote()) {
    return send_back_to_vsp(form, "DoctorsNote is mandatory");
  }
  if (!form.hasHIVDetails()) {
    return send_back_to_vsp(form, "HIVDetails is mandatory");
  }
  if (!form.hasPatientStatus()) {
    return send_back_to_vsp(form, "PatientStatus is mandatory");
  }
  return send_back_to_vsp(form, "Form is mandatory");
}

void mark_claim_rejected(const TreatmentForm& form) {
  if (!form.hasTreatmentFormNo()) {
    return send_back_to_vsp(form, "TreatmentFormNo is mandatory");
  }
  if (!form.hasClaimNo()) {
    return send_back_to_vsp(form, "ClaimNo is mandatory");
  }
  if (!form.hasSubmittedDate()) {
    return send_back_to_vsp(form, "SubmittedDate is mandatory");
  }
  if (!form.hasVSPName()) {
    return send_back_to_vsp(form, "VSPName is mandatory");
  }
  if (!form.hasVoucherNo()) {
    return send_back_to_vsp(form, "VoucherNo is mandatory");
  }
  if (!form.hasVisitCount()) {
    return send_back_to_vsp(form, "VisitCount is mandatory");
  }
  if (!form.hasPatientType()) {
    return send_back_to_vsp(form, "PatientType is mandatory");
  }
  if (!form.hasPatientName()) {
    return send_back_to_vsp(form, "PatientName is mandatory");
  }
  if (!form.hasAge()) {
    return send_back_to_vsp(form, "Age is mandatory");
  }
  if (!form.hasGender()) {
    return send_back_to_vsp(form, "Gender is mandatory");
  }
  if (!form.hasAddress()) {
    return send_back_to_vsp(form, "Address is mandatory");
  }
  if (!form.hasContactNo()) {
    return send_back_to_vsp(form, "ContactNo is mandatory");
  }
  if (!form.hasDoctorName()) {
    return send_back_to_vsp(form, "DoctorName is mandatory");
  }
  if (!form.hasDoctorsNote()) {
    return send_back_to_vsp(form, "DoctorsNote is mandatory");
  }
  if (!form.hasHIVDetails()) {
    return send_back_to_vsp(form, "HIVDetails is mandatory");
  }
  if (!form.hasPatientStatus()) {
    return send_back_to_vsp(form, "PatientStatus is mandatory");
  }
  return send_back_to_vsp(form, "Form is mandatory");
}

void capture_transaction_details(const TreatmentForm& form) {
  TransactionDetails transactionDetails;
  transactionDetails.treatmentFormNo = form.getTreatmentFormNo();
  transactionDetails.claimNo = form.getClaimNo();
  transactionDetails.submittedDate = form.getSubmittedDate();
  transactionDetails.vSPName = form.getVSPName();
  transactionDetails.voucherNo = form.getVoucherNo();
  transactionDetails.visitCount = form.getVisitCount();
  transactionDetails.patientType = form.getPatientType();
  transactionDetails.patientName = form.getPatientName();
  transactionDetails.age = form.getAge();
  transactionDetails.gender = form.getGender();
  transactionDetails.address = form.getAddress();
  transactionDetails.contactNo = form.getContactNo();
  transactionDetails.doctorName = form.getDoctorName();
  transactionDetails.doctorsNote = form.getDoctorsNote();
  transactionDetails.hIVDetails = form.getHIVDetails();
  transactionDetails.patientStatus = form.getPatientStatus();
  return transactionDetails;
}

void validate_hiv_details(const TreatmentForm& form) {
  if (form.hasHIVDetails()) {
    std::regex regex("HIV-\d+");
    if (!regex.match(form.getHIVDetails())) {
      return send_back_to_vsp(form, "HIV Details is not in the correct format");
    }
  }
}

void update_patient_status(const TreatmentForm& form) {
  Claim claim = capture_transaction_details(form);
  claim.patientStatus = form.getPatientStatus();
  return claim;
}

