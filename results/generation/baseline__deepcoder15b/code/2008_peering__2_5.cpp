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

std::vector<std::pair<int, int>> balance_requests(std::vector<std::pair<int, int>> &requests, int numCDNs);
std::vector<std::pair<int, int>> aggregate_data(const std::vector<std::vector<std::pair<int, int>> > &data);
std::vector<std::pair<int, int>> handle_parameters(std::vector<std::pair<int, int>> &parameters);

std::vector<std::pair<int, int>> balance_requests(std::vector<std::pair<int, int>> &requests, int numCDNs) {
  std::vector<int> target(numCDNs, 0);
  // Calculate total load for each CDN
  for (auto &request : requests) {
    int load = request.first;
    target[find_index(request, load)] += load;
  }
  // Calculate target per CDN
  for (int i = 0; i < numCDNs; i++) {
    target[i] = target[i] / numCDNs;
  }
  // Assign each request to the closest target
  std::vector<std::pair<int, int>> result;
  for (auto &request : requests) {
    int load = request.first;
    int best_match = -1;
    int min_diff = std::numeric_limits<int>::max();
    for (int i = 0; i < numCDNs; i++) {
      int current_target = target[i];
      int diff = abs(load - current_target);
      if (diff < min_diff) {
        min_diff = diff;
        best_match = i;
      }
    }
    result.push_back({request, best_match});
  }
  return result;
}

vector<pair<int, int>> aggregate_data(vector<vector<pair<int, int>>> &data) {
  vector<pair<int, int>> result;
  for (auto &inner_data : data) {
    for (auto &pair : inner_data) {
      result.push_back({pair.first, pair.second});
    }
  }
  return result;
  }
  

std::vector<std::pair<int, int>> handle_parameters(std::vector<std::pair<int, int>> &parameters) {
  std::vector<std::pair<int, int>> new_parameters;
  for (size_t i = 0; i < parameters.size(); ++i) {
    // Calculate the average load across all CDNs
    int total_load = 0;
    for (const auto& p : parameters) {
      total_load += p.back().first;
    }
    double average_load = static_cast<double>(total_load) / parameters.size();

    // Update expected delay based on average load
    if (average_load > 100) {
      new_parameters.push_back({average_load + (average_load - 100), parameters[i].back().second});
    } else {
      new_parameters.push_back({parameters[i].back().second - (100 - average_load), parameters[i].back().second});
    }
  }
  return new_parameters;
  }
  

