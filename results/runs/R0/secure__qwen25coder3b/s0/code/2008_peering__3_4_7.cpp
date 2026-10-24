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

bool validate_request(const std::string& request);
void handle_malicious_request(const std::string& request);
bool check_long_term_peering(const std::string& peering_id);
void perform_short_term_negotiation(const std::string& peering_id);

bool validate_request(const std::string& request) {
  static const std::vector<std::string> malicious_keywords = {"malicious", "attack", "harmful"};
  for (const auto& keyword : malicious_keywords) {
    if (request.find(keyword) != std::string::npos) {
      return false;
    }
  }
  return true;
}

void handle_malicious_request(const std::string& request) {
  static const std::vector<std::string> malicious_keywords = {"malicious", "attack", "harmful"};
  for (const auto& keyword : malicious_keywords) {
    if (request.find(keyword) != std::string::npos) {
      std::cout << "Malicious request detected: " << request << std::endl;
      // Log the request and notify relevant parties
      return;
    }
  }
  std::cout << "Request is safe: " << request << std::endl;
}

bool check_long_term_peering(const std::string& peering_id) {
  static const std::vector<std::string> long_term_peering_ids = {"id1", "id2", "id3"};
  for (const auto& id : long_term_peering_ids) {
    if (id == peering_id) {
      return true;
    }
  }
  return false;
}

void perform_short_term_negotiation(const std::string& peering_id) {
  if (!check_long_term_peering(peering_id)) {
    std::cout << "Short-term negotiation initiated for peering ID: " << peering_id << std::endl;
    // Perform negotiation logic here
    std::cout << "Negotiation completed for peering ID: " << peering_id << std::endl;
  } else {
    std::cout << "Peering ID: " << peering_id << " is already long-term, no short-term negotiation needed." << std::endl;
  }
}

