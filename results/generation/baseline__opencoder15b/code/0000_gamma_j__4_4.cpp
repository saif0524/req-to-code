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
  // Create a JSON object to hold the email confirmation details
  json j = { {"customerName", customerName}, {"orderDetails", orderDetails}, {"trackingNumber", trackingNumber} };

  // Send an email confirmation to the customer
  std::string subject = "Order Confirmation";
  std::string body = "Thank you for your order! Your order details and tracking number have been sent to you.\n\nOrder Details: " + orderDetails + ".\nTracking Number: " + trackingNumber + "";
  sendEmail(customerName, subject, body);
}

