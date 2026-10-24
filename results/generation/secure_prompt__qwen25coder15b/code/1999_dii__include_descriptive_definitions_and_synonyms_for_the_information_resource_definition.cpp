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

std::vector<std::string> search_term(const std::string& query);
std::string get_term_description(const std::string& term);
void update_term_description(const std::string& term, const std::string& new_description);

std::vector<std::string> search_term(const std::string& query) {
  std::vector<std::string> result;
  for (const auto& term : registry) {
    if (term.find(query) != std::string::npos) {
      result.push_back(term);
    }
  }
  return result;
}

std::string get_term_description(const std::string& term) {
  std::vector<std::string> result;
  for (const auto& term : registry) {
    if (term.find(query) != std::string::npos) {
      result.push_back(term);
    }
  }
  return result;
}

void update_term_description(const std::string& term, const std::string& new_description) {
  for (auto& term : registry) {
    if (term == term) {
      term = new_description;
      return;
    }
  }
  return "Term not found";
}

