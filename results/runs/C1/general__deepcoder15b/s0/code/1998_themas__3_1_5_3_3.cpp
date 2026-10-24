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

std::pair<std::string, int> process_request(std::vector<std::pair<std::string, int>> requests);
std::vector<std::pair<std::string, int>> handle_data(std::vector<std::pair<std::string, int>> data);
void send_response(std::pair<std::string, int> response);

std::pair<std::string, int> process_request(std::vector<std::pair<std::string, int>> requests) {
  std::vector<std::pair<std::string, int>> generated_requests;
  for (auto& r : requests) {
    std::string unit = r.first;
    int state = r.second;
    if (state == 0) { // current is off
      generated_requests.push_back({unit, 1}); // send request to turn on
    }
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
    std::pair<std::string, int> current_state = {response.first, response.second};
    for (auto& unit : current_state) {
        if (unit.second == 1) {
            unit.first = " turned on ";
        }
    }
    return current_state;
  }
  

