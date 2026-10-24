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

{ std::string }

string data;
vector<string> data;
string input;
void;
void;

string data() { 
  std::vector<std::string> data; 
  std::stringstream ss; 
  while (std::getline(ss, response, '
')) { 
    data.push_back(response); 
  } 
  return data; 
}

vector<string> data() { 
  vector<string> result; 
  string current_response; 
  do { 
    current_response = fetch_data(); 
    if (current_response.empty()) { 
      break; 
    } 
    result.push_back(current_response); 
  } while (!current_response.empty()); 
  return result; 
}

string input() {
  std::string current_response;
  do {
    current_response = getStream();
    if (!current_response.empty()) {
      data.push_back(current_response);
    }
  } while (current_response != '
');
  return current_response;
}

void close_connection() {
    return 0;
  }

void processMultipleRequest() {
    std::vector<std::string> data = data();
    std::string connection;
    do {
        connection = getStream();
        for (const std::string& request : data) {
            input();
            data.push_back(input());
        }
        close_connection();
    } while (true);
    return 0;
    } "reasoning": [
        

