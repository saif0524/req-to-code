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

bool isWellRecognizedOutsideContainer(const std::string& term);
bool isCharacteristic(const std::string& term);
bool shouldUseXMLAttributes(const std::string& term);
void processTerm(const std::string& term);
void handleTerm(const std::string& term);

bool isWellRecognizedOutsideContainer(const std::string& term) {
  // Define a set of well recognized terms outside the container
  std::set<std::string> wellRecognizedTerms = {
    "CTRY_CD", "CTRY_NM", "CTRY_ABBRD_NM", "CTRY_OFF_NM",
    "CTRY_SCP_NT_TX", "CTRY_PSTL_NM"
  };

  // Check if the term is in the set of well recognized terms
  return wellRecognizedTerms.find(term) != wellRecognizedTerms.end();
}

bool isCharacteristic(const std::string& term) {
  // Define a set of characteristic terms for the entity CTRY
  std::set<std::string> characteristicTerms = {
    "CTRY_CD", "CTRY_NM", "CTRY_ABBRD_NM", "CTRY_OFF_NM",
    "CTRY_SCP_NT_TX", "CTRY_PSTL_NM"
  };

  // Check if the term is in the set of characteristic terms
  return characteristicTerms.find(term) != characteristicTerms.end();
}

bool shouldUseXMLAttributes(const std::string& term) {
  // Check if the term is well recognized outside its container
  if (isWellRecognizedOutsideContainer(term)) {
    // If recognized, use XML_Attributes sparingly
    return true;
  } else {
    // Otherwise, do not use XML_Attributes
    return false;
  }
}

void processTerm(const std::string& term) {
  if (shouldUseXMLAttributes(term)) {
    // Handle the term as an XML_Attribute
    std::cout << "Handling term as XML_Attribute: " << term << std::endl;
  } else {
    // Handle the term as a regular attribute
    std::cout << "Handling term as regular attribute: " << term << std::endl;
  }
}

void handleTerm(const std::string& term) {
  if (isWellRecognizedOutsideContainer(term)) {
    if (shouldUseXMLAttributes(term)) {
      std::cout << "Handling term as XML_Attribute: " << term << std::endl;
    } else {
      std::cout << "Handling term as regular attribute: " << term << std::endl;
    }
  } else {
    std::cout << "Term is not well recognized outside its container: " << term << std::endl;
  }
}

