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

GenericMaster get_generic_master(const std::string& code_name);
DrugsMaster get_drugs_master(const std::string& drug_code);
SyndromeMaster get_syndrome_master(const std::string& syndrome_code);
ClinicalExaminationMaster get_clinical_examination_master(const std::string& exam_code);
DiagnosisMaster get_diagnosis_master(const std::string& diagnosis_code);

GenericMaster get_generic_master(const std::string& code_name) {
  GenericMaster generic_master;
  generic_master.get_generic_master(code_name);
  return generic_master;
}

DrugsMaster get_drugs_master(const std::string& drug_code) {
  GenericMaster generic_master;
  generic_master.get_generic_master(drug_code);

  if (generic_master.get_generic_master(drug_code).get_code_name() == drug_code) {
    return generic_master.get_drugs_master(drug_code);
  } else {
    return GenericMaster::get_error_message("Invalid drug code");
  }
}

SyndromeMaster get_syndrome_master(const std::string& syndrome_code) {
  GenericMaster generic_master = get_generic_master(syndrome_code);

  if (generic_master.get_generic_master(syndrome_code).get_code_name() == syndrome_code) {
    return generic_master.get_drugs_master(syndrome_code);
  } else {
    return GenericMaster::get_error_message("Invalid syndrome code");
  }
}

ClinicalExaminationMaster get_clinical_examination_master(const std::string& exam_code) {
  GenericMaster generic_master = get_generic_master(exam_code);

  if (generic_master.get_generic_master(exam_code).get_code_name() == exam_code) {
    return generic_master.get_drugs_master(exam_code);
  } else {
    return GenericMaster::get_error_message("Invalid exam code");
  }
}

DiagnosisMaster get_diagnosis_master(const std::string& diagnosis_code) {
  GenericMaster generic_master = get_generic_master(diagnosis_code);

  if (generic_master.get_generic_master(diagnosis_code).get_code_name() == diagnosis_code) {
    return generic_master.get_drugs_master(diagnosis_code);
  } else {
    return GenericMaster::get_error_message("Invalid diagnosis code");
  }
}

