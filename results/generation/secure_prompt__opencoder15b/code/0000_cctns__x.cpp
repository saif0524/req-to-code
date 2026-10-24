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

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts);
void processComplaint(const std::string& complaintId);
std::string getComplaintDetails(const std::string& complaintId);
void updateComplaintStatus(const std::string& complaintId, const std::string& status);
std::string getComplaintHistory(const std::string& citizenId);

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts) {
  // Implementation of the function
}

void processComplaint(const std::string& complaintId) {
  // Implementation of the function
}

std::string getComplaintDetails(const std::string& complaintId) {
   // Implementation of the function
   // Retrieve the details of a complaint
   // Return JSON with 'complaintDetails': complaint details
}

void updateComplaintStatus(const std::string& complaintId, const std::string& status) {
    // Implementation of the function
    // Update the status of a complaint in the database or any other data storage system
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only
}

std::string getComplaintHistory(const std::string& citizenId) {
    // Implementation of the function
    // Retrieve the complaint history from the database for the given citizenId
    // Return the complaint history as a JSON string
}

