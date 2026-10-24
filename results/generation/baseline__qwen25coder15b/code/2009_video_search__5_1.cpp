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

void searchVideo(const std::string& query);
void displayResults(const std::vector<VideoResult>& results);
void sortResults(std::vector<VideoResult>& results);

void searchVideo(const std::string& query) {
  VideoResultVector results = VideoSearchEngine::searchVideo(query);
  displayResults(results);
}

void displayResults(const std::vector<VideoResult>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

void sortResults(std::vector<VideoResult>& results) {
  std::sort(results.begin(), results.end(), [](const VideoResult& a, const VideoResult& b) {
    // Implement the sorting criteria here
    return a.rating > b.rating; // Example: sort by rating in descending order
  });
}

