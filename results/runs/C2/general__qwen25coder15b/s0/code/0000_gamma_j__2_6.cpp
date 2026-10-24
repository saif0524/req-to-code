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

struct web_server_config;
using json = nlohmann::json;

void install_online_help();
void deliver_operations_and_maintenance_manual();

void install_online_help() {
  web_server_config config;
  config.port = 8080;
  config.directory = "/path/to/help/files";
  web_server web_server(config);
  web_server.start();
  return json::object({"message", "online help installed successfully"});
}

void deliver_operations_and_maintenance_manual() {
  using json = nlohmann::json;

  web_server_config config;
  config.port = 8080;
  config.directory = "/path/to/help/files";

  web_server web_server(config);
  web_server.start();

  return json::object({
    "message", "operations and maintenance manual delivered successfully"
  });
}

