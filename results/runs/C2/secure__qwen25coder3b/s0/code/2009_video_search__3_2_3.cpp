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

void updateDatabase();
std::vector<VideoResult> searchVideos(const std::string& query, bool includeHosts, bool includeLinks);
std::vector<VideoResult> sortResults(const std::vector<VideoResult>& results, SortOrder order);
void displayResults(const std::vector<VideoResult>& results);
void handleNoResults();

void updateDatabase() {
  std::vector<std::string> urls;
  // Add URLs to the 'urls' vector
  for (const auto& url : urls) {
    // Make HTTP request to the URL
    // Parse the response and store the results
  }
}

struct VideoResult { std::string name; int length; std::string date; std::string link; }; std::vector<VideoResult> searchVideos(const std::string& query, bool includeHosts, bool includeLinks) { std::vector<VideoResult> results; if (includeHosts) { // Make HTTP request to video hosting sites and parse responses // Add results to the 'results' vector } if (includeLinks) { // Make HTTP request to video linking sites and parse responses // Add results to the 'results' vector } return sortResults(results, SortOrder::Length); }

enum SortOrder { Length, Date, Alphabetical }; std::vector<VideoResult> sortResults(const std::vector<VideoResult>& results, SortOrder order) { std::vector<VideoResult> sortedResults = results; bool swapped; do { swapped = false; for (size_t i = 0; i < sortedResults.size() - 1; ++i) { if (order == SortOrder::Length) { if (sortedResults[i].length > sortedResults[i + 1].length) { std::swap(sortedResults[i], sortedResults[i + 1]); swapped = true; } } else if (order == SortOrder::Date) { if (sortedResults[i].date > sortedResults[i + 1].date) { std::swap(sortedResults[i], sortedResults[i + 1]); swapped = true; } } else if (order == SortOrder::Alphabetical) { if (sortedResults[i].name > sortedResults[i + 1].name) { std::swap(sortedResults[i], sortedResults[i + 1]); swapped = true; } } } } while (swapped); return sortedResults; }

void displayResults(const std::vector<VideoResult>& results) { for (const auto& result : results) { std::cout << "Video Name: " << result.name << std::endl; std::cout << "Length: " << result.length << std::endl; std::cout << "Date Posted: " << result.date << std::endl; std::cout << "Link: " << result.link << std::endl; std::cout << "-------------------------" << std::endl; } }

void handleNoResults() { std::cout << "No results were found for this search." << std::endl; }

