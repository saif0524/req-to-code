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

int streamId, double duration -> std::string {
    return std::to_string(streamId) + " with duration: " + std::to_string(duration) + 
    "";
    }

bool checkVideoId(int videoId, std::string url) {
    std::map<int, std::string> videoIdMap;
    videoIdMap[videoId] = url;
    return videoIdMap.find(url) != videoIdMap.end();
    }

int threshold(int numVideoIds, std::map<int, std::string> videoIdMap, int minThresholdPercentage) {
    std::string reasoning = 
    "To determine the threshold for video IDs, we first collect all video IDs that match a specific pattern. This is done by iterating through the videoIdMap and counting how many video IDs meet the criteria. The threshold is then calculated as a percentage of the total video IDs, ensuring that it reflects the desired coverage. For example, if 90% of the video IDs match the pattern, the threshold would be set to 90. This ensures that only relevant video streams are processed, maintaining system efficiency and relevance.\n};\n

The function `checkIndemnification` calls the `threshold` function to determine if the software meets indemnification requirements. It returns a string with a reasoning explaining how the threshold is calculated.

