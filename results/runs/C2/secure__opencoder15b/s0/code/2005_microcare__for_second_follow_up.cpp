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

add_claim(const std::string& diagnosis_drug_name, int frequency, int no_of_days, int qty, const std::vector<std::string>& symptoms, const std::vector<std::string>& examinations, const std::vector<std::string>& diagnosis, const std::vector<std::string>& lab_tests, const std::vector<std::string>& drugs_other_measures);

void add_claim(const std::string& diagnosis_drug_name, int frequency, int no_of_days, int qty, const std::vector<std::string>& symptoms, const std::vector<std::string>& examinations, const std::vector<std::string>& diagnosis, const std::vector<std::string>& lab_tests, const std::vector<std::string>& drugs_other_measures) {
    // Create a new claim object with the given parameters
    Claim new_claim(diagnosis_drug_name, frequency, no_of_days, qty, symptoms, examinations, diagnosis, lab_tests, drugs_other_measures);

    // Add the new claim object to the system's claim list
    system_claims.push_back(new_claim);
}

