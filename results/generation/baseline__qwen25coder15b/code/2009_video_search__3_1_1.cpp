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

void addTorrentWebsite(const std::string& url);
std::vector<std::string> searchTorrents(const std::string& searchTerm);
void displaySearchResults(const std::vector<std::string>& results);
void updateTorrentDatabase(const std::vector<std::string>& newWebsites);

void Database::addTorrentWebsite(const std::string& url) {
  if (isValidTorrentWebsite(url)) {
    websites.push_back(url);
    return;
  }
  return;
}

std::vector<std::string> searchTorrents(const std::string& searchTerm) {
  std::vector<std::string> results;
  for (const auto& website : websites) {
    if (website.find(searchTerm) != std::string::npos) {
      results.push_back(website);
    }
  }
  return results;
}

void displaySearchResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    // Construct a string for each result
    std::string link = "http://" + result;\n// Display the link in the tab on the main window\n// (This is a placeholder for the actual implementation)\n}
}

void updateTorrentDatabase(const std::vector<std::string>& newWebsites) {
  for (const auto& website : newWebsites) {
    addTorrentWebsite(website);
  }
}

