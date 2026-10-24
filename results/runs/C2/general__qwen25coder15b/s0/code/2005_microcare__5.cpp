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

struct VoucherFeedback { std::string voucher_no; ClientDetails client_details; std::vector<Syndrome> syndromes; LabTest lab_test; std::vector<Drug> drugs; std::string success_of_treatment; std::string referral_to_treatment; std::string satisfaction_of_treatment; std::string satisfaction_of_counseling; std::string satisfaction_of_privacy; std::string partner_treated; };

void collect_client_feedback(std::vector<VoucherFeedback>& feedback);
bool validate_client_details(const ClientDetails& details);
bool validate_syndromes(const std::vector<Syndrome>& syndromes);
bool validate_lab_test(const LabTest& test);
bool validate_drugs(const std::vector<Drug>& drugs);

struct VoucherFeedback { ClientDetails client_details; std::vector<Syndrome> syndromes; LabTest lab_test; std::vector<Drug> drugs; bool valid; }; void collect_client_feedback(std::vector<VoucherFeedback>& feedback) { for (const auto& feedback : feedback) { if (!validate_client_details(feedback.client_details)) { return false; } if (!validate_syndromes(feedback.syndromes)) { return false; } if (!validate_lab_test(feedback.lab_test)) { return false; } if (!validate_drugs(feedback.drugs)) { return false; } feedback.valid = true; } return true; }

struct ClientDetails { std::string name; int age; std::string gender; std::string address; std::string phone; std::string email; std::vector<Syndrome> syndromes; std::vector<LabTest> lab_tests; std::vector<Drug> drugs; }; bool validate_client_details(ClientDetails& details) { if (details.name.empty() || details.age <= 0 || details.gender.empty() || details.address.empty()) { return false; } if (details.phone.empty() || details.email.empty()) { return false; } if (details.syndromes.empty()) { return false; } if (details.lab_tests.empty()) { return false; } if (details.drugs.empty()) { return false; } return true; }

bool validate_syndromes(std::vector<Syndrome>& syndromes) {
  if (syndromes.size() == 0) {
    return false; // Syndromes are required
  }
  for (const auto& syndrome : syndromes) {
    if (syndrome.size() == 0) {
      return false; // Syndrome is required
    }
  }
  return true; // Syndromes are valid
}

bool validate_lab_test(const LabTest& test, VoucherFeedback& feedback) { if (test.empty()) { feedback.valid = false; return false; } return true; }

bool validate_drugs(const std::vector<Drug>& drugs) { if (!feedback.valid) { return false; } if (drugs.empty()) { feedback.valid = false; return false; } for (const auto& drug : drugs) { if (drug.empty()) { feedback.valid = false; return false; } } return true; }

