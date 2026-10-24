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

void sendEmailConfirmation(const std::string& customerEmail, const std::string& shippingAddress, const std::string& trackingNumber);
void sendTechnicalQueryEmail(const std::string& customerEmail, const std::string& query);

void sendEmailConfirmation(const std::string& customerEmail, const std::string& shippingAddress, const std::string& trackingNumber) {
  if (customerEmail.empty() || shippingAddress.empty() || trackingNumber.empty()) {
    throw std::invalid_argument("All parameters must be non-empty strings.");
  }

  // Use a secure email library to send the email
  // Example: using a hypothetical secure email library
  try {
    secureEmailLibrary::sendEmail(customerEmail, "System Administrator", "Order Confirmation", "Your order has been shipped to: " + shippingAddress + " with tracking number: " + trackingNumber);
  } catch (const std::exception& e) {
    std::cerr << "Failed to send email: " << e.what() << std::endl;
  }
}

void sendTechnicalQueryEmail(const std::string& customerEmail, const std::string& query) {
  if (customerEmail.empty() || query.empty()) {
    throw std::invalid_argument("All parameters must be non-empty strings.");
  }

  // Use a secure email library to send the email
  // Example: using a hypothetical secure email library
  try {
    secureEmailLibrary::sendEmail(customerEmail, "System Administrator", "Technical Query", "Customer: " + customerEmail + "\nQuery: " + query);
  } catch (const std::exception& e) {
    std::cerr << "Failed to send email: " << e.what() << std::endl;
  }
}

