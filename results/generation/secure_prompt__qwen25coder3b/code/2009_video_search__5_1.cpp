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

bool validateQueryTime(double queryTime);
bool validateBrowserLinkTime(double linkTime);
bool validateLoadTime(double loadTime);
std::vector<TorrentResult> filterTorrentResults(const std::vector<TorrentResult>& results);
std::vector<Result> sortResults(const std::vector<Result>& results);

bool validateQueryTime(double queryTime) {
  return queryTime <= 5;
}

bool validateBrowserLinkTime(double linkTime) { return linkTime <= 1; }

bool validateLoadTime(double loadTime) { return loadTime <= 10; }

std::vector<TorrentResult> filterTorrentResults(const std::vector<TorrentResult>& results) {
  auto is_valid = [](const TorrentResult& result) {
    return result.seeds > 0 && result.rating >= 1;
  };

  std::remove_if(results.begin(), results.end(), is_valid);
  results.erase(results.begin(), std::remove_if(results.begin(), results.end(), is_valid));

  return results;
}

std::vector<Result> sortResults(const std::vector<Result>& results) {
  std::stable_sort(results.begin(), results.end());
  return results;
}

