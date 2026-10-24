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

std::vector<Video> search(std::string query);
std::vector<Video> filter(std::vector<Video> videos, std::string filter);
std::vector<Video> sort(std::vector<Video> videos, std::string sort_by);
void download(Video video);
void play(Video video);

std::vector<Video> search(std::string query) { 
   std::vector<Video> result; 
   for (auto& video : videos) { 
     if (video.title.find(query) != std::string::npos || video.description.find(query) != std::string::npos) { 
       result.push_back(video); 
     } 
   } 
   return result; 
}

std::vector<Video> filter(std::vector<Video> videos, std::string filter) { 
    std::vector<Video> result; 
    for (auto& video : videos) { 
        if (video.title.find(filter) != std::string::npos || video.description.find(filter) != std::string::npos) { 
            result.push_back(video); 
        } 
    } 
    return result; 
}

template <typename T>
std::vector<Video> sort(std::vector<Video> videos, std::string sort_by, T compare) {
    if (sort_by == "title") {
        std::sort(videos.begin(), videos.end(), compare);
    } else if (sort_by == "date") {
        std::sort(videos.begin(), videos.end(), compare);
    }
    return videos;
}

std::string download(Video video) { 
   std::string url = video.url; 
   std::string filename = video.title + ".mp4"; 
   std::string command = "curl -o " + filename + " \

std::string play(Video video) { 
    std::string url = video.url; 
    std::string filename = video.title + "_downloaded.mp4"; 
    std::string command = "mpv " + url + " &"; 
    system(command.c_str()); 
    return filename; 
}

