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

bool checkDuplicateSalesmanName(const std::string& name, const std::vector<std::string>& existingNames);
void displayDuplicateWarning(const std::string& name);
std::string generateUniqueName(const std::string& baseName, const std::vector<std::string>& existingNames);
void updateSalesmanName(Salesman& salesman, const std::string& newName);
void processSalesmanName(Salesman& salesman);

bool checkDuplicateSalesmanName(const std::string& name, const std::vector<std::string>& existingNames) {
  for (const auto& existingName : existingNames) {
    if (existingName == name) {
      return true;
    }
  }
  return false;
}

std::string generateUniqueName(const std::string& baseName, const std::vector<std::string>& existingNames) {
  int counter = 0;
  std::string uniqueName = baseName;
  while (checkDuplicateSalesmanName(uniqueName, existingNames)) {
    counter++;
    uniqueName = baseName + std::to_string(counter);
  }
  return uniqueName;
}

void updateSalesmanName(Salesman& salesman, const std::string& newName) { salesman.setName(newName); }

bool processSalesmanName(Salesman& salesman) { std::string newName = salesman.getName(); if (!checkDuplicateSalesmanName(newName, salesman.getNames())) { salesman.setName(newName); return true; } else { std::string uniqueName = generateUniqueName(newName, salesman.getNames()); salesman.setName(uniqueName); return false; } }

