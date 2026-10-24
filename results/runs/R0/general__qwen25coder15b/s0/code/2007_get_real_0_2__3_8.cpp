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

std::vector<std::string> getHighSchoolCurricula();
std::vector<std::string> getOUSCurricula();
std::vector<std::string> getACMCurricula();
std::vector<std::string> getUOCurricula();
std::vector<std::string> mergeCurricula(const std::vector<std::string>& ousCurricula, const std::vector<std::string>& acmCurricula, const std::vector<std::string>& uoCurricula);

std::vector<std::string> getHighSchoolCurricula() {
  std::vector<std::string> ousCurricula = getOUSCurricula();
  std::vector<std::string> acmCurricula = getACMCurricula();
  std::vector<std::string> uoCurricula = getUOCurricula();
  return mergeCurricula(ousCurricula, acmCurricula, uoCurricula);
}

std::vector<std::string> getOUSCurricula() {
  std::vector<std::string> curricula;
  // Fetch the recommended curricula from the OUS website
  // Add the recommended curricula to the curricula vector
  return curricula;
}

std::vector<std::string> getACMCurricula() {
  std::vector<std::string> curricula;
  // Fetch the recommended curricula from the ACM website
  // Add the recommended curricula to the curricula vector
  return curricula;
}

std::vector<std::string> getUOCurricula() {
  std::vector<std::string> curricula;
  // Fetch the recommended curricula from the UO website
  // Add the recommended curricula to the curricula vector
  return curricula;
}

std::vector<std::string> mergeCurricula(const std::vector<std::string>& ousCurricula, const std::vector<std::string>& acmCurricula, const std::vector<std::string>& uoCurricula) {
  std::vector<std::string> mergedCurricula;
  mergedCurricula.insert(mergedCurricula.end(), ousCurricula.begin(), ousCurricula.end());
  mergedCurricula.insert(mergedCurricula.end(), acmCurricula.begin(), acmCurricula.end());
  mergedCurricula.insert(mergedCurricula.end(), uoCurricula.begin(), uoCurricula.end());
  return mergedCurricula;
}

