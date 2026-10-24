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

void sendEmailConfirmation(std::string customerName, std::string orderDetails, std::string trackingNumber);

void sendEmailConfirmation(std::string customerName, std::string orderDetails, std::string trackingNumber) {
   json j = { {"customerName", customerName}, {"orderDetails", orderDetails}, {"trackingNumber", trackingNumber} };

   std::string subject = "Order Confirmation";
   std::string body = "Thank you for your order! Your order details and tracking number have been sent to you.\n\nOrder Details: " + orderDetails + ".\nTracking Number: " + trackingNumber + ";\n";

   sendEmail(customerName, subject, body);
}

