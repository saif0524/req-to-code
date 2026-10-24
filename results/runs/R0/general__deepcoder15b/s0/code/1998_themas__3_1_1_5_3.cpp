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

std::pair<std::vector<std::object>, std::vector<std::object>> read_file(std::string& file, std::vector<std::object> data);
void process_data(std::pair<std::vector<std::object>, std::vector<std::object>> data);
void set_data(std::pair<std::vector<std::object>, std::vector<std::object>> data, std::string& file);
std::vector<std::object> get_overtemp(std::pair<std::vector<std::object>, std::vector<std::object>> data);
void set_overtemp(std::pair<std::vector<std::object>, std::vector<std::object>> data);

pair<std::vector<std::object>, std::vector<std::object>> read_file(std::string& file, std::vector<std::object> data) {
  std::vector<std::object> all_data;
  std::string line;
  std::ios::binary file_open(file);

  while (std::getline(file_open, line, '
')) {
    std::istringstream iss(line);
    std::vector<std::object> parts;
    while (std::getline(iss, std::string{}, std::back_inserter(parts))) {
      all_data.push_back(std::make_pair(parts[0], parts[1]));
    }
  }

  return std::make_pair(all_data.begin(), all_data.end());
}

int max_temp = -1; for (auto& pair : data) { int current = pair[0]; int new_val = pair[1]; if (current > max_temp) { max_temp = current; } else if (new_val > max_temp) { max_temp = new_val; } } return max_temp; }

void set_data(std::pair<std::object, std::object> data, std::string& file) {
  std::file_open(file);
  std::string line;
  std::vector<std::object> data_pair = data;
  for (auto& pair : data_pair) {
    std::istringstream iss(line);
    std::vector<std::object> parts;
    std::getline(iss, parts);
    std::write(line, line.length() + parts.size(), line.c_str(), line);
    std::getline(iss, line, '
');
  }
  std::file_close(file);
  return;
  }

std::vector<std::object> get_overtemp(std::pair<std::vector<std::object>, std::vector<std::object>> data) {
  int max_temp = -1; 
  for (auto& pair : data) { 
    int current = pair[0]; 
    if (current > max_temp) { 
      max_temp = current; 
    } 
  } 
  return std::vector<std::object>(std::max(0, max_temp), std::min(100, max_temp)); 
  }

void set_overtemp(std::pair<std::vector<std::object>, std::vector<std::object>> data) {
  int current_overtemp = -1;
  for (auto& pair : data) {
    int current = pair[0];
    if (current > current_overtemp) {
      current_overtemp = current;
    }
  }

  int new_overtemp = -1;
  for (auto& pair : data) {
    int current = pair[0];
    if (current > new_overtemp) {
      new_overtemp = current;
    }
  }

  return std::make_pair(current_overtemp, new_overtemp);
}

