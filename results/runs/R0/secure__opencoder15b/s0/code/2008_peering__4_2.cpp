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

std::string server; int port; std::string message; int connection_id;

establish_connection(std::string server, int port);
send_message(std::string message, int connection_id);
receive_message(int connection_id);
close_connection(int connection_id);

int establish_connection(std::string server, int port) {
  // Establish a TCP/IP connection to the server using the specified port number.
  // Your code here.
}

int send_message(std::string message, int connection_id) {
  // Send a message over the established connection using the connection ID.
  // Your code here.
}

int receive_message(int connection_id) {
  // Receive a message from the server using the connection ID.
  // Your code here.
}

int close_connection(int connection_id) {
  // Close the connection using the connection ID.
  // Your code here.
}

