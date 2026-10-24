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

double calculateServerResponseTime(const std::string& serverAddress, int requestCount, int duration);
bool compareResponseTimes(double currentResponseTime, double expectedResponseTime);
void checkServerPerformance(const std::string& serverAddress, int requestCount, int duration);

double calculateServerResponseTime(const std::string& serverAddress, int requestCount, int duration) {
  using namespace std::chrono;
  double totalResponseTime = 0.0;
  for (int i = 0; i < requestCount; ++i) {
    auto start = high_resolution_clock::now();
    std::this_thread::sleep_for(milliseconds(duration));
    auto end = high_resolution_clock::now();
    totalResponseTime += duration_cast<milliseconds>(end - start).count();
  }
  return totalResponseTime / requestCount;
}

bool compareResponseTimes(double currentResponseTime, double expectedResponseTime) { return currentResponseTime <= expectedResponseTime; }

void checkServerPerformance(const std::string& serverAddress, int requestCount, int duration, double expectedResponseTime) {
  double averageResponseTime = calculateServerResponseTime(serverAddress, requestCount, duration);
  bool meetsRequirement = compareResponseTimes(averageResponseTime, expectedResponseTime);
  // Additional logic to handle the result, e.g., log or notify
}

