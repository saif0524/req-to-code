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

using json_object = std::map<std::string, std::string>;
using add_measure = void(const std::string& name, int frequency, int days, int qty);
using is_lab_test_exists = bool(const std::string& name);

void add_syndrome(const std::string& name, int frequency, int days, int qty);
void add_clinical_examination(const std::string& name, int frequency, int days, int qty);
void add_diagnosis(const std::string& name, int frequency, int days, int qty);
void add_lab_test(const std::string& name, int frequency, int days, int qty);
void add_drug(const std::string& name, int frequency, int days, int qty);

void add_syndrome(const std::string& name, int frequency, int days, int qty) {
  // Check if the syndrome already exists in the treatment level
  if (is_syndrome_exists(name)) {
    return json_object(
      "message": "syndrome already exists"
    );
  }

  // Add the new syndrome to the treatment level
  add_measure(name, frequency, days, qty);

  // Return a JSON object with the message 'syndrome added successfully'
  return json_object(
    "message": "syndrome added successfully"
  );
}

void add_clinical_examination(const std::string& name, int frequency, int days, int qty) {
  // Check if the clinical examination already exists in the treatment level
  if (is_clinical_examination_exists(name)) {
    return json_object(
      "message": "clinical examination already exists"
    );
  }

  // Add the new clinical examination to the treatment level
  add_measure(name, frequency, days, qty);

  // Return a JSON object with the message 'clinical examination added successfully'
  return json_object(
    "message": "clinical examination added successfully"
  );
}

void add_diagnosis(const std::string& name, int frequency, int days, int qty) {
  // Check if the diagnosis already exists in the treatment level
  if (is_diagnosis_exists(name)) {
    return json_object(
      "message": "diagnosis already exists"
    );
  }

  // Add the new diagnosis to the treatment level
  add_measure(name, frequency, days, qty);

  // Return a JSON object with the message 'diagnosis added successfully'
  return json_object(
    "message": "diagnosis added successfully"
  );
}

void add_lab_test(const std::string& name, int frequency, int days, int qty) {
  // Check if the lab test already exists in the treatment level
  if (is_lab_test_exists(name)) {
    return json_object(
      "message": "lab test already exists"
    );
  }

  // Add the new lab test to the treatment level
  add_measure(name, frequency, days, qty);

  // Return a JSON object with the message 'lab test added successfully'
  return json_object(
    "message": "lab test added successfully"
  );
}

using json_object = std::map<std::string, std::string>;
using add_measure = void(const std::string& name, int frequency, int days, int qty);
using is_lab_test_exists = bool(const std::string& name);

void add_drug(const std::string& name, int frequency, int days, int qty) {
  // Check if the drug already exists in the treatment level
  if (is_drug_exists(name)) {
    return json_object(
      "message": "drug already exists"
    );
  }

  // Add the new drug to the treatment level
  add_measure(name, frequency, days, qty);

  // Return a JSON object with the message 'drug added successfully'
  return json_object(
    "message": "drug added successfully"
  );
}

