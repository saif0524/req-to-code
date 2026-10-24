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

using namespace display;

void download_video(const std::string& video_url);
void display_video(const std::string& video_url);
void review_video(const std::string& video_url);

void download_video(const std::string& video_url) {
  // Use the download_video function from the download module to perform the download
  download::download_video(video_url);
}

void display_video(const std::string& video_url) {
  // Use the display_video function from the display module to open the video URL
  display::display_video(video_url);
}

void review_video(const std::string& video_url) {  // Use the display_video function from the display module to open the video URL
  display::display_video(video_url); }

