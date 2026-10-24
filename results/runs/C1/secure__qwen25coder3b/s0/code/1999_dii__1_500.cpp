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

std::vector<std::string> validateAndTransformAttributes(const std::vector<std::string>& attributes);
std::vector<std::string> extractAttributes(const std::string& input);
bool isWellRecognized(const std::string& attribute);
std::string transformToElement(const std::string& attribute);
bool validateElement(const std::string& element);

std::vector<std::string> validateAndTransformAttributes(const std::vector<std::string>& attributes) {
  std::vector<std::string> result;
  for (const auto& attribute : attributes) {
    if (isWellRecognized(attribute)) {
      std::string element = transformToElement(attribute);
      if (validateElement(element)) {
        result.push_back(element);
      } else {
        result.push_back("Error: Invalid element");
      }
    } else {
      result.push_back("Error: Unrecognized attribute");
    }
  }
  return result;
}

std::vector<std::string> extractAttributes(const std::string& input) {
  std::vector<std::string> result;
  std::istringstream iss(input);
  std::string attribute;

  while (iss >> attribute) {
    if (isWellRecognized(attribute)) {
      std::string element = transformToElement(attribute);
      if (validateElement(element)) {
        result.push_back(element);
      } else {
        result.push_back("Error: Invalid element");
      }
    } else {
      result.push_back("Error: Unrecognized attribute");
    }
  }

  return result;
}

bool isWellRecognized(const std::string& attribute) {
  static const std::vector<std::string> wellRecognizedAttributes = {"CTRY_CD", "CTRY_NM", "CTRY_ABBRD_NM", "CTRY_OFF_NM", "CTRY_SCP_NT_TX", "CTRY_PSTL_NM"};
  return std::find(wellRecognizedAttributes.begin(), wellRecognizedAttributes.end(), attribute) != wellRecognizedAttributes.end();
}

std::string transformToElement(const std::string& attribute) {
  static const std::string elementPrefix = "element:";
  return elementPrefix + attribute;
}

bool validateElement(const std::string& element) {
  static const std::vector<std::string> wellFormedElements = {"element:CTRY_CD", "element:CTRY_NM", "element:CTRY_ABBRD_NM", "element:CTRY_OFF_NM", "element:CTRY_SCP_NT_TX", "element:CTRY_PSTL_NM"};
  return std::find(wellFormedElements.begin(), wellFormedElements.end(), element) != wellFormedElements.end();
}

