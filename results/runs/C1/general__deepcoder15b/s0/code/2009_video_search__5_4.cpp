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

int streamId, double duration -> std::string;
int videoId, std::string url -> bool;
int threshold -> std::string;
std::string;
int threshold -> bool;

int streamId, double duration -> std::string {
    return std::to_string(streamId) + " with duration: " + std::to_string(duration) + 
    "";
    }

int videoId, std::string url -> bool {
  std::map<int, std::string> videoIdMap;
  videoIdMap[videoId] = url;
  return videoIdMap.find(url) != videoIdMap.end();
}

int threshold -> std::string {
  auto it = videoIdMap.find(threshold);
  if (it != videoIdMap.end()){
    return "Video with ID " + std::to_string(threshold) + " exists";
  } else {
    return "Video with ID " + std::to_string(threshold) + " does not exist";
  }
  }

std::string checkIndemizationRequirements(int threshold) {
    std::map<std::string, int> videoIdMap;
    if (threshold == 1234) {
      return std::string(

bool exchangeData(int threshold) {
    auto it = videoIdMap.find(threshold);
    return it != videoIdMap.end();
    }

