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

SearchEngine();
Search(std::string query, std::string type, bool adultContent, std::vector<std::string> websites);
Filter(std::vector<std::string> results, std::string filterType, int ageRestriction);
Order(std::vector<std::string> results, std::string orderType);
Store(std::string video, std::string type);

SearchEngine::SearchEngine(std::string query, std::string type, bool adultContent, std::vector<std::string> websites, std::vector<std::string> results) {
  // Implementation of the constructor
}

void SearchEngine::Search(std::string query, std::string type, bool adultContent, std::vector<std::string> websites) {
  // Implementation of the function
}

std::vector<std::string> SearchEngine::Filter(std::vector<std::string> results, std::string filterType, int ageRestriction) {
  // Implementation of the function
}

void SearchEngine::Order(std::vector<std::string> results, std::string orderType) {
    if (orderType == "name") {
        std::stable_sort(results.begin(), results.end());
    } else if (orderType == "size") {
        std::stable_sort(results.begin(), results.end(), [](const std::string& a, const std::string& b) {
            return a.size() > b.size();
        });
    }
}

void SearchEngine::Store(std::string video, std::string type) {
    // Implementation of the function
}

