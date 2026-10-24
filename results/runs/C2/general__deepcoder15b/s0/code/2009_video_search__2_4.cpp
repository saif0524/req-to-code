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

{ std::video }

std::video_stream::read;
std::video::process;
std::vector<std::struct>> search;
std::vector<std::struct>> display;
std::vector<std::struct>> handle;

struct std::video_stream::read {
  std::vector<std::pair<std::int64_t, std::uint8_t>> read(const std::video_stream& stream) const {
    if (std::is_file(stream)) {
      std::ifstream file(stream);
      if (!file) return std::vector<std::pair<std::int64_t, std::uint8_t>>{};
      std::vector<std::pair<std::int64_t, std::uint8_t>> data;
      file.read(data.end(), data.begin(), std::numeric_limits<std::int64_t>::max());
      return data;
    } else {
      std::video_stream& v = stream;
      std::vector<std::pair<std::int64_t, std::uint8_t>> result;
      v.read(v.data.end(), v.data.begin());
      return result;
    }
  }
}

std::vector<std::pair<std::int64_t, std::uint8_t>> process(std::vector<std::pair<std::int64_t, std::uint8_t>> video) {
  std::vector<std::pair<std::int64_t, std::uint8_t>> result;
  for (size_t i = 0; i < video.size(); i += 2) {
    size_t width = video[i].first;
    size_t height = video[i].second;
    std::vector<std::pair<std::int64_t, std::uint8_t>> pixels;
    for (size_t y = 0; y < height; y++) {
      size_t x = 0;
      if (y % 2 == 0 && y != 0) {
        x = width;
      } else {
        x = 0;
      }
      int r = (y % 2 == 0) ? 0 : 255;
      int g = (y % 2 == 1) ? 128 : 64;
      int b = (y % 2 == 0 && y != 0) ? 64 : 128;
      pixels.push_back({x, y, r, g, b});
      }
    }
    result.push_back(pixels);
  }
  return result;
  }

vector<std::video> search(vector<std::video> videos, vector<std::struct>> search_params) {
  vector<std::video> result;
  for (const auto& video : videos) {
    vector<std::struct>> metadata;
    for (auto& y : video) {
      metadata.push_back(y.second);
    }
    if (metadata == search_params) {
      result.push_back(video);
    }
  }
  return result;
  }
}:

vector<std::struct>> display(vector<std::struct>> search) {
  vector<json_object> result;
  for (auto& video : search) {
    result.emplace_back(
      "video_info",
      {"\ntitle: {0}\ngenre: {1}\nrelease_year: {2}
        reason: "Video details"
      }"\n);\nresult.emplace_back(\n"video_data",
      {"\ntitle: {0}\ngenre: {1}\nrelease_year: {2}
        reason: "Video search results"
      }"\n);\nresult.emplace_back(\n"video_details",
      {"\ntitle: {0}\ngenre: {1}\nrelease_year: {2}
        reason: "Video metadata"
      }"\n);\n}\nreturn json_encode(result);
}
}:

std::vector<std::video>> handle(std::vector<std::video>> videos \\ \\\\ { \\ \\ \quad std::vector<std::video>> result; \\ \\ \quad for (auto& video : videos) \\ \quad \quad \quad struct VideoInfo { \quad \quad \quad \quad int title; \quad \quad \quad \quad \quad int genre; \quad \quad \quad \quad \quad int release_year; \quad \quad \quad \quad \quad \quad std::string reason; \quad \quad \quad \quad \quad } videoInfo = process(video); \\ \quad \quad \quad \quad result.emplace_back(videoInfo); \\ \quad \quad \\ \quad \quad return result; \\ \quad } \\\\\\\}

