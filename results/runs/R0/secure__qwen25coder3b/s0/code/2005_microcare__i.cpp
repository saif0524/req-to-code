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

bool validateDistributorCode(const std::string& code);
bool validateName(const std::string& name);
bool validateTypeOfOF(const std::string& type);
bool validateProprietorName(const std::string& name);
bool validateDesignation(const std::string& designation);

bool validateDistributorCode(const std::string& code) {
  if (code.length() != 3 || code[0] != 'D' || !isdigit(code[1]) || !isdigit(code[2])) {
    return false;
  }
  return true;
}

bool validateName(const std::string& name) {
  if (name.empty()) {
    return false;
  }
  std::string trimmedName = name;
  std::istringstream iss(trimmedName);
  std::string word;
  while (iss >> word) {
    if (!std::all_of(word.begin(), word.end(), ::isalpha)) {
      return false;
    }
  }
  return true;
}

bool validateTypeOfOF(const std::string& type) {
  if (type.empty()) {
    return false;
  }
  for (char c : type) {
    if (!std::isalpha(c)) {
      return false;
    }
  }
  return true;
}

bool validateProprietorName(const std::string& name) {
  if (name.empty()) {
    return false;
  }
  std::string trimmedName = name;
  std::istringstream iss(trimmedName);
  std::string word;
  while (iss >> word) {
    if (!std::all_of(word.begin(), word.end(), ::isalpha)) {
      return false;
    }
  }
  return true;
}

bool validateDesignation(const std::string& designation) {
  if (designation.empty()) {
    return false;
  }
  std::istringstream iss(designation);
  std::string word;
  while (iss >> word) {
    if (!std::all_of(word.begin(), word.end(), ::isalpha)) {
      return false;
    }
  }
  return true;
}

