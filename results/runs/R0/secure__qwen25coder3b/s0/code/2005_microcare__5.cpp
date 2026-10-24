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

void collectClientFeedback(std::string voucherNo, ClientDetails clientDetails, Syndromes syndromes, LabTestResults labTestResults, TreatmentSuccess treatmentSuccess, ReferralToTreatment referralToTreatment, SatisfactionOfTreatment satisfactionOfTreatment, SatisfactionOfCounseling satisfactionOfCounseling, SatisfactionOfPrivacy satisfactionOfPrivacy, PartnerTreated partnerTreated);
bool validateInput(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated);
void storeFeedback(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated);
void generateReport(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated);
void displayFeedback(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated);

void collectClientFeedback(std::string voucherNo, ClientDetails clientDetails, Syndromes syndromes, LabTestResults labTestResults, TreatmentSuccess treatmentSuccess, ReferralToTreatment referralToTreatment, SatisfactionOfTreatment satisfactionOfTreatment, SatisfactionOfCounseling satisfactionOfCounseling, SatisfactionOfPrivacy satisfactionOfPrivacy, PartnerTreated partnerTreated) {
  if (!validateInput(voucherNo, clientDetails, syndromes, labTestResults, treatmentSuccess, referralToTreatment, satisfactionOfTreatment, satisfactionOfCounseling, satisfactionOfPrivacy, partnerTreated)) {
    return;
  }
  storeFeedback(voucherNo, clientDetails, syndromes, labTestResults, treatmentSuccess, referralToTreatment, satisfactionOfTreatment, satisfactionOfCounseling, satisfactionOfPrivacy, partnerTreated);
  generateReport(voucherNo, clientDetails, syndromes, labTestResults, treatmentSuccess, referralToTreatment, satisfactionOfTreatment, satisfactionOfCounseling, satisfactionOfPrivacy, partnerTreated);
  displayFeedback(voucherNo, clientDetails, syndromes, labTestResults, treatmentSuccess, referralToTreatment, satisfactionOfTreatment, satisfactionOfCounseling, satisfactionOfPrivacy, partnerTreated);
}

bool validateInput(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated) {
  if (voucherNo.empty()) {
    return false;
  }
  if (clientDetails.name.empty() || clientDetails.age < 0 || clientDetails.gender.empty()) {
    return false;
  }
  if (syndromes.empty()) {
    return false;
  }
  if (labTestResults.empty()) {
    return false;
  }
  if (treatmentSuccess.empty()) {
    return false;
  }
  if (referralToTreatment.empty()) {
    return false;
  }
  if (satisfactionOfTreatment < 1 || satisfactionOfTreatment > 4) {
    return false;
  }
  if (satisfactionOfCounseling < 1 || satisfactionOfCounseling > 4) {
    return false;
  }
  if (satisfactionOfPrivacy < 1 || satisfactionOfPrivacy > 4) {
    return false;
  }
  if (partnerTreated < 0 || partnerTreated > 1) {
    return false;
  }
  return true;
}

void storeFeedback(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated) {
  // Create a JSON object to store the feedback
  json feedback;
  feedback["voucherNo"] = voucherNo;
  feedback["clientDetails"] = clientDetails;
  feedback["syndromes"] = syndromes;
  feedback["labTestResults"] = labTestResults;
  feedback["treatmentSuccess"] = treatmentSuccess;
  feedback["referralToTreatment"] = referralToTreatment;
  feedback["satisfactionOfTreatment"] = satisfactionOfTreatment;
  feedback["satisfactionOfCounseling"] = satisfactionOfCounseling;
  feedback["satisfactionOfPrivacy"] = satisfactionOfPrivacy;
  feedback["partnerTreated"] = partnerTreated;

  // Write the JSON object to a file
  std::ofstream file("client_feedback.json");
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file for writing." << std::endl;
    return;
  }
  file << feedback.dump(4); // Pretty print the JSON
  file.close();
}

void generateReport(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated) {
  // Create a JSON object to store the report
  json report;
  report[

void displayFeedback(const std::string& voucherNo, const ClientDetails& clientDetails, const Syndromes& syndromes, const LabTestResults& labTestResults, const TreatmentSuccess& treatmentSuccess, const ReferralToTreatment& referralToTreatment, const SatisfactionOfTreatment& satisfactionOfTreatment, const SatisfactionOfCounseling& satisfactionOfCounseling, const SatisfactionOfPrivacy& satisfactionOfPrivacy, const PartnerTreated& partnerTreated) {
  // Create a JSON object to store the feedback
  json feedback;
  feedback["voucherNo"] = voucherNo;
  feedback["clientDetails"] = clientDetails;
  feedback["syndromes"] = syndromes;
  feedback["labTestResults"] = labTestResults;
  feedback["treatmentSuccess"] = treatmentSuccess;
  feedback["referralToTreatment"] = referralToTreatment;
  feedback["satisfactionOfTreatment"] = satisfactionOfTreatment;
  feedback["satisfactionOfCounseling"] = satisfactionOfCounseling;
  feedback["satisfactionOfPrivacy"] = satisfactionOfPrivacy;
  feedback["partnerTreated"] = partnerTreated;

  // Print the JSON object to the console
  std::cout << feedback.dump(4) << std::endl;
}

