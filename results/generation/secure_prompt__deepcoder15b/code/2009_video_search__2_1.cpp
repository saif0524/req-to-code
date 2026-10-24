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

// Define the database instance and map here

std::string getVideoPath(std::string searchQuery, std::map<std::string, std::vector<std::string>>& videoPaths);
std::map<std::string, std::vector<std::string>> searchVideos(std::vector<std::string> searchQueries, std::map<std::string, std::vector<std::string>>& videoPaths);
std::string loadVideoPath(std::map<std::string, std::vector<std::string>>& videoPaths, std::string searchQuery);
std::map<std::string, std::vector<std::string>> searchQuery(std::string searchQuery, std::map<std::string, std::vector<std::string>>& videoPaths);

std::string getVideoPath(std::string searchQuery, std::map<std::string, std::vector<std::string>>& videoPaths) {
  auto it = videoPaths.find(searchQuery);
  if (it != videoPaths.end()) {
    return it->second[0];
  }
  return;
  }

std::map<std::string, std::vector<std::string>> searchVideos(std::vector<std::string> searchQueries, std::map<std::string, std::vector<std::string>>& videoPaths) {
  std::map<std::string, std::vector<std::string>> result;
  for (const auto& query : searchQueries) {
    result[query] = std::vector<std::string>();
  }
  for (const auto& videoPath : videoPaths) {
    if (videoPath.find(query) != std::string::npos) {
      result[query].push_back(videoPath);
    }
    videoPaths.erase(videoPath);
  }
  return result;
  }

std::string loadVideoPath(std::map<std::string, std::vector<std::string>>& videoPaths, std::string searchQuery) {
  for (const auto& entry : videoPaths) {
    const std::string& videoPath = entry.second;
    if (videoPath.find(searchQuery) != std::string::npos) {
      return videoPath;
    }
  }
  return;
  }
  

std::map<std::string, std::vector<std::string>> searchQuery(std::string searchQuery, std::map<std::string, std::vector<std::string>>& videoPaths) {
  std::map<std::string, std::vector<std::string>> result;
  for (const auto& entry : videoPaths) {
    if (entry.second.find(searchQuery) != std::string::npos) {
      result[entry.first].push_back(entry.second);
    }
  }
  return result;
  }

