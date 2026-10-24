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
std::vector<std::string> getOusCurricula();
std::vector<std::string> getAcademicCurricula();
std::vector<std::string> getUniversityCurricula();
std::vector<std::string> mergeCurricula(const std::vector<std::string>& ousCurricula, const std::vector<std::string>& academicCurricula, const std::vector<std::string>& universityCurricula);

std::vector<std::string> getHighSchoolCurricula() {
  std::vector<std::string> ousCurricula = getOusCurricula();
  std::vector<std::string> academicCurricula = getAcademicCurricula();
  std::vector<std::string> universityCurricula = getUniversityCurricula();
  return mergeCurricula(ousCurricula, academicCurricula, universityCurricula);
}

std::vector<std::string> getOusCurricula() {
  std::vector<std::string> ousCurricula;
  // Logic to retrieve OUS curricula
  return ousCurricula;
}

std::vector<std::string> getAcademicCurricula() {
  std::vector<std::string> academicCurricula;
  // Logic to retrieve ACM curricula
  return academicCurricula;
}

std::vector<std::string> getUniversityCurricula() {
  std::vector<std::string> universityCurricula;
  // Logic to retrieve university curricula
  return universityCurricula;
}

std::vector<std::string> mergeCurricula(const std::vector<std::string>& ousCurricula, const std::vector<std::string>& academicCurricula, const std::vector<std::string>& universityCurricula) {
  std::vector<std::string> mergedCurricula;
  mergedCurricula.insert(mergedCurricula.end(), ousCurricula.begin(), ousCurricula.end());
  mergedCurricula.insert(mergedCurricula.end(), academicCurricula.begin(), academicCurricula.end());
  mergedCurricula.insert(mergedCurricula.end(), universityCurricula.begin(), universityCurricula.end());
  return mergedCurricula;
}

