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
void displayErrorMessage(const std::string& message);

bool validatePassword(const std::string& password, const std::string& repeatPassword) {
  return password == repeatPassword;
}

void displayErrorMessage(const std::string& message) { std::cout << message << std::endl; }

