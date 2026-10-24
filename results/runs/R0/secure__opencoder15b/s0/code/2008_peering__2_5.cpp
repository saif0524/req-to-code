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

double calculate_cost(std::vector<double> &latencies);
std::vector<std::string> select_peers(std::vector<double> &latencies, double threshold);
std::string redirect_request(std::string &request, std::vector<std::string> &peers);
std::map<std::string, double> get_attributes(std::string &provider);
void update_attributes(std::string &provider, std::map<std::string, double> &attributes);

double calculate_cost(std::vector<double> &latencies) {
  double total_cost = 0;
  for (double latency : latencies) {
    total_cost += latency;
  }
  return total_cost;
}

double calculate_cost(std::vector<double> &latencies) {
   double total_cost = 0;
   for (double latency : latencies) {
     total_cost += latency;
   }
   return total_cost;
}

std::vector<std::string> select_peers(std::vector<double> &latencies, double threshold) {
   std::vector<std::string> peers;
   for (int i = 0; i < latencies.size(); i++) {
     if (latencies[i] < threshold) {
       peers.push_back(latencies[i]);
     }
   }
   return peers;
}

std::string redirect_request(std::string &request, std::vector<std::string> &peers) {
   for (std::string peer : peers) {
     if (get_attributes(peer).find("response_time") != get_attributes(peer).end()) {
       return peer;
     }
   }
   return peers[0];
}

std::map<std::string, double> get_attributes(std::string &provider) {
   // Implementation to get attributes from the CDN provider
   return attributes;
}

void update_attributes(std::string &provider, std::map<std::string, double> &attributes) {
   // Implementation to update attributes of the CDN provider
}

std::string redirect_request(std::string &request, std::vector<std::string> &peers) {
    for (std::string peer : peers) {
        if (get_attributes(peer).find("response_time") != get_attributes(peer).end()) {
            return peer;
        }
    }
    return peers[0];
}

std::map<std::string, double> get_attributes(std::string &provider) {
    // Implementation to get attributes from the CDN provider
    std::map<std::string, double> attributes;
    // Add your code here to retrieve the attributes from the CDN provider
    return attributes;
}

double calculate_cost(std::vector<double> &latencies) {
   double total_cost = 0;
   for (double latency : latencies) {
     total_cost += latency;
   }
   return total_cost;
}

std::vector<std::string> select_peers(std::vector<double> &latencies, double threshold) {
   std::vector<std::string> peers;
   for (int i = 0; i < latencies.size(); i++) {
     if (latencies[i] < threshold) {
       peers.push_back(latencies[i]);
     }
   }
   return peers;
}

std::string redirect_request(std::string &request, std::vector<std::string> &peers) {
   for (std::string peer : peers) {
     if (get_attributes(peer).find("response_time") != get_attributes(peer).end()) {
       return peer;
     }
   }
   return peers[0];
}

std::map<std::string, double> get_attributes(std::string &provider) {
   // Implementation to get attributes from the CDN provider
   return attributes;
}

void update_attributes(std::string &provider, std::map<std::string, double> &attributes) {
   // Implementation to update attributes of the CDN provider
}

std::string redirect_request(std::string &request, std::vector<std::string> &peers) {
   for (std::string peer : peers) {
     if (get_attributes(peer).find("response_time") != get_attributes(peer).end()) {
       return peer;
     }
   }
   return peers[0];
}

std::map<std::string, double> get_attributes(std::string &provider) {
   std::map<std::string, double> attributes;
   // Add your code here to retrieve the attributes from the CDN provider
   return attributes;
}

