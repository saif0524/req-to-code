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
void updateVideoList(const std::vector<std::string>& newVideos);
std::vector<std::string> searchVideos(const std::string& query);
void displaySearchResults(const std::vector<std::string>& results);

void displayMainScreen(const std::vector<std::string>& videos) {
  for (const auto& video : videos) {
    std::cout << video << std::endl;
  }
}

void handleUserInput(std::vector<std::string>& videos) {
  std::string input;
  while (true) {
    std::cout << "Enter a command (search, select, exit): " << std::endl;
    std::cin >> input;
    if (input == "search") {
      std::string query;
      std::cout << "Enter search query: " << std::endl;
      std::cin >> query;
      std::vector<std::string> results = searchVideos(query);
      updateVideoList(results);
    } else if (input == "select") {
      std::cout << "Enter video index to select: " << std::endl;
      int index;
      std::cin >> index;
      if (index >= 0 && index < videos.size()) {
        std::cout << "Selected video: " << videos[index] << std::endl;
      } else {
        std::cout << "Invalid index" << std::endl;
      }
    } else if (input == "exit") {
      break;
    } else {
      std::cout << "Invalid command" << std::endl;
    }
  }
}

void updateVideoList(const std::vector<std::string>& newVideos) {
  videos.clear();
  for (const auto& video : newVideos) {
    videos.push_back(video);
  }
}

std::vector<std::string> searchVideos(const std::string& query) {
  std::vector<std::string> results;
  for (const auto& video : videos) {
    if (std::find_if(video.begin(), video.end(), [&query](char c) {
      return c == query[0];
    }) != video.end()) {
      results.push_back(video);
    }
  }
  return results;
}

void displaySearchResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

