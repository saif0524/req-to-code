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

bool validatePassword(const std::string& password, const std::string& repeatPassword);
void displayError(const std::string& errorMessage);

bool validatePassword(const std::string& password, const std::string& repeatPassword) {
  return password == repeatPassword;
}

void displayError(const std::string& errorMessage) {
  std::cout << errorMessage << std::endl;
}

