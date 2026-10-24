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

using namespace std;

int create_tcp_connection(const std::string& server_ip, int server_port);
void send_message(int connection_id, const std::string& message);
std::string receive_message(int connection_id);
void handle_request(int connection_id, const std::string& request);
void handle_response(int connection_id, const std::string& response);

int create_tcp_connection(const std::string& server_ip, int server_port) {
  int connection_id = socket(AF_INET, SOCK_STREAM, 0);
  if (connection_id == -1) {
    perror("socket");
    return -1;
  }
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  if (inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    close(connection_id);
    return -1;
  }
  if (connect(connection_id, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(connection_id);
    return -1;
  }
  return connection_id;
}

void send_message(int connection_id, const std::string& message) {
  int bytes_sent = send(connection_id, message.c_str(), message.size(), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(connection_id);
    return -1;
  }
  close(connection_id);
}

int receive_message(int connection_id) {
  char buffer[1024];
  int bytes_received = recv(connection_id, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    close(connection_id);
    return "Error receiving message";
  }
  return std::string(buffer, bytes_received);
}

void handle_request(int connection_id, const std::string& request) {
  if (connection_id == -1) {
    perror("socket");
    return;
  }
  std::string response = request + "Response from server";
  int bytes_sent = send(connection_id, response.c_str(), response.size(), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(connection_id);
  }
  close(connection_id);
}

void handle_response(int connection_id, const std::string& response) {
  if (connection_id == -1) {
    perror("socket");
    return;
  }
  std::string acknowledgement = response + "Acknowledgement from server";
  int bytes_sent = send(connection_id, acknowledgement.c_str(), acknowledgement.size(), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(connection_id);
  }
  close(connection_id);
}

