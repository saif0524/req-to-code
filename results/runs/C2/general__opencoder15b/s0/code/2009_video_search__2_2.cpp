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

void SearchEngine::Search(std::string query, std::string type, bool adultContent, std::vector<std::string> websites) {
    std::vector<std::string> results = /* call the function to get the results */;
    std::vector<std::string> filteredResults = Filter(results, filterType, ageRestriction);
    std::vector<std::string> orderedResults = Order(filteredResults, orderType);
    Store(orderedResults, type);
}

class SearchEngine {
public:
    SearchEngine() {}
    void Search(std::string query, std::string type, bool adultContent, std::vector<std::string> websites) {
        std::vector<std::string> results = /* call the function to get the results */;
        std::vector<std::string> filteredResults = Filter(results, filterType, ageRestriction);
        std::vector<std::string> orderedResults = Order(filteredResults, orderType);
        Store(orderedResults, type);
    }
    void Order(std::vector<std::string> results, std::string orderType) {
        if (orderType == "name") {
            std::stable_sort(results.begin(), results.end());
        } else if (orderType == "size") {
            std::stable_sort(results.begin(), results.end(), [] (const std::string& a, const std::string& b) {
                return a.size() > b.size();
            });
        }
    }
    void Filter(std::vector<std::string> results, std::string filterType, int ageRestriction) {
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
    void Store(std::string video, std::string type) {
        /* store the video in the user's database */;
    }
};

void SearchEngine::Order(std::vector<std::string> results, std::string orderType) {
     if (orderType == "name") {
         std::stable_sort(results.begin(), results.end());
     } else if (orderType == "size") {
         std::stable_sort(results.begin(), results.end(), [] (const std::string& a, const std::string& b) {
             return a.size() > b.size();
         });
     }
}

