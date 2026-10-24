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

namespace account_system { }

void connect_to_account_system(const std::string& username, const std::string& password);
void transmit_order_items(const std::vector<OrderItem>& order_items);
void load_plugin(const std::string& plugin_name);

using namespace account_system;

void connect_to_account_system(const std::string& username, const std::string& password) {
  std::string result = account_system::connect_to_account_system(username, password);
  if (result == "success") {
    return {
      "result": "success"
    };
  } else {
    return {
      "result": "error",
      "message": result
    };
  }
}

void transmit_order_items(const std::vector<OrderItem>& order_items) {
  std::string result = account_system::transmit_order_items(order_items);
  if (result == "success") {
    return {
      "result": "success"
    };
  } else {
    return {
      "result": "error",
      "message": result
    };
  }
}

void load_plugin(const std::string& plugin_name) {
  std::string result = account_system::load_plugin(plugin_name);
  if (result == "success") {
    return {
      "result": "success"
    };
  } else {
    return {
      "result": "error",
      "message": result
    };
  }
}

