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

void registerComplaint(const std::string& citizenName, const std::string& complaintDescription, const std::string& evidence);
void processComplaint(const std::string& complaintId, const std::string& investigationDetails);
void updateComplaintStatus(const std::string& complaintId, const std::string& status);
std::string getComplaintDetails(const std::string& complaintId);
std::vector<std::string> searchComplaints(const std::string& keyword);

std::vector<std::string> complaints;  // Shared declaration for storing complaints

void registerComplaint(const std::string& citizenName, const std::string& complaintDescription, const std::string& evidence) {
  std::string complaintId = std::to_string(complaints.size() + 1);  // Generate complaint ID
  complaints.push_back(citizenName + ' ' + complaintDescription + ' ' + evidence);  // Store complaint
  return {"complaintId": complaintId};  // Return complaint ID as JSON
}

void processComplaint(const std::string& complaintId, const std::string& investigationDetails) {
  for (size_t i = 0; i < complaints.size(); ++i) {
    if (complaints[i].find(complaintId) != std::string::npos) {
      complaints[i] += ' ' + investigationDetails;
      return {

void updateComplaintStatus(const std::string& complaintId, const std::string& status) {
  for (size_t i = 0; i < complaints.size(); ++i) {
    if (complaints[i].find(complaintId) != std::string::npos) {
      complaints[i] += ' ' + status;
      return {
        "complaintId": complaintId,
        "reasoning": "Updated complaint status to: " + status
      };
    }
  }
  return {
    "complaintId": complaintId,
    "reasoning": "Complaint not found"
  };
}

std::string getComplaintDetails(const std::string& complaintId) {
  for (size_t i = 0; i < complaints.size(); ++i) {
    if (complaints[i].find(complaintId) != std::string::npos) {
      return {
        "complaintId": complaintId,
        "details": complaints[i]
      };
    }
  }
  return {
    "complaintId": complaintId,
    "reasoning": "Complaint not found"
  };
}

std::vector<std::string> searchComplaints(const std::string& keyword) {
  std::vector<std::string> result;
  for (const auto& complaint : complaints) {
    if (complaint.find(keyword) != std::string::npos) {
      result.push_back(complaintId);
    }
  }
  return result;
}

