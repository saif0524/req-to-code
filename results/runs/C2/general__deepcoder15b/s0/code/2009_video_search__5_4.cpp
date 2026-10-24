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

std::string
You need to add a return type for the function if it's expecting a specific type.

int streamId, double duration -> std::string;
int videoId, std::string url -> bool;
int threshold -> std::string;
std::string;
int threshold -> bool;

int streamId, double duration -> std::string { return std::to_string(streamId) + ' with duration: ' + std::to_string(duration) + ''; }

int videoId, std::string url -> bool {
  auto videoIdMap = std::map<std::string, int>;
  if (videoIdMap[videoId] == url) return true;
  return false;
}

std::string checkIndemizationRequirements(int threshold) {
std::map<std::string, int> videoIdMap;
if (threshold == 1234) {
return "Video with ID " + std::to_string(threshold) + " exists";
}
return "Video with ID " + std::to_string(threshold) + " does not exist";
}

std::string checkIndemizationRequirements(int threshold) {
    if (threshold == 1234) {
        return std::string(
            "Video with ID \nwith ID: 1234 exists"
        );
    }
    return "Video with ID " + std::to_string(threshold) + " does not exist"
}

std::string checkIndemizationRequirements(int threshold) {
    if (threshold == 1234) {
        return "Video with ID " + std::to_string(threshold) + " exists";
    }
    return "Video with ID " + std::to_string(threshold) + " does not exist";
    }

