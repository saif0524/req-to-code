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

struct Police {
  bool registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts, const std::string& investigation);
  void updateComplaintStatus(const std::string& complaintId, const std::string& status);
  void sendNotification(const std::string& complaintId, const std::string& message);
};
struct Police {
  bool registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts, const std::string& investigation);
  void updateComplaintStatus(const std::string& complaintId, const std::string& status);
  std::optional<std::string> getComplaintDetails(const std::string& complaintId);
  void sendNotification(const std::string& complaintId, const std::string& message);
  void updateComplaintEvidence(const std::string& complaintId, const std::string& evidence);
};

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts, const std::string& investigation);
void updateComplaintStatus(const std::string& complaintId, const std::string& status);
std::optional<std::string> getComplaintDetails(const std::string& complaintId);
void sendNotification(const std::string& complaintId, const std::string& message);
void updateComplaintEvidence(const std::string& complaintId, const std::string& evidence);

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts, const std::string& investigation) {
  Police police;
  bool isComplaintRegistered = police.registerComplaint(complaint, evidence, facts, investigation);
  if (isComplaintRegistered) {
    police.updateComplaintStatus(complaintId, 'pending');
    police.sendNotification(complaintId, 'Your complaint has been registered. Please wait for the investigation to proceed.');
  } else {
    police.sendNotification(complaintId, 'Failed to register your complaint. Please try again later.');
  }
}

void updateComplaintStatus(const std::string& complaintId, const std::string& status) {
  Police police;
  bool isComplaintRegistered = police.registerComplaint(complaintId, evidence, facts, investigation);
  if (isComplaintRegistered) {
    police.updateComplaintStatus(complaintId, status);
    police.sendNotification(complaintId, 'Your complaint has been updated. Please wait for the investigation to proceed.');
  } else {
    police.sendNotification(complaintId, 'Failed to update your complaint. Please try again later.');
  }
}

struct Police {
  bool registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts, const std::string& investigation);
  void updateComplaintStatus(const std::string& complaintId, const std::string& status);
  std::optional<std::string> getComplaintDetails(const std::string& complaintId);
  void sendNotification(const std::string& complaintId, const std::string& message);
  void updateComplaintEvidence(const std::string& complaintId, const std::string& evidence);
};

std::optional<std::string> getComplaintDetails(const std::string& complaintId) {
  Police police;
  bool isComplaintRegistered = police.registerComplaint(complaintId, evidence, facts, investigation);
  if (isComplaintRegistered) {
    return police.getComplaintDetails(complaintId);
  } else {
    return std::nullopt;
  }
}

void sendNotification(const std::string& complaintId, const std::string& message, const Police& police, const std::string& evidence, const std::string& facts, const std::string& investigation) {
  bool isComplaintRegistered = police.registerComplaint(complaintId, evidence, facts, investigation);
  if (isComplaintRegistered) {
    police.updateComplaintStatus(complaintId, 'pending');
    police.sendNotification(complaintId, message);
  } else {
    police.sendNotification(complaintId, 'Failed to register your complaint. Please try again later.');
  }
}

void updateComplaintEvidence(const std::string& complaintId, const std::string& evidence, const Police& police) {
  bool isComplaintRegistered = police.registerComplaint(complaintId, evidence, facts, investigation);
  if (isComplaintRegistered) {
    police.updateComplaintStatus(complaintId, 'pending');
    police.sendNotification(complaintId, 'Your complaint has been updated. Please wait for the investigation to proceed.');
  } else {
    police.sendNotification(complaintId, 'Failed to update your complaint. Please try again later.');
  }
}

