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
void carryAdditionalBaggage(const std::string& term, const std::string& additionalBaggage);
void submitAsSeparateElement(const std::string& term, const std::string& elementName);

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
  if (!isWellRecognizedOutsideContainerTerm(term)) {
    term = term + '_' + elementName;
  }
}

void carryAdditionalBaggage(const std::string& term, const std::string& additionalBaggage) {
  if (!isWellRecognizedOutsideContainerTerm(term)) {
    term = term + '_' + additionalBaggage;
  }
}

void submitAsSeparateElement(const std::string& term, const std::string& elementName) { if (!isWellRecognizedOutsideContainerTerm(term)) { term = term + '_' + elementName; } }

