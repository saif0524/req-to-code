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
vector<string> selectPeers(vector<CDNProvider> providers, double costThreshold, double loadThreshold, double responseTimeThreshold);
void redirectRequests(vector<WebServer> webServers, vector<CDNProvider> providers, vector<string> selectedPeers);

double calculateCost(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  // Define the cost model
  double responsivenessCost = webServerResponsiveness * 0.1;
  double delayCost = expectedNetworkDelay * 0.05;
  double locationCost = geographicLocation * 0.02;

  // Calculate the total cost
  double totalCost = responsivenessCost + delayCost + locationCost;

  return totalCost;
}

double calculateLoad(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  // Define load factors and their weights
  double responsivenessWeight = 0.4;
  double delayWeight = 0.3;
  double locationWeight = 0.3;

  // Calculate load based on weighted factors
  double responsivenessLoad = webServerResponsiveness * responsivenessWeight;
  double delayLoad = expectedNetworkDelay * delayWeight;
  double locationLoad = geographicLocation * locationWeight;

  // Calculate total load
  double totalLoad = responsivenessLoad + delayLoad + locationLoad;

  return totalLoad;
}

double calculateResponseTime(double webServerResponsiveness, double expectedNetworkDelay, double geographicLocation) {
  // Calculate response time as the sum of web server responsiveness and expected network delay
  double responseTime = webServerResponsiveness + expectedNetworkDelay;

  return responseTime;
}

vector<string> selectPeers(vector<CDNProvider> providers, double costThreshold, double loadThreshold, double responseTimeThreshold) {
  vector<string> selectedPeers;

  for (const auto& provider : providers) {
    double cost = calculateCost(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);
    double load = calculateLoad(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);
    double responseTime = calculateResponseTime(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);

    if (cost <= costThreshold && load <= loadThreshold && responseTime <= responseTimeThreshold) {
      selectedPeers.push_back(provider.name);
    }
  }

  return selectedPeers;
}

void redirectRequests(vector<WebServer> webServers, vector<CDNProvider> providers, vector<string> selectedPeers) {
  for (auto& webServer : webServers) {
    double minCost = numeric_limits<double>::max();
    double minLoad = numeric_limits<double>::max();
    double minResponseTime = numeric_limits<double>::max();
    string selectedProviderName;

    for (const auto& provider : providers) {
      if (selectedPeers.find(provider.name) != selectedPeers.end()) {
        double cost = calculateCost(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);
        double load = calculateLoad(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);
        double responseTime = calculateResponseTime(provider.webServerResponsiveness, provider.expectedNetworkDelay, provider.geographicLocation);

        if (cost < minCost || load < minLoad || responseTime < minResponseTime) {
          minCost = cost;
          minLoad = load;
          minResponseTime = responseTime;
          selectedProviderName = provider.name;
        }
      }
    }

    // Redirect the request to the selected provider's Web servers
    // (implementation details depend on the specific requirements and architecture)
  }
}

