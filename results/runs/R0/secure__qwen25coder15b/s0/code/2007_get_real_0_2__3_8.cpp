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
void displayCurricula(const std::vector<std::string>& curricula);
std::vector<std::string> filterCurricula(const std::vector<std::string>& curricula, const std::string& keyword);
void updateCurricula(std::vector<std::string>& curricula, const std::vector<std::string>& newCurricula);

std::vector<std::string> getHighSchoolCurricula() {
  std::vector<std::string> curricula = getCurricula();
  std::vector<std::string> filteredCurricula = filterCurricula(curricula, "CS");
  return filteredCurricula;
}

void displayCurricula(const std::vector<std::string>& curricula) {
  for (const auto& curriculum : curricula) {
    std::cout << curriculum << std::endl;
  }
}

std::vector<std::string> filterCurricula(const std::vector<std::string>& curricula, const std::string& keyword) {
  std::vector<std::string> filteredCurricula;
  for (const auto& curriculum : curricula) {
    if (curriculum.find(keyword) != std::string::npos) {
      filteredCurricula.push_back(curriculum);
    }
  }
  return filteredCurricula;
}

void updateCurricula(std::vector<std::string>& curricula, const std::vector<std::string>& newCurricula) {
  std::vector<std::string> filteredCurricula;
  for (const auto& curriculum : newCurricula) {
    if (std::find(curricula.begin(), curricula.end(), curriculum) == curricula.end()) {
      filteredCurricula.push_back(curriculum);
    }
  }
  curricula = filteredCurricula;
}

