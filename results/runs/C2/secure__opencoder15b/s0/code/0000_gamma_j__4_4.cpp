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

Mail mail;
using namespace std;

void send_order_confirmation(const std::string& email, const std::string& order_id);
void send_system_admin_notification(const std::string& email, const std::string& message);

void send_order_confirmation(const std::string& email, const std::string& order_id) {
     // Create a mail object
     Mail mail;
     mail.set_to(email);
     mail.set_subject("Order Confirmation");
     mail.set_body("Thank you for your order! Your tracking number is: " + order_id);
     // Send the mail
     mail.send();
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

