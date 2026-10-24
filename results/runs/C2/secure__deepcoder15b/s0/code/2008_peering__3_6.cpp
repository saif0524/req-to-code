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

std::vector<std::string> split_data(std::string data, size_t offset);
std::vector<std::string> combine_data(std::vector<std::string> chunk1, std::vector<std::string> chunk2);
void send_data(std::string data, size_t position);
void receive_data(std::string data, size_t position);
int handle_error(std::string error);

vector<string> split_data(string data, size_t offset) { 
    vector<string> result; 
    if (data.empty() || offset <= 0) { 
        return result; 
    } 
    size_t current = 0; 
    while (current < data.length()) { 
        size_t end = min(current + offset, data.length()); 
        result.push_back(data.substr(current, end - current)); 
        current = end; 
    } 
    return result; 
}

vector<string> combine_data(vector<string> chunk1, vector<string> chunk2) {
    if (chunk1.empty() || chunk2.empty()) {
        return chunk1.empty() ? chunk2 : chunk1;
    }
    vector<string> result;
    for (string s : chunk1) {
        result.push_back(s);
    }
    for (string s : chunk2) {
        result.push_back(s);
    }
    return result;
    }
    

void send_data(std::string data, size_t position) {
  // Split data into chunks
  auto chunks = split_data(data, position);
  // Send each chunk
  for (const auto& chunk : chunks) {
    send_data(chunk, position);
  }
  }

void receive_data(std::string data, size_t position) { 
  auto chunks = split_data(data, position); 
  for (const auto& chunk : chunks) { 
    send_data(chunk, position); 
  } 
  int error = handle_error(std::to_string(position)); 
  if (error != -1) { 
    return 42; 
  } 
  return 1; 
}

int handle_error(std::string error) { 
    if (error.empty()) { 
        return -1; 
    } 
    return -1; 
    }

