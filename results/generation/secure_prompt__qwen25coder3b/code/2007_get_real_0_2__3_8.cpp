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

std::vector<std::string> get_ous_curricula();
std::vector<std::string> get_acm_curricula();
std::vector<std::string> get_other_university_curricula();
std::vector<std::string> combine_curricula(const std::vector<std::string>& ous_curricula, const std::vector<std::string>& acm_curricula, const std::vector<std::string>& other_university_curricula);
std::string format_curricula_list(const std::vector<std::string>& curricula);

std::vector<std::string> get_ous_curricula() {
  std::vector<std::string> ous_curricula;
  // Logic to retrieve OUS curricula
  // Example: ous_curricula.push_back("Course A");
  // Example: ous_curricula.push_back("Course B");
  return ous_curricula;
}

std::vector<std::string> get_acm_curricula() {
  std::vector<std::string> acm_curricula;
  // Logic to retrieve ACM curricula
  // Example: acm_curricula.push_back("Course C");
  // Example: acm_curricula.push_back("Course D");
  return acm_curricula;
}

std::vector<std::string> get_other_university_curricula() {
  std::vector<std::string> other_university_curricula;
  // Logic to retrieve other university curricula
  // Example: other_university_curricula.push_back("Course E");
  // Example: other_university_curricula.push_back("Course F");
  return other_university_curricula;
}

std::vector<std::string> combine_curricula(const std::vector<std::string>& ous_curricula, const std::vector<std::string>& acm_curricula, const std::vector<std::string>& other_university_curricula) {
  std::vector<std::string> combined_curricula;
  combined_curricula.insert(combined_curricula.end(), ous_curricula.begin(), ous_curricula.end());
  combined_curricula.insert(combined_curricula.end(), acm_curricula.begin(), acm_curricula.end());
  combined_curricula.insert(combined_curricula.end(), other_university_curricula.begin(), other_university_curricula.end());
  return combined_curricula;
}

std::string format_curricula_list(const std::vector<std::string>& curricula) {
  std::stringstream ss;
  for (size_t i = 0; i < curricula.size(); ++i) {
    ss << curricula[i];
    if (i < curricula.size() - 1) {
      ss << "\n";
    }
  }
  return ss.str();
}

