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

void collectClientFeedback(std::vector<std::string>& voucherNo, std::vector<std::string>& clientDetails, std::vector<std::string>& syndromesTreated, std::vector<std::string>& labTests, std::vector<std::string>& drugs, std::vector<std::string>& successOfTreatment, std::vector<std::string>& referralToTreatment, std::vector<std::string>& satisfactionOfTreatment, std::vector<std::string>& satisfactionOfCounseling, std::vector<std::string>& satisfactionOfPrivacy, std::vector<std::string>& partnerTreated);
void processFeedback(const std::vector<std::string>& voucherNo, const std::vector<std::string>& clientDetails, const std::vector<std::string>& syndromesTreated, const std::vector<std::string>& labTests, const std::vector<std::string>& drugs, const std::vector<std::string>& successOfTreatment, const std::vector<std::string>& referralToTreatment, const std::vector<std::string>& satisfactionOfTreatment, const std::vector<std::string>& satisfactionOfCounseling, const std::vector<std::string>& satisfactionOfPrivacy, const std::vector<std::string>& partnerTreated);

void processFeedback(const std::vector<std::string>& voucherNo, const std::vector<std::string>& clientDetails, const std::vector<std::string>& syndromesTreated, const std::vector<std::string>& labTests, const std::vector<std::string>& drugs, const std::vector<std::string>& successOfTreatment, const std::vector<std::string>& referralToTreatment, const std::vector<std::string>& satisfactionOfTreatment, const std::vector<std::string>& satisfactionOfCounseling, const std::vector<std::string>& satisfactionOfPrivacy, const std::vector<std::string>& partnerTreated) {
  for (size_t i = 0; i < voucherNo.size(); ++i) {
    std::cout << "Voucher No: " << voucherNo[i] << std::endl;
    std::cout << "Client Details: " << clientDetails[i] << std::endl;
    std::cout << "Syndromes Treated: " << syndromesTreated[i] << std::endl;
    std::cout << "Lab Tests: " << labTests[i] << std::endl;
    std::cout << "Drugs: " << drugs[i] << std::endl;
    std::cout << "Success of Treatment: " << successOfTreatment[i] << std::endl;
    std::cout << "Referral To Treatment: " << referralToTreatment[i] << std::endl;
    std::cout << "Satisfaction of Treatment: " << satisfactionOfTreatment[i] << std::endl;
    std::cout << "Satisfaction of Counseling: " << satisfactionOfCounseling[i] << std::endl;
    std::cout << "Satisfaction of Privacy: " << satisfactionOfPrivacy[i] << std::endl;
    std::cout << "Partner Treated: " << partnerTreated[i] << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
}

