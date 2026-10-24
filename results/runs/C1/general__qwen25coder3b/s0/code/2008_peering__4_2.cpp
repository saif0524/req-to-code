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
  size_t headerLength = 4; // Assuming 4 bytes for the header
  if (message.size() < headerLength) {
    throw std::runtime_error("Malformed message: header too short");
  }

  size_t totalDataLength = static_cast<size_t>(reinterpret_cast<const uint32_t*>(message.data())[0]);

  if (message.size() != headerLength + totalDataLength) {
    throw std::runtime_error("Malformed message: total data length mismatch");
  }

  std::string request = message.substr(headerLength, totalDataLength);

  // Process the request based on the protocol
  // ...
}

void handleSurrogateInteraction(const std::string& request, std::string& response) {
  if (request.find("GET") != std::string::npos) {
    // Handle HTTP GET request
    response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!";
  } else if (request.find("PUT") != std::string::npos) {
    // Handle HTTP PUT request
    response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nData received successfully";
  } else if (request.find("FTP") != std::string::npos) {
    // Handle FTP request
    response = "FTP response";
  } else {
    // Handle unknown request
    response = "Unknown request";
  }
}

