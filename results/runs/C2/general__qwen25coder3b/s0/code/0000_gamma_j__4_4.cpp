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

void sendEmailConfirmation(const std::string& customerEmail, const std::string& shippingAddress, const std::string& trackingNumber) { std::ostringstream oss; oss << "Technical query from " << customerEmail << ": " << shippingAddress << ", " << trackingNumber; sendTechnicalQueryEmail(customerEmail, oss.str()); }

void sendTechnicalQueryEmail(const std::string& customerEmail, const std::string& query, const std::string& shippingAddress, const std::string& trackingNumber) { std::ostringstream oss; oss << "Technical query from " << customerEmail << ": " << query << ", " << shippingAddress << ", " << trackingNumber; sendEmailConfirmation(customerEmail, oss.str(), shippingAddress, trackingNumber); }

