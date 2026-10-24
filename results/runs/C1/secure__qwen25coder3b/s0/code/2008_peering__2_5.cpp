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

double calculateCost(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation);
double calculateLoad(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation);
double calculateResponseTime(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation);
vector<string> selectPeers(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation);
void redirectRequests(vector<string> peers, vector<string> requests);

double calculateCost(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  return webServerResponsiveness * expectedNetworkDelay + geographicLocation;
}

double calculateLoad(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  return webServerResponsiveness * expectedNetworkDelay + geographicLocation;
}

double calculateResponseTime(double webServerResponsiveness, double expectedNetworkDelay) { return webServerResponsiveness + expectedNetworkDelay; }

vector<string> selectPeers(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  vector<string> peers;
  double score;
  double threshold = 100.0; // Example threshold
  for (auto& peer : peerList) {
    score = calculateCost(webServerResponsiveness, expectedNetworkDelay, geographicLocation);
    if (score < threshold) {
      peers.push_back(peer);
    }
  }
  return peers;
}

void redirectRequests(vector<string> peers, vector<string> requests) {
  for (auto& request : requests) {
    double webServerResponsiveness = getWebServerResponsiveness(request);
    double expectedNetworkDelay = getExpectedNetworkDelay(request);
    double geographicLocation = getGeographicLocation(request);
    double cost = calculateCost(webServerResponsiveness, expectedNetworkDelay, geographicLocation);
    string selectedPeer = selectPeers(webServerResponsiveness, expectedNetworkDelay, geographicLocation);
    peers.push_back(selectedPeer);
  }
}

