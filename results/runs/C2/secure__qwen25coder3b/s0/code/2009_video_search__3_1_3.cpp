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

void updateTorrentDatabase();
std::vector<TorrentResult> searchTorrents(const std::string& query, bool includeTorrents);
std::string formatTorrentResult(const TorrentResult& result);
void displaySearchResults(const std::vector<TorrentResult>& results);
std::vector<TorrentResult> sortTorrentResults(const std::vector<TorrentResult>& results, TorrentSortOrder order);

void updateTorrentDatabase() {
  std::vector<TorrentSite> sites = fetchTorrentSitesFromInternet();
  storeTorrentSitesInDatabase(sites);
  std::lock_guard<std::mutex> lock(mutex);
  if (fetchTorrentSitesFromInternet() == nullptr) {
    reason = "Failed to fetch torrent sites from internet";
    return;
  }
  cacheTorrentDatabase();
}

void searchTorrents(const std::string& query, bool includeTorrents) {
  // Step 1: Validate the input query
  if (query.empty()) {
    reason = "Invalid query: query is empty";
    return {};
  }

  // Step 2: Check if the includeTorrents flag is valid
  if (!includeTorrents) {
    reason = "Invalid flag: includeTorrents is false";
    return {};
  }

  // Step 3: Fetch the latest torrent database if it is out of date
  if (isTorrentDatabaseOutdated()) {
    updateTorrentDatabase();
  }

  // Step 4: Perform the search using the query and includeTorrents flag
  std::vector<TorrentResult> results = performSearch(query, includeTorrents);

  // Step 5: Handle any errors that occur during the search process
  if (results.empty()) {
    reason = "No results found for this search";
    return {};
  }

  // Step 6: Return the search results
  return results;
}

struct TorrentResult { int seedCount; int peerCount; int fileSize; std::string datePosted; std::string link; }; std::string formatTorrentResult(const TorrentResult& result) { std::string formattedResult; std::string seedCount = std::to_string(result.seedCount); std::string peerCount = std::to_string(result.peerCount); std::string fileSize = std::to_string(result.fileSize); std::string datePosted = result.datePosted; std::string link = result.link; formattedResult += "Seed Count: " + seedCount + "\n"; formattedResult += "Peer Count: " + peerCount + "\n"; formattedResult += "File Size: " + fileSize + "\n"; formattedResult += "Date Posted: " + datePosted + "\n"; formattedResult += "Link: " + link + "\n"; if (seedCount.empty()) { formattedResult += "Seed Count: N/A\n"; } if (peerCount.empty()) { formattedResult += "Peer Count: N/A\n"; } if (fileSize.empty()) { formattedResult += "File Size: N/A\n"; } if (datePosted.empty()) { formattedResult += "Date Posted: N/A\n"; } if (link.empty()) { formattedResult += "Link: N/A\n"; } return formattedResult; }

void displaySearchResults(const std::vector<TorrentResult>& results) { if (results.empty()) { std::cout << "No results were found for this search." << std::endl; return; } for (const auto& result : results) { std::string formattedResult = formatTorrentResult(result); std::cout << formattedResult << std::endl; } }

enum class TorrentSortOrder { Size, Date, Alphabetical }; struct TorrentResult { int seedCount; int peerCount; int fileSize; std::string datePosted; std::string link; }; std::vector<TorrentResult> sortTorrentResults(const std::vector<TorrentResult>& results, TorrentSortOrder order) { auto comparator = [](const TorrentResult& a, const TorrentResult& b) { switch (order) { case TorrentSortOrder::Size: return a.fileSize < b.fileSize; case TorrentSortOrder::Date: return a.datePosted < b.datePosted; case TorrentSortOrder::Alphabetical: return a.title < b.title; default: return false; } }; std::sort(results.begin(), results.end(), comparator); return results; }

