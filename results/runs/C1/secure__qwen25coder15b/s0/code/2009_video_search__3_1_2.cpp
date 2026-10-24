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

void startTorrentSearch(const std::string& searchTerm);
void queryTorrentWebsites(const std::string& searchTerm);
void displayTorrentResults(const std::vector<TorrentResult>& results);
void sortTorrentResults(std::vector<TorrentResult>& results, const std::string& columnHeader);
void nextTorrentPage(std::vector<TorrentResult>& results);

void startTorrentSearch(const std::string& searchTerm) {
  queryTorrentWebsites(searchTerm);
}

void queryTorrentWebsites(const std::string& searchTerm) {
  std::vector<TorrentResult> results = TorrentSearchEngine::queryTorrentWebsites(searchTerm);
  return results;
}

void displayTorrentResults(const std::vector<TorrentResult>& results) {
  TorrentSearchEngine::displayTorrentResults(results);
}

void sortTorrentResults(std::vector<TorrentResult>& results, const std::string& columnHeader) {
  std::sort(results.begin(), results.end(), [&](const TorrentResult& a, const TorrentResult& b) {
    return a[columnHeader] < b[columnHeader];
  });
}

void nextTorrentPage(std::vector<TorrentResult>& results) {
  // Fetch the next set of results based on the current search term and the current page number
  std::vector<TorrentResult> nextResults = TorrentSearchEngine::queryTorrentWebsites(results.back().searchTerm, results.back().pageNumber + 1);

  // Update the current page number and the results vector with the next set of results
  results.back().pageNumber += 1;
  results.back().results = nextResults;

  // Handle any errors that may occur during the database or API call
  if (nextResults.empty()) {
    // Handle the error, e.g., display an error message to the user
  }
}

