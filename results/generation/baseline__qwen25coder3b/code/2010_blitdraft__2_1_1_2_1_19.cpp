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

std::string generateErrorMessage(const std::string& errorType) {
  switch (errorType) {
    case "username":
      return "Username is required and must be unique.";
    case "email":
      return "Email is required and must be valid.";
    case "password":
      return "Password is required and must be at least 8 characters long.";
    case "firstName":
      return "First name is required.";
    case "lastName":
      return "Last name is required.";
    case "requiredFields":
      return "All required fields must be filled.";
    default:
      return "Unknown error.";
  }
}

bool checkCriteria(const std::string& criteria) {
  switch (criteria) {
    case "username":
      // Check if username is unique and not empty
      return !username.empty() && username.size() <= 50;
    case "email":
      // Check if email is valid
      return std::regex_match(email, std::regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}") && email.size() <= 100;
    case "password":
      // Check if password is at least 8 characters long
      return password.size() >= 8;
    case "firstName":
      // Check if first name is not empty
      return !firstName.empty() && firstName.size() <= 50;
    case "lastName":
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

