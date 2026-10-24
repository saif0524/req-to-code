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

std::vector<Case> search_case(std::string search_term);

std::vector<Case> search_case(std::string search_term) {
  std::vector<Case> result;
  for (auto& case_ : cases) {
    if (std::find_if(case_.begin(), case_.end(), [&](const std::string& s) { return s.find(search_term) != std::string::npos; }) != case_.end()) {
      result.push_back(case_);
    }
  }
  return result;
}

