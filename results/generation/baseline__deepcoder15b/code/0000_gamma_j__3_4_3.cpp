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

.cpp

bool check_order_validity(const std::vector<std::string>& target_order, const std::vector<std::string>& current_order);
void send_email(std::string order_number, const std::string& message);
void handle_email_feedback(std::string email_message);
bool check_order_incorrectness(const std::vector<std::string>& current_order);

bool check_order_validity(const std::vector<std::string>& target_order, const std::vector<std::string>& current_order) {
  if (target_order.size() != current_order.size()) {
    return false;
  }
  std::sort(target_order.begin(), target_order.end());
  std::sort(current_order.begin(), current_order.end());
  return target_order == current_order;
  }
  

void send_email(std::string order_number, const std::string& message) {
  email::send(order_number, message);
  }

void handle_email_feedback(std::string email_message) {
  if (check_order_incorrectness(current_order, target_order)) {
    send_email(order_number, 

bool check_order_incorrectness(const std::vector<std::string>& current_order) {
    std::sort(current_order.begin(), current_order.end());
    for (size_t i = 0; i < current_order.size() - 1; ++i) {
        if (current_order[i] == current_order[i + 1]) {
            return true;
        }
    }
    return false;
}

