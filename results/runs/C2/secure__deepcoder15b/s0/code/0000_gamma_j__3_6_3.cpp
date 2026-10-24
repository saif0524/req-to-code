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

std::vector<int> read_data(std::vector<int> input);
std::vector<int> write_data(std::vector<int> data);
bool validate_input(std::vector<int> data);
std::vector<int> process_data(std::vector<int> validated_data);
void handle_error(std::vector<int> data);

std::vector<int> read_data(std::vector<int> input) {  if (validate_input(input)) {    return input;  } else {    return std::vector<int>();  } }

std::vector<int> write_data(std::vector<int> data) {
std::vector<int> result;
std::octwrite(result, data.begin(), data.end());
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

vector<int> process_data(vector<int> validated_data) {
  vector<int> result;
  for (int i = validated_data.size() - 1; i >= 0; i--) {
    result.push_back(validated_data[i]);
  }
  return result;
  }

vector<int>& handle_error(vector<int>& data) { return data; }

