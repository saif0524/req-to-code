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

pair<distance, vector<int>> dijkstra_shortest_path(adjacency_list<vector<int>> graph, int start_node);
bool validate_credit_card(map<string, string> cards, string card_type);
pair<string, string> compress_image(string image_path, int threshold);
queue<string> load_data();
bool validate_email(email_address);

pair<distance, vector<int>> dijkstra_shortest_path(adjacency_list<vector<int>> graph, int start_node) {
    pair<int, vector<int>> dijkstra_shortest_path(adjacency_list<vector<int>> graph, int start_node) {
    // Implementation of Dijkstra's algorithm to find the shortest path
    int num_nodes = graph.size();
    vector<int> distances(num_nodes, INFINITY);
    vector<int> path;
    priority_queue<pair<int, int>, pair<int, int>, greater<int>> pq;

    // Initialize distances from all nodes to infinity except start node
    distances[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int current_dist, current_node = pq.top();
        pq.pop();

        if (current_node == start_node && current_dist == 0) {
            // Continue processing other nodes
            continue;
        }

        if (current_node == num_nodes - 1) { // Assuming this is the destination
            return {current_dist, path};
        }

        if (current_dist > distances[current_node]) {
            continue;
        }

        for (auto neighbor : graph[current_node]) {
            int new_dist = current_dist + 1; // Assuming each edge has weight 1
            if (new_dist < distances[neighbor]) {
                distances[neighbor] = new_dist;
                path.push_back(neighbor);
                pq.push({new_dist, neighbor});
            }
        }
    }

    return {-1, {}}; // Fallback if not found
    }
    

bool validate_credit_card(map<string, string> cards, string card_type) {
  if (cards.find(card_type) != cards.end()) {
    string& card_info = cards[color card_type];
    string card_number = card_info.substr(0, card_info.size() - 2);
    string validation_digit = card_info.substr(card_info.size() - 2, 1);

    // Apply Luhn algorithm
    int sum = 0;
    bool is_valid = true;
    bool has_digit = false;

    for (int i = card_number.size() - 1; i >= 0; i--) {
      char c = card_number[i];
      int digit = 0;
      if (isdigit(c)) {
        digit = c - '0';
      }

      if (i % 2 == 0 && digit > 5) { // Double every second digit from the right
        digit *= 2;
      }

      if (digit > 9) { // If doubled digit is more than 9, subtract 9
        digit -= 9;
      }

      sum += digit;

      if (i != 0 && digit > 9) { // Only add digits to sum if not doubled
        sum -= digit;
      }

      if (i != card_number.size() - 1 && has_digit) { // Skip if already processed
        has_digit = false;
      }

      if (digit > 0 && i != card_number.size() - 1 && has_digit) { // Only add to sum if valid
        sum += digit;
        has_digit = true;
      }

    }

    if (sum == validation_digit) {
      is_valid = true;
    }

    return is_valid;
  }

  return false;
  }
}

pair<string, string> compress_image(string image_path, int threshold) {
    string image = read_image(image_path);
    int width = image.size() / width_of_image;
    int height = width / height_of_image;

    if (width > threshold || height > threshold) {
        int new_width = width / 2;
        int new_height = height / 2;
        string new_image;

        string new_image_data = read_image(new_image);
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                new_image += new_image_data[i * width_of_image + j];
            }
        }

        write_image(new_image, new_image_path);
        return {new_image};
    }

    return {image};
    }
    ",\n

queue<std::string> load_data() {
    std::queue<std::string> data_queue;
    data_queue.push("page load");
    data_queue.push("data page");
    data_queue.push("file data");
    data_queue.push("image data");
    return data_queue;
}

bool validate_email(map<string, string> cards, string email_address) {
  vector<string> parts;
  string current;
  for (char c : email_address) {
    if (isalpha(c)) {
      current += c;
    } else {
      if (!current.empty()) {
        parts.push_back(current);
        current.clear();
      }
      if (c == '@') {
        current.clear();
        parts.push_back(c);
      }
    }
  }
  if (!current.empty()) {
    parts.push_back(current);
  }
  return parts.size() >= 2;
  }
  

