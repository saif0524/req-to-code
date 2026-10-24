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

bool isWellRecognizedOutsideContainerTerm(const std::string& term);
void designateAsElement(const std::string& term, const std::string& elementName);
void identifyAsAttribute(const std::string& term, const std::string& attributeName);
void limitProliferationOfTags(const std::string& term, const std::string& tagName);
void useXML_Attributes sparingly(const std::string& term, const std::string& attributeName);

bool isWellRecognizedOutsideContainerTerm(const std::string& term) {
  const std::vector<std::string> wellKnownTerms = {
    "CTRY_CD", "CTRY_NM", "CTRY_ABBRD_NM", "CTRY_OFF_NM", "CTRY_SCP_NT_TX", "CTRY_PSTL_NM"
  };

  for (const auto& knownTerm : wellKnownTerms) {
    if (knownTerm == term) {
      return true;
    }
  }

  return false;
}

void designateAsElement(const std::string& term, const std::string& elementName) {
  const std::vector<std::string> wellKnownTerms = {
    "CTRY_CD", "CTRY_NM", "CTRY_ABBRD_NM", "CTRY_OFF_NM", "CTRY_SCP_NT_TX", "CTRY_PSTL_NM"
  };

  for (const auto& knownTerm : wellKnownTerms) {
    if (knownTerm == term) {
      return true;
    }
  }

  return false;
}

void identifyAsAttribute(const std::string& term, const std::string& attributeName) {
  if (isWellRecognizedOutsideContainerTerm(term)) {
    // Identify the term as an attribute
    // Example: ctry.addAttribute(attributeName);
  } else {
    // The term is not well recognized outside its container term
    // Example: throw std::invalid_argument("Term is not well recognized outside its container term");
  }
}

void limitProliferationOfTags(const std::string& term, const std::string& tagName) {
  if (isWellRecognizedOutsideContainerTerm(term)) {
    // Identify the term as an attribute
    // Example: ctry.addAttribute(attributeName);
  } else {
    // The term is not well recognized outside its container term
    // Example: throw std::invalid_argument("Term is not well recognized outside its container term");
  }
}

void useXML_Attributes sparingly(const std::string& term, const std::string& attributeName) {
  if (isWellRecognizedOutsideContainerTerm(term)) {
    // Use XML_Attributes sparingly
    // Example: ctry.addAttribute(attributeName);
  } else {
    // The term is not well recognized outside its container term
    // Example: throw std::invalid_argument("Term is not well recognized outside its container term");
  }
}

