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

std::vector<SearchResult> queryTorrentWebsites(const std::string& searchTerm);
void displaySearchResults(const std::vector<SearchResult>& results);
void sortSearchResults(std::vector<SearchResult>& results, const std::string& columnHeader);
std::vector<SearchResult> getNextPageResults(const std::vector<SearchResult>& results, size_t currentPage);

std::vector<SearchResult> queryTorrentWebsites(const std::string& searchTerm) {
  if (searchTerm.empty()) {
    return {}; // Return an empty vector if the search term is empty
  }
  // Simulate querying the database and returning results
  return {SearchResult{"Website1", 100, 200, 1000, "2023-10-01", "http://example.com"},\nSearchResult{"Website2", 200, 300, 2000, "2023-10-02", "http://example.com"}};\n}

void displaySearchResults(const std::vector<SearchResult>& results) {
  for (const auto& result : results) {
    std::cout << "Website: " << result.website << ", Seeds: " << result.seeds << ", Peers: " << result.peers << ", Size: " << result.size << ", Date: " << result.date << ", Link: " << result.link << std::endl;
  }
}

void sortSearchResults(std::vector<SearchResult>& results, const std::string& columnHeader) {
  if (results.empty()) {
    return;
  }
  // Define a comparison function based on the column header
  auto compare = [](const SearchResult& a, const SearchResult& b) {
    if (columnHeader == "website") {
      return a.website < b.website;
    } else if (columnHeader == "seeds") {
      return a.seeds < b.seeds;
    } else if (columnHeader == "peers") {
      return a.peers < b.peers;
    } else if (columnHeader == "size") {
      return a.size < b.size;
    } else if (columnHeader == "date") {
      return a.date < b.date;
    } else if (columnHeader == "link") {
      return a.link < b.link;
    }
    return false;
  };
  // Sort the results using the comparison function
  std::sort(results.begin(), results.end(), compare);
}

std::vector<SearchResult> getNextPageResults(const std::vector<SearchResult>& results, size_t currentPage) {
  const size_t resultsPerPage = 10; // Define the number of results per page
  size_t startIndex = currentPage * resultsPerPage;
  size_t endIndex = std::min(startIndex + resultsPerPage, results.size());
  return std::vector<SearchResult>(results.begin() + startIndex, results.begin() + endIndex);
}

