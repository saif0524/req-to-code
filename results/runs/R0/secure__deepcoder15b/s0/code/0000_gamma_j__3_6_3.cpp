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

std::vector<std::pair<int, int>> points

std::vector<int> read_data(std::vector<int> input);
std::vector<int> write_data(std::vector<int> data);
bool validate_input(std::vector<int> data);

std::vector<int> read_data(std::vector<int> input) {
  return input;
  }

std::vector<int> write_data(std::vector<int> data) {
  std::vector<int> result;
  std::out.write(result, data.begin(), data.end());
  return result;
  }

bool validate_input(std::vector<int> data) {
  if (data.empty()) {
    return false; // Empty data is invalid
  }
  if (data.size() < 1) {
    return false; // Minimum size required
  }
  if (data.size() % 2 != 0) {
    return false; // Size must be even
  }
  for (int num : data) {
    if (num < 0) {
      return false; // All elements must be non-negative
    }
  }
  return true; // All criteria met
}

