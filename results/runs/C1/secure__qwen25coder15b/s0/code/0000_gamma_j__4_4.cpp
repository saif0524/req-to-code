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

void sendEmailConfirmation(const std::string& customerEmail, const std::string& trackingNumber);
void sendEmailToSystemAdministrator(const std::string& technicalQuery);

void sendEmailConfirmation(const std::string& customerEmail, const std::string& trackingNumber) {
  // Create the email message
  std::string emailMessage = "Dear Customer,\n\nYour order has been received and will be delivered to the following address:\n
" + customerEmail + "

Tracking Number: " + trackingNumber + "

Thank you for your order.

Best regards,
[Your Name]";\n\n// Send the email\nsendEmail(emailMessage);
}

void sendEmailToSystemAdministrator(const std::string& technicalQuery) {
  // Create the email message
  std::string emailMessage = "Dear System Administrator,\n\n" + technicalQuery + "\nBest regards,
[Your Name]";\n\n// Send the email\nsendEmail(emailMessage);
}

