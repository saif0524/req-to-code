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

std::vector<Case> searchSimple(const std::string& query);
std::vector<Case> searchAdvanced(const std::vector<std::string>& criteria);
Case retrieveRecentCase(const std::string& caseId);
Case retrieveInactiveCase(const std::string& caseId);
void scaleSystem(int numCases);

struct Case {
  std::string id;
  std::string description;
  std::chrono::system_clock::time_point accessDate;
  bool matchesQuery(const std::string& query) const;
};

std::vector<Case> searchSimple(const std::string& query) {
  std::vector<Case> results;
  for (const auto& case : cases) {
    if (case.matchesQuery(query)) {
      results.push_back(case);
    }
  }
  return results;
}

template<typename T, typename Criterion>
std::vector<T> searchAdvanced(const std::vector<std::string>& criteria, std::function<bool(const Case&, const Criterion&)> matchesCriterion) {
  std::vector<T> results;
  for (const auto& case : cases) {
    if (std::all_of(criteria.begin(), criteria.end(), [&case, &matchesCriterion](const std::string& criterion) {
      return matchesCriterion(case, criterion);
    })) {
      results.push_back(case);
    }
  }
  return results;
}

Case retrieveRecentCase(const std::string& caseId) { std::vector<Case> recentCases; for (const auto& case : cases) { if (case.accessDate >= std::chrono::system_clock::now() - std::chrono::days(60)) { recentCases.push_back(case); } } return recentCases.front(); }

Case retrieveInactiveCase(const std::string& caseId) { std::vector<Case> inactiveCases; for (const auto& case : cases) { if (case.accessDate < std::chrono::system_clock::now() - std::chrono::days(60)) { inactiveCases.push_back(case); } } if (!inactiveCases.empty()) { return inactiveCases.front(); } else { throw std::runtime_error("Case not found"); } }

template<typename T>
void scaleSystem(int numCases) {
  if (numCases > 1000) {
    // Increase the number of threads for parallel processing
    std::thread::hardware_concurrency();
  } else if (numCases > 500) {
    // Increase the cache size for faster access
    static constexpr int cacheSize = 1024;
  } else {
    // Optimize the search algorithms
    static void optimizeSearchAlgorithms() {
      // Implementation of search algorithm optimization
    }
  }
}

