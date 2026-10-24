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

int create_tcp_connection(const std::string& server_ip, int server_port);
void send_message(int connection_id, const std::string& message);
std::string receive_message(int connection_id);
void handle_request(int connection_id, const std::string& request);
void handle_response(int connection_id, const std::string& response);

int create_tcp_connection(const std::string& server_ip, int server_port) {
  return create_tcp_connection(server_ip, server_port);
}

void send_message(int connection_id, const std::string& message) {
  int bytes_sent = send(connection_id, message.c_str(), message.size(), 0);
  if (bytes_sent == -1) {
    throw std::runtime_error("Failed to send message over TCP connection");
  }
}

std::string receive_message(int connection_id) {
  char buffer[1024];
  int bytes_received = recv(connection_id, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    throw std::runtime_error("Failed to receive message over TCP connection");
  }
  return std::string(buffer, bytes_received);
}

void handle_request(int connection_id, const std::string& request) {
  if (request.empty()) {
    send_message(connection_id, "Invalid request");
    return;
  }
  // Process the request and construct the response
  std::string response = process_request(request);
  send_message(connection_id, response);
}

void handle_response(int connection_id, const std::string& response) {
  if (response.empty()) {
    send_message(connection_id, "Invalid response");
    return;
  }
  // Process the response and construct the response
  std::string response = process_request(response);
  send_message(connection_id, response);
}

