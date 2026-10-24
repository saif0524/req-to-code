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

vector<int> dijkstra(adjacency_list<vector<int>> graph, int start);
bool validate_credit_card(string card);
vector<int> compress_image(vector<int> image, float ratio);
vector<int> load_data(stream<int> source);
bool validate_email(string email);

vector<int> dijkstra(adjacency_list<vector<int>> graph, int start) {
    vector<int> distance(graph.size(), INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int current_dist = current.first;
        int current_node = current.second;

        if (current_dist > distance[current_node]) {
            continue;
        }

        for (int neighbor : graph[current_node]) {
            int tentative_dist = current_dist + 1;
            if (tentative_dist < distance[neighbor]) {
                distance[neighbor] = tentative_dist;
                pq.push({tentative_dist, neighbor});
            }
        }
    }

    return distance;
  },
  

bool validate_credit_card(string card) {
  // Extract card number from string
  if (card.empty() || !isnumeric(card[0])) {
    return false;
  }

  // Check if card number is valid length
  if (card.size() < 13 || card.size() > 19) {
    return false;
  }

  // Check starting digits
  string valid_starts = 

vector<int> compress_image(vector<int> image, float ratio) { 
  if (image.empty()) { 
    return {}; 
  } 
  int original_size = image.size(); 
  float max_compressed_size = static_cast<float>(original_size * ratio); 
  vector<RunLength> run_length; 
  int current_value = image[0]; 
  int count = 1; 
  for (size_t i = 1; i < original_size; ++i) { 
    if (image[i] == current_value) { 
      count++; 
    } else { 
      run_length.push_back(RunLength(current_value, count)); 
      current_value = image[i]; 
      count = 1; 
    } 
  } 
  run_length.push_back(RunLength(current_value, count)); 
  vector<RunLength> compressed_runs; 
  for (auto &run : run_length) { 
    int value = run.value; 
    int count = run.count; 
    if (value == 0 || count == 0) { 
      continue; 
    } 
    int new_count = static_cast<int>(count * ratio); 
    if (new_count <= 0) { 
      continue; 
    } 
    compressed_runs.push_back(RunLength(value, new_count)); 
  } 
  vector<int> result; 
  for (auto &run : compressed_runs) { 
    int value = run.value; 
    int count = run.count; 
    for (int i = 0; i < count; i++) { 
      result.push_back(value); 
    } 
  } 
  return result; 
  }

vector<int> load_data(stream<int> source) {
  vector<int> result;
  stream_or<int> stream(source);
  while (stream >> int value) {
    result.push_back(value);
  }
  return result;
  }

bool validate_email(string email) {
  size_t local_pos = email.find('_');
  string local = (local_pos != string::npos) ? email.substr(0, local_pos) :;
  string domain = (local_pos != string::npos) ? email.substr(local_pos + 1) :;

  for (char c : local) {
    if (c < '0' || c > '9' || !isalnum(c)) {
      return false;
    }
  }

  for (char c : domain) {
    if (c < 'a' || c > 'z' || c < '0' || c > '9' || c == '_') {
      return false;
    }
  }

  return true;
  },
  

