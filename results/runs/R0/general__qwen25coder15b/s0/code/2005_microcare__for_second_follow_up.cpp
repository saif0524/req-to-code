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

void add_syndrome(const std::string& name, int frequency, int days, int qty);
void add_clinical_examination(const std::string& name, int frequency, int days, int qty);
void add_diagnosis(const std::string& name, int frequency, int days, int qty);
void add_lab_test(const std::string& name, int frequency, int days, int qty);
void add_drug(const std::string& name, int frequency, int days, int qty);

void add_syndrome(const std::string& name, int frequency, int days, int qty) {
  add_syndrome(name, frequency, days, qty);
}

void add_clinical_examination(const std::string& name, int frequency, int days, int qty) {
  add_clinical_examination(name, frequency, days, qty);
}

void add_diagnosis(const std::string& name, int frequency, int days, int qty) {
  add_diagnosis(name, frequency, days, qty);
}

void add_lab_test(const std::string& name, int frequency, int days, int qty) {
  add_drug(name, frequency, days, qty);
}

void add_drug(const std::string& name, int frequency, int days, int qty) {
  add_drug(name, frequency, days, qty);
}

