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

void process_request(const std::string& unit_name, bool is_on);
std::string generate_request(const std::string& unit_name, bool is_on);
void send_request(const std::string& request);
bool validate_request(const std::string& request);
void handle_request(const std::string& request);

void process_request(const std::string& unit_name, bool is_on) {
  std::string request = generate_request(unit_name, is_on);
  send_request(request);
}

std::string generate_request(const std::string& unit_name, bool is_on) {
  return unit_name + (is_on ? 

std::string generate_request(const std::string& unit_name, bool is_on) {
  return unit_name + (is_on ? 'on' : 'off');
}

void send_request(const std::string& request) {
  // Send the request to the appropriate system or device
  // Example: using a network library to send the request over the network
  // Example: using a file system to write the request to a file
  // Example: using a database to store the request
}

bool validate_request(const std::string& request) {
  if (request.empty() || request.size() < 5 || request.size() > 10) {
    return false;
  }
  if (request[0] != 'H' && request[0] != 'C') {
    return false;
  }
  if (request[1] != 'E' && request[1] != 'A') {
    return false;
  }
  if (request[2] != 'R' && request[2] != 'U') {
    return false;
  }
  if (request[3] != 'T' && request[3] != 'I') {
    return false;
  }
  if (request[4] != 'N' && request[4] != 'G') {
    return false;
  }
  if (request[5] != ' ' && request[5] != '-') {
    return false;
  }
  if (request[6] != 'H' && request[6] != 'E') {
    return false;
  }
  if (request[7] != 'A') {
    return false;
  }
  if (request[8] != 'R') {
    return false;
  }
  if (request[9] != 'U') {
    return false;
  }
  return true;
}

void handle_request(const std::string& request) {
  if (!validate_request(request)) {
    return "Invalid request";
  }
  send_request(request);
  return "Request processed successfully";
}

