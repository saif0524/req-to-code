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

void displayMainScreen(const std::vector<std::string>& videos);
void handleUserInput(std::vector<std::string>& videos);
void updateVideoList(const std::vector<std::string>& videos);
std::vector<std::string> searchVideos(const std::string& query);
bool validateInput(const std::string& input);

void displayMainScreen(const std::vector<std::string>& videos) {
  for (const auto& video : videos) {
    std::cout << video << std::endl;
  }
}

void handleUserInput(std::vector<std::string>& videos) {
  std::string query;
  std::cout << "Enter search query: " << std::endl;
  std::cin >> query;
  if (validateInput(query)) {
    std::vector<std::string> results = searchVideos(query);
    updateVideoList(results);
  } else {
    std::cout << "Invalid input. Please try again." << std::endl;
  }
}

void updateVideoList(const std::vector<std::string>& videos) {
  std::vector<std::string> updatedVideos = videos;
  displayMainScreen(updatedVideos);
}

std::vector<std::string> searchVideos(const std::vector<std::string>& query, const std::vector<std::string>& videos) {
  std::vector<std::string> results;
  for (const auto& video : videos) {
    if (video.find(query) != std::string::npos) {
      results.push_back(video);
    }
  }
  return results;
}

bool validateInput(const std::string& input) {
  return !input.empty();
}

