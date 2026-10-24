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

bool checkDuplicateSalesmanID(const std::string& id);
bool checkDuplicateSalesmanName(const std::string& name);
void displayDuplicateWarning(const std::string& name);
void addDifferentiatingIndicator(std::string& name);
void processSalesmanData(const std::string& id, const std::string& name);

bool checkDuplicateSalesmanID(const std::string& id) {
  static std::set<std::string> salesmanIDs;
  return salesmanIDs.find(id) != salesmanIDs.end();
}

bool checkDuplicateSalesmanName(const std::string& name) {
  static std::set<std::string> salesmanNames;
  return salesmanNames.find(name) != salesmanNames.end();
}

void displayDuplicateWarning(const std::string& name) {
  static std::set<std::string> salesmanNames;
  if (salesmanNames.find(name) != salesmanNames.end()) {
    std::cout << "Warning: Duplicate name detected: "

void addDifferentiatingIndicator(std::string& name) {
  static std::set<std::string> usedNames;
  if (usedNames.find(name) != usedNames.end()) {
    name += '*'; // Add a distinguishing character
  }
  usedNames.insert(name);
}

void processSalesmanData(const std::string& id, const std::string& name) {
  if (checkDuplicateSalesmanID(id)) {
    std::cout << "Warning: Duplicate ID detected: "

