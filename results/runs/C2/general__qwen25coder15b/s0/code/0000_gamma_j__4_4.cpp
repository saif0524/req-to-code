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

void sendEmailConfirmation(const std::string& customerEmail, const std::string& trackingNumber) {  sendEmail(customerEmail, trackingNumber);  log(customerEmail, trackingNumber); }

void sendEmailToSystemAdministrator(const std::string& technicalQuery) {  sendEmail(technicalQuery); }

