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

UserSearch(User user, std::string query);
DeveloperSearch(Developer developer, std::string query);
UserFilter(User user, std::string filter);
DeveloperFilter(Developer developer, std::string filter);
UserSort(User user, std::string sort);

std::vector<Video> UserSearch(User user, std::string query) { 
    std::vector<Video> results; 
    for (Video video : user.getVideoDatabase()) { 
        if (video.matches(query)) { 
            results.push_back(video); 
        } 
    } 
    return results; 
}

std::vector<Video> DeveloperSearch(Developer developer, std::string query) { 
    std::vector<Video> results; 
    for (Video video : developer.getVideoDatabase()) { 
        if (video.matches(query)) { 
            results.push_back(video); 
        } 
    } 
    return results; 
}

template <typename T>
std::vector<Video> UserFilter(User user, T filter) {
    std::vector<Video> results;
    for (Video video : user.getVideoDatabase()) {
        if (video.matches(filter)) {
            results.push_back(video);
        }
    }
    return results;
}

std::vector<Video> DeveloperFilter(Developer developer, std::string filter) { 
     std::vector<Video> results; 
     for (Video video : developer.getVideoDatabase()) { 
         if (video.matches(filter)) { 
             results.push_back(video); 
         } 
     } 
     return results; 
 }

std::vector<Video> UserSort(User user, std::string sort) { 
     std::vector<Video> sortedVideos = user.getVideoDatabase(); 
     if (sort == "title") { 
         std::sort(sortedVideos.begin(), sortedVideos.end(), [](Video a, Video b) { 
             return a.getTitle() < b.getTitle(); 
         }); 
     } else if (sort == "length") { 
         std::sort(sortedVideos.begin(), sortedVideos.end(), [](Video a, Video b) { 
             return a.getLength() < b.getLength(); 
         }); 
     } else if (sort == "upload_date") { 
         std::sort(sortedVideos.begin(), sortedVideos.end(), [](Video a, Video b) { 
             return a.getUploadDate() < b.getUploadDate(); 
         }); 
     } 
     return sortedVideos; 
 }

