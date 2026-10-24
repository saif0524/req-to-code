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
void handleUserCreation(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName);

std::string validateUserInput(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName) {
  std::string error;

  if (username.empty() || !std::all_of(username.begin(), username.end(), ::isalnum)) {
    error = "Invalid username: must be alphanumeric and not empty.\n";
  }

  if (email.empty() || !std::regex_match(email, std::regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}"))) {
    error = "Invalid email: must be a valid email address.\n";
  }

  if (password.empty() || password.length() < 8) {
    error = "Invalid password: must be at least 8 characters long.\n";
  }

  if (firstName.empty()) {
    error = "Invalid first name: must not be empty.\n";
  }

  if (lastName.empty()) {
    error = "Invalid last name: must not be empty.\n";
  }

  return error;
}

std::string generateErrorMessage(const std::string& errorType) {  std::hash<std::string> hash;  int errorTypeHash = hash(errorType);  switch (errorTypeHash) {    case 0:      return "Invalid username: must be alphanumeric and not empty.\n";    case 1:      return "Invalid email: must be a valid email address.\n";    case 2:      return "Invalid password: must be at least 8 characters long.\n";    case 3:      return "Invalid first name: must not be empty.
";    case 4:      return "Invalid last name: must not be empty.
";    default:      return "Unknown error type.
";  } }

void handleUserCreation(const std::string& username, const std::string& email, const std::string& password, const std::string& firstName, const std::string& lastName) {
  std::string error = validateUserInput(username, email, password, firstName, lastName);

  if (!error.empty()) {
    std::cout << error;
    return;
  }

  // Proceed with user creation logic here
  std::cout << "User created successfully!" << std::endl;
}

