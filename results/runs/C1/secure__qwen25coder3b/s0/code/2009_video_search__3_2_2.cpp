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

std::vector<VideoResult> queryVideoHosts(const std::string& searchTerm);
std::vector<VideoResult> queryVideoLinks(const std::string& searchTerm);
std::vector<VideoResult> sortResults(const std::vector<VideoResult>& results, const std::string& columnHeader);
std::vector<VideoResult> filterResults(const std::vector<VideoResult>& results, const std::vector<std::string>& selectedWebsites);
void displayResults(const std::vector<VideoResult>& results);

struct VideoResult { std::string website; std::string videoName; int length; std::string date; }; std::vector<VideoResult> queryVideoHosts(const std::string& searchTerm) { if (searchTerm.empty()) { return {}; } // Simulate querying video hosting sites std::vector<VideoResult> results = { {"YouTube", "Video Name", 120, "2023-10-01"}, {"Vimeo", "Another Video", 90, "2023-09-15"} }; return results; }

template<typename T>
std::vector<T> queryVideoLinks(const std::string& searchTerm) {
  if (searchTerm.empty()) {
    return {};
  }
  // Simulate querying video link sites
  std::vector<T> results = {
    {"YouTube", "Video Name", 120, "2023-10-01"},
    {"Vimeo", "Another Video", 90, "2023-09-15"}
  };
  return results;
}

template<typename T>
std::vector<T> sortResults(const std::vector<T>& results, const std::string& columnHeader) {
  if (results.empty()) {
    return results;
  }

  std::sort(results.begin(), results.end(), [&columnHeader](const T& a, const T& b) {
    if (columnHeader == "Date") {
      // Convert date strings to a comparable format
      std::istringstream dateA(a.date), dateB(b.date);
      std::tm tmA, tmB;
      dateA >> std::get_time(&tmA, "%Y-%m-%d");
      dateB >> std::get_time(&tmB, "%Y-%m-%d");
      return std::mktime(&tmA) < std::mktime(&tmB);
    } else {
      return a[columnHeader] < b[columnHeader];
    }
  });

  return results;
}

template<typename T, typename U>
std::vector<T> filterResults(const std::vector<T>& results, const std::vector<U>& selectedWebsites) {
  if (results.empty()) {
    return results;
  }

  std::vector<T> filteredResults;
  for (const auto& result : results) {
    if (std::find(selectedWebsites.begin(), selectedWebsites.end(), result.website) != selectedWebsites.end()) {
      filteredResults.push_back(result);
    }
  }

  return filteredResults;
}

template<typename T>
void displayResults(const std::vector<T>& results) {
  for (const auto& result : results) {
    std::cout << "Website: " << result.website << std::endl;
    std::cout << "Video Name: " << result.videoName << std::endl;
    std::cout << "Length: " << result.length << " seconds" << std::endl;
    std::cout << "Date Posted: " << result.date << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
}

