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

GenericMaster createGenericMaster(const std::string& code, const std::string& name);
DrugsMaster createDrugsMaster(const std::string& drugCode, const std::string& drugName, double retailPrice);
SyndromeMaster createSyndromeMaster(const std::string& syndromeCode, const std::string& syndromeDescription);
ClinicalExaminationMaster createClinicalExaminationMaster(const std::string& examCode, const std::string& examDescription);
DiagnosisMaster createDiagnosisMaster(const std::string& diagnosisCode, const std::string& diagnosisDescription);

struct GenericMaster { std::string code; std::string name; }; GenericMaster createGenericMaster(const std::string& code, const std::string& name) { return GenericMaster(code, name); }

struct DrugsMaster { std::string drugCode; std::string drugName; double retailPrice; }; DrugsMaster createDrugsMaster(const std::string& drugCode, const std::string& drugName, double retailPrice) { return DrugsMaster(drugCode, drugName, retailPrice); }

struct SyndromeMaster { std::string syndromeCode; std::string syndromeDescription; }; SyndromeMaster createSyndromeMaster(const std::string& syndromeCode, const std::string& syndromeDescription) { return SyndromeMaster(syndromeCode, syndromeDescription); }

struct ClinicalExaminationMaster { std::string examCode; std::string examDescription; }; ClinicalExaminationMaster createClinicalExaminationMaster(const std::string& examCode, const std::string& examDescription) { return ClinicalExaminationMaster(examCode, examDescription); }

struct DiagnosisMaster { std::string diagnosisCode; std::string diagnosisDescription; }; DiagnosisMaster createDiagnosisMaster(const std::string& diagnosisCode, const std::string& diagnosisDescription) { return DiagnosisMaster(diagnosisCode, diagnosisDescription); }

