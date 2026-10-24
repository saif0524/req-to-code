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

void updateDatabase();
void streamSearch();
void includeVideoHostSearch(bool include);
void includeVideoLinkSearch(bool include);
std::vector<VideoHost> searchVideoHosts(std::string query);

void updateDatabase() {
  // Retrieve video hosting and video link sites from the database
  std::vector<VideoHost> videoHosts = retrieveVideoHosts();

  // Store the video hosting and video link sites in the database
  storeVideoHosts(videoHosts);
}

bool includeVideoHostSearch(bool include) {
   // Retrieve video hosting and video link sites from the database
   std::vector<VideoHost> videoHosts = retrieveVideoHosts();

   // Store the video hosting and video link sites in the database
   storeVideoHosts(videoHosts);
}

void includeVideoLinkSearch(bool include) {
    // Retrieve video hosting and video link sites from the database
    std::vector<VideoHost> videoHosts = retrieveVideoHosts();

    // Store the video hosting and video link sites in the database
    storeVideoHosts(videoHosts);
}

std::vector<VideoHost> searchVideoHosts(std::string query) {
   // Retrieve video hosting and video link sites from the database
   std::vector<VideoHost> videoHosts = retrieveVideoHosts();

   // Filter the video hosting and video link sites based on the user's search query
   std::vector<VideoHost> filteredHosts = filterHosts(videoHosts, query);

   // Store the filtered video hosting and video link sites in the database
   storeVideoHosts(filteredHosts);

   // Return the filtered video hosting and video link sites
   return filteredHosts;
}

