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

void send_order_confirmation(const std::string& email, const std::string& order_id);
void send_system_admin_notification(const std::string& email, const std::string& message);

void send_order_confirmation(const std::string& email, const std::string& order_id) {
  // Implementation of the function
  // Send an e-mail confirmation to the customer with the tracking number
  // ...
}

void send_system_admin_notification(const std::string& email, const std::string& message) {
   // Create a mail object
   Mail mail;
   mail.set_to(email);
   mail.set_subject("System Administrator Notification");
   mail.set_body(message);
   // Send the mail
   mail.send();
}

