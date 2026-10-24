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

void searchTorrents(const std::string& searchTerm);
void displayResults(const std::vector<std::string>& results);
std::vector<std::string> parseResults(const std::string& result);
std::string getSearchTerm();
void setSearchTerm(const std::string& newSearchTerm);

void searchTorrents(const std::string& searchTerm) {
  // Your implementation here
}

void displayResults(const std::vector<std::string>& results) {
    // Iterate over the results
    for (const auto& result : results) {
        // Create a web link for each result
        std::string webLink = "<a href=" + result + ">

std::vector<std::string> parseResults(const std::string& result) {
    std::vector<std::string> webLinks;
    // Extract the web links from the result
    // This is a simplified example and may not work for all cases
    size_t startPos = 0;
    size_t endPos = result.find("<a href=");
    while (endPos != std::string::npos) {
        startPos = endPos;
        endPos = result.find("</a>", startPos);
        if (endPos != std::string::npos) {
            webLinks.push_back(result.substr(startPos, endPos - startPos));
        }
    }
    return webLinks;
}

std::string getSearchTerm() {
    return searchTerm;
}

void setSearchTerm(const std::string& newSearchTerm) {
    searchTerm = newSearchTerm;
    // Trigger a new search
    searchTorrents(searchTerm);
}

