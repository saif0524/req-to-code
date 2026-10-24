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

bool validateWebDesignConsistency(const std::string& webDesign, const std::string& oussDesign);
double calculateAdaptabilityScore(const std::string& webDesign);
double calculateCorrectnessScore(const std::string& webDesign);
double calculateFlexibilityScore(const std::string& webDesign);
double calculateUsabilityScore(const std::string& webDesign);

bool validateWebDesignConsistency(const std::string& webDesign, const std::string& oussDesign) {
  if (webDesign.find(oussDesign) != std::string::npos) {
    return true;
  }
  return false;
}

double calculateAdaptabilityScore(const std::string& webDesign) {
  int conventionCount = 0;
  std::string oussDesign = "OUS site conventions";
  size_t pos = webDesign.find(oussDesign);
  while (pos != std::string::npos) {
    conventionCount++;
    pos = webDesign.find(oussDesign, pos + 1);
  }
  return conventionCount;
}

double calculateCorrectnessScore(const std::string& webDesign) {
  std::istringstream iss(webDesign);
  std::string word;
  int conventionCount = 0;
  std::string oussDesign = "OUS site conventions";

  while (iss >> word) {
    if (word == oussDesign) {
      conventionCount++;
    }
  }

  int totalWords = std::count_if(webDesign.begin(), webDesign.end(), [](unsigned char c){ return std::isspace(c); }) + 1;
  return static_cast<double>(conventionCount) / totalWords;
}

double calculateFlexibilityScore(const std::string& webDesign) {
  std::istringstream iss(webDesign);
  std::string word;
  int flexibilityCount = 0;
  std::string flexibilityKeywords[] = {"responsive", "adaptive", "scalable", "modular", "flexible"};

  while (iss >> word) {
    for (const auto& keyword : flexibilityKeywords) {
      if (word == keyword) {
        flexibilityCount++;
        break;
      }
    }
  }

  int totalWords = std::count_if(webDesign.begin(), webDesign.end(), [](unsigned char c){ return std::isspace(c); }) + 1;
  return static_cast<double>(flexibilityCount) / totalWords;
}

double calculateUsabilityScore(const std::string& webDesign) {
  std::istringstream iss(webDesign);
  std::string word;
  int usabilityCount = 0;
  std::string usabilityKeywords[] = {"user-friendly", "easy-to-use", "intuitive", "accessible", "user-centered"};

  while (iss >> word) {
    for (const auto& keyword : usabilityKeywords) {
      if (word == keyword) {
        usabilityCount++;
        break;
      }
    }
  }

  int totalWords = std::count_if(webDesign.begin(), webDesign.end(), [](unsigned char c){ return std::isspace(c); }) + 1;
  return static_cast<double>(usabilityCount) / totalWords;
}

