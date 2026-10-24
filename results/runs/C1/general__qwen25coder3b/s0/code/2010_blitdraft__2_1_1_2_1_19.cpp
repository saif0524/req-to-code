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

std::string validateUserInput(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName);
std::string generateErrorMessage(const std::string& errorType);
bool checkCriteria(const std::string& criteria);
bool checkRequiredFields(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName);
void handleSaveAction(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName);

std::string validateUserInput(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName) {
  std::string errorMessage;

  if (!checkCriteria("username")) {
    errorMessage = generateErrorMessage("username");
  }

  if (!checkCriteria("email")) {
    errorMessage = generateErrorMessage("email");
  }

  if (!checkCriteria("password")) {
    errorMessage = generateErrorMessage("password");
  }

  if (!checkCriteria("firstName")) {
    errorMessage = generateErrorMessage("firstName");
  }

  if (!checkCriteria("lastName")) {
    errorMessage = generateErrorMessage("lastName");
  }

  if (!checkRequiredFields(username, email, password, firstName, lastName)) {
    errorMessage = generateErrorMessage("requiredFields");
  }

  return errorMessage;
}

std::string generateErrorMessage(const std::string& errorType) {  std::string errorMessage;  int errorTypeInt = std::stoi(errorType);  switch (errorTypeInt) {    case 1:      errorMessage = "Username is required and must be unique.";      break;    case 2:      errorMessage = "Email is required and must be valid.";      break;    case 3:      errorMessage = "Password is required and must be at least 8 characters long.";      break;    case 4:      errorMessage = "First name is required.";      break;    case 5:      errorMessage = "Last name is required.";      break;    case 6:      errorMessage = "All required fields must be filled.";      break;    default:      errorMessage = "Unknown error.";      break;  }  return errorMessage;}

bool checkCriteria(const std::string& criteria) {
  switch (std::stoi(criteria)) {
    case 1:
      // Check if username is unique and not empty
      return !username.empty() && username.size() <= 50;
    case 2:
      // Check if email is valid
      return std::regex_match(email, std::regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}")) && email.size() <= 100;
    case 3:
      // Check if password is at least 8 characters long
      return password.size() >= 8;
    case 4:
      // Check if first name is not empty
      return !firstName.empty() && firstName.size() <= 50;
    case 5:
      // Check if last name is not empty
      return !lastName.empty() && lastName.size() <= 50;
    default:
      // Return false for unknown criteria
      return false;
  }
}

bool checkRequiredFields(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName) {
  return !username.empty() && !email.empty() && !password.empty() && !firstName.empty() && !lastName.empty();
}

void handleSaveAction(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName) {
  std::string errorMessage = validateUserInput(username, email, password, firstName, lastName);
  if (!errorMessage.empty()) {
    std::cout << errorMessage << std::endl;
  }
}

