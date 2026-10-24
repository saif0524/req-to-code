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

std::pair<std::string, std::vector<std::string>> send_email_confirmation(int customer_id, int tracking_number, std::string email_address, std::string subject);
std::pair<std::string, std::vector<std::string>> send_email_to_system_admin(int system_admin_id, std::pair<int, std::string>> query_data);

pair<string, vector<string>> send_email_confirmation(int customer_id, int tracking_number, string email_address, string subject) {
  email::message msg;
  msg.setSubject(subject);
  return make_pair(msg.text(), vector<string });
  return make_pair(msg.text(), vector<string });
  return make_pair(msg.text(), vector<string });
  return make_pair(msg.text(), vector<string });
  return make_pair(msg.text(), vector<string });
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));
  return make_pair(msg.text(), vector<string()));

pair<string, vector<string>> send_email_to_system_admin(int system_admin_id, std::pair<int, std::string>> query_data {
  auto msg = email::message();
  msg.setSubject(

