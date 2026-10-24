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

std::pair<bool, int> validate_request(std::vector<int> data);
std::pair<std::vector<int>, std::string> handle_request(std::pair<std::vector<int>, std::string> request);
std::pair<std::vector<int>, std::string> handle_malicious_request(std::pair<std::vector<int>, std::string> request);

std::pair<bool, int> validate_request(std::vector<int> data) {
  if (data.size() < 2) {
    return {true, -1};
  } else {
    return {false, -1};
  }
  }

pair<std::vector<int>, std::string> handle_request(pair<std::vector<int>, std::string> request) {
  auto data = request.first;
  if (data.size() < 2) {
    return {true, 

pair<std::vector<int>, std::string> handle_malicious_request(pair<std::vector<int>, std::string> request) {
  auto data = request.first;
  return {true, std::vector<int>{data.first}, std::string>{data.second}};
  }

