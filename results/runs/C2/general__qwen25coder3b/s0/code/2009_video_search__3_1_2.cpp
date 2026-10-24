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

std::vector<SearchResult> queryTorrentWebsites(const std::string& searchTerm) { std::vector<SearchResult> results; // Mock database query logic // For demonstration, we will add a few results to the vector results.push_back({"example.com", 100, 200, "1GB", "2023-10-01", "http://example.com/torrent1"}); results.push_back({"example.org", 50, 150, "2GB", "2023-09-15", "http://example.org/torrent2"}); return results; }

void displaySearchResults(const std::vector<SearchResult>& results) {
  for (const auto& result : results) {
    std::cout << result.website << " - " << result.seeds << " seeds, " << result.peers << " peers, " << result.size << " - " << result.datePosted << " - " << result.link << std::endl;
  }
}

struct SearchResult { std::string website; int seeds; int peers; std::string size; std::string datePosted; std::string link; }; void sortSearchResults(std::vector<SearchResult>& results, const std::string& columnHeader) { std::sort(results.begin(), results.end(), [&columnHeader](const SearchResult& a, const SearchResult& b) { if (columnHeader == "website") { return a.website < b.website; } else if (columnHeader == "seeds") { return a.seeds < b.seeds; } else if (columnHeader == "peers") { return a.peers < b.peers; } else if (columnHeader == "size") { return a.size < b.size; } else if (columnHeader == "datePosted") { return a.datePosted < b.datePosted; } else if (columnHeader == "link") { return a.link < b.link; } return false; }); }

std::vector<SearchResult> getNextPageResults(const std::vector<SearchResult>& results, size_t currentPage) const { size_t resultsPerPage = 10; size_t startIndex = currentPage * resultsPerPage; size_t endIndex = std::min(startIndex + resultsPerPage, results.size()); return std::vector<SearchResult>(results.begin() + startIndex, results.begin() + endIndex); }

