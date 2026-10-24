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

std::vector<std::string> searchVideos(std::string searchTerm);
void sortResults(std::vector<std::string>& results, std::string sortBy);
void filterWebsites(std::vector<std::string>& results, std::vector<std::string> selectedWebsites);
void nextPage(std::vector<std::string>& results);
std::vector<std::string> getHostingSites();

std::vector<std::string> searchVideos(std::string searchTerm) {
  // Your implementation here
}

void sortResults(std::vector<std::string>& results, std::string sortBy) {
   for (int i = 0; i < results.size(); i++) {
       for (int j = i + 1; j < results.size(); j++) {
           if (sortBy == "asc") {
               if (results[i] > results[j]) {
                   std::swap(results[i], results[j]);
               }
           } else if (sortBy == "desc") {
               if (results[i] < results[j]) {
                   std::swap(results[i], results[j]);
               }
           }
       }
   }
}

void filterWebsites(std::vector<std::string>& results, std::vector<std::string> selectedWebsites) {
    results.erase(std::remove_if(results.begin(), results.end(), [&selectedWebsites](const std::string& website) {
        return std::find(selectedWebsites.begin(), selectedWebsites.end(), website) == selectedWebsites.end();
    }), results.end());
}

void nextPage(std::vector<std::string>& results) {
    // Get the current page size
    int pageSize = 10;
    // Get the current page index
    int currentPageIndex = (results.size() / pageSize) + 1;
    // Get the next page
    results = std::vector<std::string>(results.begin() + (currentPageIndex * pageSize), results.end());
}

std::vector<std::string> getHostingSites() {
    // Your implementation here
}

