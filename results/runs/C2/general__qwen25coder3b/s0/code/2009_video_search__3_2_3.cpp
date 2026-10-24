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
void displayResults(const std::vector<VideoResult>& results);
void sortResults(std::vector<VideoResult>& results, SortOrder order);
void navigateResults(int currentPage, int totalPages);

struct VideoResult { std::string videoName; std::string length; std::string datePosted; std::string link; }; std::vector<VideoResult> searchVideos(const std::string& query, bool includeHosts, bool includeLinks) { updateDatabase(); std::vector<VideoResult> results; // Perform search logic here return results; }

void displayResults(const std::vector<VideoResult>& results) { std::cout << "Video Name - Length - Date Posted - Link" << std::endl; for (const auto& result : results) { std::cout << result.videoName << " - " << result.length << " - " << result.datePosted << " - " << result.link << std::endl; } }

void sortResults(std::vector<VideoResult>& results, SortOrder order) { std::sort(results.begin(), results.end(), [order](const VideoResult& a, const VideoResult& b) { switch (order) { case SortOrder::Length: return a.length < b.length; case SortOrder::Date: return a.datePosted < b.datePosted; case SortOrder::Alphabetical: return a.videoName < b.videoName; } }); }

void navigateResults(int currentPage, int totalPages) { if (currentPage == 1) { std::cout << "There are no previous pages." << std::endl; } else if (currentPage > 1) { std::cout << "There is a previous page." << std::endl; } if (currentPage == totalPages) { std::cout << "There are no next pages." << std::endl; } else if (currentPage < totalPages) { std::cout << "There is a next page." << std::endl; } }

