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

int voucherNumberValidation(int voucherNumber);
std::vector<std::string> clientDetailsParsing(std::vector<std::string> formData);
std::vector<std::string> labTestResults(std::vector<std::string> testData);
bool drugTreatmentMonitoring(std::string drug, std::vector<std::pair<std::string, std::string>> treatmentData);

int voucherNumberValidation(int voucherNumber) 
{ 
    if (voucherNumber < 1) 
    { 
      return -1; 
    }
    if (voucherNumber > 1000) 
    { 
      return -2; 
    }
    return 0; 
  }

vector<string> clientDetailsParsing(vector<string> formData) {
  vector<string> result;
  for (string& elem : formData) {
    if (elem == 

vector<string> labTestResults(vector<string> testData) {
  vector<string> result;
  for (string s : testData) {
    string value;
    // Assuming each string in testData is a lab test result string
    // For example, 

bool drugTreatmentMonitoring(std::string drug, std::vector<std::pair<std::string, std::string>> treatmentData) {
    for (const auto& pair : treatmentData) {
        std::string drugName = pair.first;
        if (drugName == drug) {
            return true;
        }
    }
    return false;
    }

    

