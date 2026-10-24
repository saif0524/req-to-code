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

bool validateInput(const std::string& date, const std::string& forms, const std::string& vspName);
bool checkForms(const std::string& forms, const std::string& availableForms);
void printReceipt(const std::string& vspName, const std::string& date, const std::string& forms, const std::string& availableForms);

bool validateInput(const std::string& date, const std::string& forms, const std::string& vspName) {
  // Validate date format
  if (date.empty() || !std::regex_match(date, std::regex(R"([0-9]{4}-[0-9]{2}-[0-9]{2})"))) {
    throw std::invalid_argument("Invalid date format.");
  }

  // Check if the mentioned forms and available forms match
  try {
    int formsNum = std::stoi(forms);
    int availableFormsNum = std::stoi(availableForms);
    if (formsNum > availableFormsNum) {
      throw std::invalid_argument("Mentioned forms cannot be more than available forms.");
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

bool checkForms(const std::string& forms, const std::string& availableForms) {
  try {
    int formsNum = std::stoi(forms);
    int availableFormsNum = std::stoi(availableForms);
    if (formsNum > availableFormsNum) {
      throw std::invalid_argument("Mentioned forms cannot be more than available forms.");
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

bool validateInput(const std::string& date, const std::string& forms, const std::string& vspName) {
   // Validate date format
   if (date.empty() || !std::regex_match(date, std::regex(R"([0-9]{4}-[0-9]{2}-[0-9]{2})"))) {
      throw std::invalid_argument("Invalid date format.");
   }

   // Check if the mentioned forms and available forms match
   try {
      int formsNum = std::stoi(forms);
      int availableFormsNum = std::stoi(availableForms);
      if (formsNum > availableFormsNum) {
         throw std::invalid_argument("Mentioned forms cannot be more than available forms.");
      }
   } catch (const std::invalid_argument& e) {
      std::cerr << e.what() << std::endl;
      return false;
   }
   return true;
}

bool checkForms(const std::string& forms, const std::string& availableForms) {
   try {
      int formsNum = std::stoi(forms);
      int availableFormsNum = std::stoi(availableForms);
      if (formsNum > availableFormsNum) {
         throw std::invalid_argument("Mentioned forms cannot be more than available forms.");
      }
   } catch (const std::invalid_argument& e) {
      std::cerr << e.what() << std::endl;
      return false;
   }
   return true;
}

void printReceipt(const std::string& vspName, const std::string& date, const std::string& forms, const std::string& availableForms) {
   // Prints the receipt document based on the information entered during claim submission.
}

