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

std::vector<VideoResult> searchVideos(const std::string& query, const std::vector<std::string>& sites, const std::vector<std::string>& categories, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters);
std::vector<VideoResult> sortResults(const std::vector<VideoResult>& results, const std::string& sortBy, const std::string& sortOrder);
std::vector<VideoResult> filterResults(const std::vector<VideoResult>& results, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters);
void storeFavoriteVideos(const std::vector<VideoResult>& videos);
std::vector<VideoResult> loadFavoriteVideos();

struct VideoResult { std::string name; std::string size; std::string site; std::string content; }; struct VideoSearchEngine { static std::vector<VideoResult> favoriteVideos; static std::vector<VideoResult> search(const std::string& query, const std::vector<std::string>& sites, const std::vector<std::string>& categories, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters) { // Implementation goes here } };

template<typename T>
std::vector<T> sortResults(const std::vector<T>& results, const std::string& sortBy, const std::string& sortOrder) {
  std::vector<T> sortedResults = results;
  if (sortBy == "name") {
    if (sortOrder == "asc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.name < b.name; });
    } else if (sortOrder == "desc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.name > b.name; });
    }
  } else if (sortBy == "size") {
    if (sortOrder == "asc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.size < b.size; });
    } else if (sortOrder == "desc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.size > b.size; });
    }
  } else if (sortBy == "site") {
    if (sortOrder == "asc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.site < b.site; });
    } else if (sortOrder == "desc") {
      std::sort(sortedResults.begin(), sortedResults.end(), [](const T& a, const T& b) { return a.site > b.site; });
    }
  }
  return sortedResults;
}

template<typename T>
std::vector<T> filterResults(const std::vector<T>& results, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters) {
  std::vector<T> filteredResults;
  for (const auto& result : results) {
    bool meetsContentFilter = true;
    bool meetsWebsiteFilter = true;
    for (const auto& filter : contentFilters) {
      if (result.content.find(filter) == std::string::npos) {
        meetsContentFilter = false;
        break;
      }
    }
    for (const auto& filter : websiteFilters) {
      if (result.site.find(filter) == std::string::npos) {
        meetsWebsiteFilter = false;
        break;
      }
    }
    if (meetsContentFilter && meetsWebsiteFilter) {
      filteredResults.push_back(result);
    }
  }
  return filteredResults;
}

void storeFavoriteVideos(const std::vector<VideoResult>& videos) { VideoSearchEngine::favoriteVideos = videos; }

std::vector<VideoResult> loadFavoriteVideos() { return VideoSearchEngine::favoriteVideos; }

