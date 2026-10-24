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

std::vector<case_info> search_case(std::string search_term, bool advanced_search);
std::vector<case_info> get_recent_cases();
std::vector<case_info> get_unused_cases();
case_info get_case_info(int case_id);

std::vector<case_info> search_case(std::string search_term, bool advanced_search) {
  // Your implementation here
}

std::vector<case_info> get_recent_cases() {
   std::vector<case_info> recent_cases;
   for (const auto& case_info : cases) {
      if (case_info.access_date >= std::chrono::system_clock::now() - 2 * 24 * 60 * 60) {
         recent_cases.push_back(case_info);
      }
   }
   return recent_cases;
}

std::vector<case_info> get_unused_cases() {
    std::vector<case_info> recent_cases;
    for (const auto& case_info : cases) {
        if (case_info.access_date >= std::chrono::system_clock::now() - 2 * 24 * 60 * 60) {
            recent_cases.push_back(case_info);
        }
    }
    return recent_cases;
}

std::vector<case_info> get_case_info(int case_id) {
    std::vector<case_info> recent_cases;
    for (const auto& case_info : cases) {
        if (case_info.id == case_id) {
            recent_cases.push_back(case_info);
        }
    }
    return recent_cases;
}

