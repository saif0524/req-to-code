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

vector.h, torrent.h, algorithm.h

vector<torrent> get torrentWithoutZeroSeeds(const vector<torrent>& input);
void sort_rapidly(const vector<T>& input);
vector<torrent> skip torrentWithLowRating(const vector<torrent>& input, double threshold);

vector<torrent> get torrentWithoutZeroSeeds(const vector<torrent>& input) {
  vector<torrent> result;
  for (const auto& torrent : input) {
    if (Torrent.seed != 0) {
      result.push_back(Torrent);
    }
  }
  return result;
}

vector<torrent> sort_rapidly(const vector<torrent>& input) {
  sort(input.begin(), input.end());
  return input;
  }

vector<torrent> skip torrentWithLowRating(const vector<torrent>& input, double threshold) {
  vector<torrent> result;
  for (const auto& torrent : input) {
    if (Torrent.rating >= threshold) {
      result.push_back(Torrent);
    }
  }
  return result;
  }

