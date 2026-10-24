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

void SearchEngine::Filter(std::vector<std::string> results, std::string filterType, int ageRestriction) {
    std::vector<std::string> filteredResults;
    for (const auto& result : results) {
        if (filterType == "size" && result.size() <= ageRestriction) {
            filteredResults.push_back(result);
        } else if (filterType == "age" && result.age >= ageRestriction) {
            filteredResults.push_back(result);
        }
    }
    Order(filteredResults, orderType);
    Store(filteredResults, type);
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

