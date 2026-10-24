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

${std::pair<std::string, int>}

std::pair<std::string, int> process_request(std::vector<std::pair<std::string, int>> requests);
std::vector<std::pair<std::string, int>> handle_data(std::vector<std::pair<std::string, int>> data);
void send_response(std::pair<std::string, int> response);

vector<pair<string, int>> process_request(vector<pair<string, int>> requests) {
  vector<pair<string, int>> generated_requests;
  for (auto& r : requests) {
    string unit = r.first;
    int state = r.second;
    generated_requests.push_back({unit, 1 - state});
  }
  return generated_requests;
}

vector<pair<string, int>> handle_data(vector<pair<string, int>> data) {
    vector<pair<string, int>> processed_data;
    for (auto& d : data) {
      string unit = d.first;
      int state = d.second;
      processed_data.push_back({unit, state});
    }
    return processed_data;
  }
  

void send_response(std::pair<std::string, int> response) {
  std::string turned_on = response.second == 1 ? " turned on " : " turned off ";
  return {turned_on, response.first};
}

