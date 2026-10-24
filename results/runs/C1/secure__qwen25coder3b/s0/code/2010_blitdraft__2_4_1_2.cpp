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

void scheduleUAT(const std::string& projectID, const std::string& startDate, const std::string& endDate);
bool checkUATStatus(const std::string& projectID);
void notifyUATParticipants(const std::string& projectID);
void logUATResults(const std::string& projectID, const std::string& results);
void updateProjectStatus(const std::string& projectID, const std::string& status);

void scheduleUAT(const std::string& projectID, const std::string& startDate, const std::string& endDate) {
  if (projectID.empty() || startDate.empty() || endDate.empty()) {
    throw std::invalid_argument("Invalid projectID, startDate, or endDate");
  }

  std::chrono::system_clock::time_point start, end;
  try {
    start = std::chrono::system_clock::from_string(startDate);
    end = std::chrono::system_clock::from_string(endDate);
  } catch (const std::invalid_argument& e) {
    throw std::invalid_argument("Invalid date format");
  }

  std::lock_guard<std::mutex> lock(uatMutex);
  if (scheduledUATs.find(projectID) != scheduledUATs.end()) {
    throw std::runtime_error("Project already has a scheduled UAT");
  }

  scheduledUATs[projectID] = {start, end};

  logUATResults(projectID, "UAT scheduled");
}

bool checkUATStatus(const std::string& projectID) {
  if (projectID.empty()) {
    return false;
  }

  auto it = scheduledUATs.find(projectID);
  if (it == scheduledUATs.end()) {
    return false;
  }

  auto [start, end] = it->second;
  auto now = std::chrono::system_clock::now();

  if (now >= start && now <= end) {
    return true;
  } else {
    return false;
  }
}

void notifyUATParticipants(const std::string& projectID) {
  if (projectID.empty()) {
    return;
  }

  auto it = scheduledUATs.find(projectID);
  if (it == scheduledUATs.end()) {
    return;
  }

  auto [start, end] = it->second;
  auto now = std::chrono::system_clock::now();

  if (now >= start && now <= end) {
    std::vector<std::string> participants = getParticipants(projectID);
    for (const auto& email : participants) {
      sendNotification(email, "UAT is scheduled for your project");
    }
  }
}

std::vector<std::string> getParticipants(const std::string& projectID) {
  // Implementation of getParticipants
}

void sendNotification(const std::string& email, const std::string& message) {
  // Implementation of sendNotification
}

void logUATResults(const std::string& projectID, const std::string& results) {
  if (projectID.empty() || results.empty()) {
    throw std::invalid_argument("Invalid projectID or results");
  }

  std::lock_guard<std::mutex> lock(uatMutex);
  uatResults[projectID] = results;

  logUATResults(projectID, "UAT results logged");
}

void updateProjectStatus(const std::string& projectID, const std::string& status) {
  if (projectID.empty()) {
    throw std::invalid_argument("Invalid projectID");
  }

  std::lock_guard<std::mutex> lock(uatMutex);
  auto it = scheduledUATs.find(projectID);
  if (it == scheduledUATs.end()) {
    logUATResults(projectID, "Project status update not applicable");
    return;
  }

  auto [start, end] = it->second;
  auto now = std::chrono::system_clock::now();

  if (now >= start && now <= end) {
    projectStatus[projectID] = status;
    logUATResults(projectID, "Project status updated");
  } else {
    logUATResults(projectID, "Project status update not applicable");
  }
}

