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

struct TorrentResult { int seeds; double rating; }; std::vector<TorrentResult> filterTorrentResults(const std::vector<TorrentResult>& results) { auto is_valid = [](const TorrentResult& result) { return result.seeds > 0 && result.rating >= 1; }; std::vector<TorrentResult> filtered_results; std::copy_if(results.begin(), results.end(), std::back_inserter(filtered_results), is_valid); return filtered_results; }

template<typename T, typename Comparator>
std::vector<T> sortResults(const std::vector<T>& results, Comparator comp) {
  std::stable_sort(results.begin(), results.end(), comp);
  return results;
}

