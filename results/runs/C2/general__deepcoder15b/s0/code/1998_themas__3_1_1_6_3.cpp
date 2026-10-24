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

{ std::vector<std::int64_t> read_data; }

std::vector<int> read_data(const std::string &file_path)"
    std::vector<int> read_data(const std::string &file_path) {
    std::vector<int> data;
    std::fileread(data, std::endvector, std:: streams::text, file_path);
    return data;
    };
std::pair<int, int> get_min_max(std::vector<int> data)"
    std::pair<int, int> get_min_max(std::vector<int> data) {
    int min = data[0];
    int max = data[1];
    return {min, max};
    };
std::pair<int, int> valid_range(std::vector<int> data)"
    std::pair<int, int> valid_range(std::vector<int> data) {
    int min = data[0];
    int max = data[1];
    return {min, max};
    };
bool check_inside(int temp, std::pair<int, int> valid_range)"
    bool check_inside(int temp, std::pair<int, int> valid_range) {
    return temp >= valid_range.first && temp <= valid_range.second;
    };
int main()"
    int main() {
    // code here
    return 0;
    };

std::vector<int> read_data(const std::string &file_path) {
    std::vector<int> data;
    std::fileread(data, std::endvector, std:: streams::text, file_path);
    return data;
}
std::pair<int, int> get_min_max(std::vector<int> data) {
    int min_temp = data[0];
    int max_temp = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < min_temp) {
            min_temp = data[i];
        }
        if (data[i] > max_temp) {
            max_temp = data[i];
        }
    }
    return {min_temp, max_temp};
}
std::pair<int, int> valid_range(std::vector<int> data) {
    int min = data[0];
    int max = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }
    return {min, max};
}
bool check_inside(int temp, std::pair<int, int> valid_range) {
    return temp >= valid_range.first && temp <= valid_range.second; 
}
int main() {
    return 0;
}

std::vector<int> read_data(const std::string &file_path) { std::vector<int> data; std::fileread(data, std::endvector, std:: streams::text, file_path); return data; }
std::pair<int, int> get_min_max(std::vector<int> data) { int min_temp = data[0]; int max_temp = data[0]; for (size_t i = 1; i < data.size(); ++i) { if (data[i] < min_temp) { min_temp = data[i]; } if (data[i] > max_temp) { max_temp = data[i]; } } return {min_temp, max_temp}; }
std::pair<int, int> valid_range(std::vector<int> data) { int min = data[0]; int max = data[0]; for (size_t i = 1; i < data.size(); ++i) { if (data[i] < min) { min = data[i]; } if (data[i] > max) { max = data[i]; } } return {min, max}; }
bool check_inside(int temp, std::pair<int, int> valid_range) { return temp >= valid_range.first && temp <= valid_range.second; }
int main() { int temp = 70; auto range = valid_range(data); check_inside(temp, range); return 0; }

std::pair<int, int> valid_range(std::vector<int> data) {
  if (data.empty()) {
    return {0, 0};
  }
  int min = data[0];
  int max = data[0];
  for (size_t i = 1; i < data.size(); ++i) {
    if (data[i] < min) {
      min = data[i];
    }
    if (data[i] > max) {
      max = data[i];
    }
  }
  return {min, max};
}

bool check_inside(int temp, std::pair<int, int> valid_range) 
 \ { 
     int min = valid_range.first; 
     int max = valid_range.second; 
     return temp >= min && temp <= max; 
 \ }

int main() { return 0; }

