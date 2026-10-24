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

class VoucherManager {
public:
  static std::vector<std::string> diagnosisEntries;

  void addDiagnosis(const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty);
  std::vector<std::string> getDiagnosisList();
  void updateDiagnosis(int index, const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty);
  void deleteDiagnosis(int index);
  std::string getDiagnosisDetails(int index);
};

void addDiagnosis(const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty);
std::vector<std::string> getDiagnosisList();
void updateDiagnosis(int index, const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty);
void deleteDiagnosis(int index);
std::string getDiagnosisDetails(int index);

void addDiagnosis(const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty) { static std::vector<std::string> diagnosisEntries; diagnosisEntries.push_back(syndrome + ' ' + clinicalExamination + ' ' + diagnosis + ' ' + labTest + ' ' + drug + ' ' + std::to_string(frequency) + ' ' + std::to_string(noOfDays) + ' ' + std::to_string(qty)); }

std::vector<std::string> getDiagnosisList() { return diagnosisEntries; }

void updateDiagnosis(int index, const std::string& syndrome, const std::string& clinicalExamination, const std::string& diagnosis, const std::string& labTest, const std::string& drug, int frequency, int noOfDays, int qty) { static std::vector<std::string> diagnosisEntries; if (index >= 0 && index < diagnosisEntries.size()) { diagnosisEntries[index] = syndrome + ' ' + clinicalExamination + ' ' + diagnosis + ' ' + labTest + ' ' + drug + ' ' + std::to_string(frequency) + ' ' + std::to_string(noOfDays) + ' ' + std::to_string(qty); } }

class VoucherManager { public: static std::vector<std::string> diagnosisEntries; void deleteDiagnosis(int index) { if (index >= 0 && index < diagnosisEntries.size()) { diagnosisEntries.erase(diagnosisEntries.begin() + index); } } };

std::string getDiagnosisDetails(int index) { static std::vector<std::string> diagnosisEntries; if (index >= 0 && index < diagnosisEntries.size()) { return diagnosisEntries[index]; } else { return "Invalid index"; } }

