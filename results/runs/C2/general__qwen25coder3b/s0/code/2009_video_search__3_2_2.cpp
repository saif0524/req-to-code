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

std::vector<std::string> queryVideoHosts(const std::string& searchTerm);
std::vector<std::string> queryVideoLinks(const std::string& searchTerm);
void displayResults(const std::vector<std::string>& results);
void sortResults(std::vector<std::string>& results, bool ascending);
void filterResults(std::vector<std::string>& results, const std::vector<std::string>& selectedWebsites);

std::vector<std::string> queryVideoHosts(const std::string& searchTerm) { return {}; }

std::vector<std::string> queryVideoLinks(const std::string& searchTerm) {
  std::vector<std::string> hostingResults = queryVideoHosts(searchTerm);
  std::vector<std::string> videoLinks;

  for (const auto& result : hostingResults) {
    // Assuming each result is a URL, extract video links from it
    // This is a placeholder for actual logic to extract video links
    videoLinks.push_back(result);
  }

  return videoLinks;
}

void displayResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

void sortResults(std::vector<std::string>& results, bool ascending) {
  std::sort(results.begin(), results.end(), [ascending](const std::string& a, const std::string& b) {
    return ascending ? a < b : a > b;
  });
}

void filterResults(std::vector<std::string>& results, const std::vector<std::string>& selectedWebsites) {
  results.erase(std::remove_if(results.begin(), results.end(), [&selectedWebsites](const std::string& result) {
    return std::find(selectedWebsites.begin(), selectedWebsites.end(), result) == selectedWebsites.end();
  }), results.end());
}

