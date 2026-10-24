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

void searchTorrents(std::string searchTerm);
void processTorrentResults(std::vector<TorrentResult> results);
void sortTorrentResults(std::string columnHeader, bool ascending);
void nextPageTorrentResults();

template <typename T>
void processTorrentResults(std::vector<T> results) {
  // Sort the results
  std::sort(results.begin(), results.end(), [] (const T& a, const T& b) {
    // Sort by the specified column header
    if (a.columnHeader == b.columnHeader) {
      // Sort in ascending order if ascending is true, otherwise sort in descending order
      return a.ascending ? a.value < b.value : a.value > b.value;
    }
    // Sort by the column header in ascending order
    return a.columnHeader < b.columnHeader;
  });

  // Display the results
  for (const auto& result : results) {
    std::cout << "Result: " << result.value << std::endl;
  }
}

void nextPageTorrentResults() {
  // Get the current page number
  int currentPage = getCurrentPage();

  // Get the total number of pages
  int totalPages = getTotalPages();

  // If there is a next page, display it
  if (currentPage < totalPages) {
    // Get the next page results
    std::vector<T> nextPageResults = getNextPageResults();

    // Process and display the next page results
    processTorrentResults(nextPageResults);
  }
}

class VideoSearchEngine {
   // ...
   void sortTorrentResults(std::string columnHeader, bool ascending) {
     // Sort the results
     std::sort(results.begin(), results.end(), [] (const TorrentResult& a, const TorrentResult& b) {
       // Sort by the specified column header
       if (a.columnHeader == b.columnHeader) {
         // Sort in ascending order if ascending is true, otherwise sort in descending order
         return a.ascending ? a.value < b.value : a.value > b.value;
       }
       // Sort by the column header in ascending order
       return a.columnHeader < b.columnHeader;
     });

     // Display the results
     for (const auto& result : results) {
       std::cout << "Result: " << result.value << std::endl;
     }
   }
   // ...
}

void nextPageTorrentResults() {
   // Get the current page number
   int currentPage = getCurrentPage();

   // Get the total number of pages
   int totalPages = getTotalPages();

   // If there is a next page, display it
   if (currentPage < totalPages) {
     // Get the next page results
     std::vector<TorrentResult> nextPageResults = getNextPageResults();

     // Process and display the next page results
     processTorrentResults(nextPageResults);
   }
}

