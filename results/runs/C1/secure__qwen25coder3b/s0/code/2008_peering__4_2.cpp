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

std::unique_ptr<TCPConnection> createTCPConnection(const std::string& serverAddress, int portNumber);
void sendMessage(TCPConnection& connection, const std::string& message);
std::string receiveMessage(TCPConnection& connection);
void processMessage(const std::string& message);
void handleSurrogateInteraction(const std::string& request, std::string& response);

std::unique_ptr<TCPConnection> createTCPConnection(const std::string& serverAddress, int portNumber) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    throw std::runtime_error("Failed to create socket");
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portNumber);
  if (inet_pton(AF_INET, serverAddress.c_str(), &serv_addr.sin_addr) <= 0) {
    throw std::runtime_error("Invalid address/ Address not supported");
  }

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    throw std::runtime_error("Failed to connect");
  }

  return std::unique_ptr<TCPConnection>(new TCPConnection(sockfd));
}

void sendMessage(TCPConnection& connection, const std::string& message) {
  if (send(connection.getSocket(), message.c_str(), message.size(), 0) == -1) {
    throw std::runtime_error("Failed to send message");
  }
}

std::string receiveMessage(TCPConnection& connection) {
  char buffer[1024];
  int bytesRead = recv(connection.getSocket(), buffer, sizeof(buffer) - 1, 0);
  if (bytesRead == -1) {
    throw std::runtime_error("Failed to receive message");
  }
  buffer[bytesRead] = '\0';
  return std::string(buffer);
}

void processMessage(const std::string& message) {
  size_t headerLength = 4; // Assuming a 4-byte header for total data length
  if (message.size() < headerLength) {
    throw std::runtime_error("Invalid message length");
  }

  size_t totalDataLength = std::stoul(message.substr(0, headerLength));
  if (message.size() != totalDataLength + headerLength) {
    throw std::runtime_error("Invalid message length");
  }

  std::string request = message.substr(headerLength);
  // Process the request based on the protocol
}

void handleSurrogateInteraction(const std::string& request, std::string& response) {
  size_t boundary = request.find(' '); // Assuming the request and response are separated by a space
  if (boundary == std::string::npos) {
    throw std::runtime_error("Invalid request format");
  }

  std::string requestPart = request.substr(0, boundary);
  std::string responsePart = request.substr(boundary + 1);

  // Process the request and construct the response
  // For simplicity, we will just replace the request part with the response part
  response = responsePart;
}

