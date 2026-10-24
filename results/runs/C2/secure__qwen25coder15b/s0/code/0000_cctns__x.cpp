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

void registerComplaint(const std::string& complaint, const std::string& citizenId, const std::string& policeId);
void processComplaint(const std::string& complaintId, const std::string& evidence, const std::string& facts);
void updateComplaintStatus(const std::string& complaintId, const std::string& status);
void sendComplaintToPolice(const std::string& complaintId, const std::string& policeId);
void displayComplaintStatus(const std::string& complaintId);

void registerComplaint(const std::string& complaint, const std::string& citizenId, const std::string& policeId) {
  if (complaint.empty() || citizenId.empty() || policeId.empty()) {
    return;
  }
  processComplaint(complaint, citizenId, policeId);
}

void processComplaint(const std::string& complaintId, const std::string& evidence, const std::string& facts) {
  if (complaintId.empty() || evidence.empty() || facts.empty()) {
    return;
  }
  updateComplaintStatus(complaintId, "Processing");
  sendComplaintToPolice(complaintId, "Police");
  displayComplaintStatus(complaintId);
}

void updateComplaintStatus(const std::string& complaintId, const std::string& evidence, const std::string& facts, const std::string& policeId) {  if (complaintId.empty() || evidence.empty() || facts.empty() || policeId.empty()) {    return;  }  processComplaint(complaintId, evidence, facts);  sendComplaintToPolice(complaintId, policeId);}

void sendComplaintToPolice(const std::string& complaintId, const std::string& policeId) {  if (complaintId.empty() || policeId.empty()) {    return;  }  updateComplaintStatus(complaintId, 'Processing');  sendComplaintToPolice(complaintId, policeId);  displayComplaintStatus(complaintId);}

void displayComplaintStatus(const std::string& complaintId) {  if (complaintId.empty()) {    return;  }  processComplaint(complaintId, 'Display');  sendComplaintToPolice(complaintId, 'Display');}

