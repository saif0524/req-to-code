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

bool process_evidence(string evidence_type, string evidence_details, int* result = nullptr);
int generate_number(string evidence_details, int* result, int* complaint_number = nullptr, int* complaint_description = nullptr);
void handle_complaints(int* result, int* complaint_numbers = nullptr, int* complaint descriptions = nullptr);

bool process_evidence(string evidence_type, string evidence_details, int* result = nullptr) {
    int extracted_number = 0;
    size_t pos = 0;
    while (pos < evidence_details.size()) {
        if (!isdigit(evidence_details[pos])) {
            pos++;
            continue;
        }
        extracted_number = extracted_number * 10 + (evidence_details[pos] - '0');
        pos++;
    }
    if (extracted_number != 0) {
        int generated_number = generate_number(evidence_details, result, complaint_number, description);
        if (generated_number == extracted_number) {
            *result = true;
            return true;
        } else {
            return false;
        }
    }
    return false;
    "}\n

int generate_number(string evidence_details, int* result, int* complaint_number, int* complaint_description) {
    int number = 0;
    for (char c : evidence_details) {
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
    }
    *result = number;
    return number;
    }

void handle_complaints(int* result, int* complaint_numbers = nullptr, int* complaint descriptions = nullptr) {
  if (result) *result = false;
  for (int i = 0; i < *complaint_numbers; i++) {
    int generated_number = generate_number(complaint descriptions[i][1]. evidence_details, result, complaint_numbers, complaint descriptions);
    int extracted_number;
    size_t pos = 0;
    while (pos < complaint descriptions[i][1]. evidence_details.size()) {
      if (!isdigit(complaint descriptions[i][1]. evidence_details[pos])) {
        pos++;
        continue;
      }
      extracted_number = extracted_number * 10 + (complaint descriptions[i][1]. evidence_details[pos] - '0');
      pos++;
    }
    if (generated_number == extracted_number) {
      *result = true;
    }
    complaint_numbers[i] = generated_number;
    complaint descriptions[i][0] = extracted_number;
  }
  return;
  }
  "

