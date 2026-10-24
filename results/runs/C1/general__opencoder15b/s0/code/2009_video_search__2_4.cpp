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

std::vector<Video> searchVideos(std::string query);
std::vector<Video> filterVideos(std::vector<Video> videos, std::string filter);
std::vector<Video> sortVideos(std::vector<Video> videos, std::string sort);
void downloadVideo(Video video);
void playVideo(Video video);

std::vector<Video> searchVideos(std::string query) const {
     std::vector<Video> result;
     for (Video video : videos) {
         if (video.title.find(query) != std::string::npos || video.description.find(query) != std::string::npos || std::any_of(video.tags.begin(), video.tags.end(), [&] (const std::string& tag) { return tag.find(query) != std::string::npos; })) {
             result.push_back(video);
         }
     }
     return result;
}

std::vector<Video> filterVideos(std::vector<Video> videos, std::string filter) {
     std::vector<Video> result;
     for (Video video : videos) {
         if (video.title.find(filter) != std::string::npos || video.description.find(filter) != std::string::npos || std::any_of(video.tags.begin(), video.tags.end(), [&] (const std::string& tag) { return tag.find(filter) != std::string::npos; })) {
             result.push_back(video);
         }
     }
     return result;
}

template <typename T>
std::vector<T> sortVideos(std::vector<T> videos, std::string sort) {
    if (sort == "title") {
        std::sort(videos.begin(), videos.end(), [] (const T& a, const T& b) { return a.title < b.title; });
    } else if (sort == "date") {
        std::sort(videos.begin(), videos.end(), [] (const T& a, const T& b) { return a.date < b.date; });
    }
    return videos;
}

void downloadVideo(Video video) {
     std::string url = video.url;
     std::string command = "wget " + url;
     system(command.c_str());
}

void playVideo(Video video) {
     std::string url = video.url;
     std::string command = "webbrowser" + url;
     system(command.c_str());
}

