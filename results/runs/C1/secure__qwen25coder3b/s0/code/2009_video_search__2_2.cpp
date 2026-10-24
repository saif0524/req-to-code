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
std::vector<VideoResult> sortVideos(const std::vector<VideoResult>& results, const std::string& sortBy, const std::string& sortOrder);
std::vector<VideoResult> filterVideos(const std::vector<VideoResult>& results, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters);
void storeFavoriteVideos(const std::vector<VideoResult>& videos);
std::vector<VideoResult> loadFavoriteVideos();

struct VideoResult { std::string title; std::string site; std::string size; std::string content; }; std::vector<VideoResult> searchVideos(const std::string& query, const std::vector<std::string>& sites, const std::vector<std::string>& categories, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters) { std::vector<VideoResult> results; if (query.empty() || sites.empty() || categories.empty() || contentFilters.empty() || websiteFilters.empty()) { return results; } // Search logic results.push_back({"title": "Video Title", "site": "YouTube", "size": "1GB", "content": "Adult"}); return results; }

std::vector<VideoResult> sortVideos(const std::vector<VideoResult>& results, const std::string& sortBy, const std::string& sortOrder) { std::vector<VideoResult> sortedResults = results; if (sortBy.empty() || sortOrder.empty()) { return sortedResults; } switch (sortBy) { case "name": if (sortOrder == "asc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.title < b.title; }); } else if (sortOrder == "desc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.title > b.title; }); } break; case "size": if (sortOrder == "asc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.size < b.size; }); } else if (sortOrder == "desc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.size > b.size; }); } break; case "site": if (sortOrder == "asc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.site < b.site; }); } else if (sortOrder == "desc") { std::sort(sortedResults.begin(), sortedResults.end(), [](const VideoResult& a, const VideoResult& b) { return a.site > b.site; }); } break; default: break; } return sortedResults; }

template<typename T>
std::vector<T> filterVideos(const std::vector<T>& results, const std::vector<std::string>& contentFilters, const std::vector<std::string>& websiteFilters) {
  std::vector<T> filteredResults;

  // Validate inputs
  if (contentFilters.empty() || websiteFilters.empty()) {
    return filteredResults;
  }

  // Filter logic
  for (const auto& result : results) {
    bool contentMatch = false;
    bool siteMatch = false;

    for (const auto& filter : contentFilters) {
      if (result.content == filter) {
        contentMatch = true;
        break;
      }
    }

    for (const auto& filter : websiteFilters) {
      if (result.site == filter) {
        siteMatch = true;
        break;
      }
    }

    if (contentMatch && siteMatch) {
      filteredResults.push_back(result);
    }
  }

  return filteredResults;
}

void storeFavoriteVideos(const std::vector<VideoResult>& videos) { std::string filePath = "favorite_videos.txt"; std::ofstream file(filePath, std::ios::app); if (!file.is_open()) { std::cerr << "Error opening file: " << filePath << std::endl; return; } for (const auto& result : videos) { file << result.title << "," << result.site << "," << result.size << "," << result.content << std::endl; } file.close(); }

std::vector<VideoResult> loadFavoriteVideos() { std::vector<VideoResult> favoriteVideos; std::string filePath = "favorite_videos.txt"; std::ifstream file(filePath); if (!file.is_open()) { std::cerr << "Error opening file: " << filePath << std::endl; return favoriteVideos; } std::string line; while (std::getline(file, line)) { std::istringstream iss(line); std::string title, site, size, content; if (iss >> title >> site >> size >> content) { favoriteVideos.push_back({title, site, size, content}); } } file.close(); return favoriteVideos; }

