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

void startTorrentSearch(std::string searchTerm);
void sendTorrentQueries(std::string searchTerm);
void sortSearchResults(std::string columnHeader, bool ascending);
void displayNextPage();

void sendTorrentQueries(std::string searchTerm) {
     int currentPage = getCurrentPage();
     currentPage++;
     sendTorrentQueries(searchTerm);
}

void sortSearchResults(std::string columnHeader, bool ascending) {
     int currentPage = getCurrentPage();
     currentPage++;
     sendTorrentQueries(searchTerm);
}

void displayNextPage() {
     int currentPage = getCurrentPage();
     std::string searchTerm = getSearchTerm();
     currentPage++;
     sendTorrentQueries(searchTerm);
}

