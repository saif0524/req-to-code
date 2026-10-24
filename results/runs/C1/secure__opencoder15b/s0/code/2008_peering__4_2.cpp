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

