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

void sendEmailConfirmation(const std::string& customerEmail, const std::string& shippingAddress, const std::string& trackingNumber) { sendTechnicalQueryEmail(customerEmail, std::string::format("Technical query from %s: %s", customerEmail.c_str(), shippingNumber.c_str())); }

void sendTechnicalQueryEmail(const std::string& customerEmail, const std::string& query) { std::ostringstream oss; oss << "Technical query from " << customerEmail << ": " << query; sendEmailConfirmation(customerEmail, oss.str()); }

