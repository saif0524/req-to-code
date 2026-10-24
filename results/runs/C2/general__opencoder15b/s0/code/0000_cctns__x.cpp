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

std::string complaintId;
std::string evidence;
std::string facts;
std::string citizenId;
std::string status;
struct Complaint {
     std::string complaintId;
     std::string evidence;
     std::string facts;
     std::string citizenId;
     std::string status;
};

std::vector<Complaint> cctnsDatabase;

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts);
std::string getComplaintDetails(const std::string& complaintId);
void updateComplaintStatus(const std::string& complaintId, const std::string& status);
std::vector<std::string> getComplaintsByStatus(const std::string& status);
std::vector<std::string> getComplaintsByCitizen(const std::string& citizenId);

struct Complaint {
    std::string complaintId;
    std::string evidence;
    std::string facts;
    std::string citizenId;
    std::string status;
};

std::vector<Complaint> cctnsDatabase;

void registerComplaint(const std::string& complaint, const std::string& evidence, const std::string& facts) {
    Complaint newComplaint(complaint, evidence, facts);
    newComplaint.complaintId = std::to_string(cctnsDatabase.size() + 1);
    newComplaint.citizenId = "citizenId";
    newComplaint.status = "Pending";
    cctnsDatabase.push_back(newComplaint);
}

std::string getComplaintDetails(const std::string& complaintId) {
    for (const auto& complaint : cctnsDatabase) {
        if (complaint.complaintId == complaintId) {
            return complaint.details;
        }
    }
    return "Complaint not found.";
}

std::string updateComplaintStatus(const std::string& complaintId, const std::string& status) {
    for (auto& complaint : cctnsDatabase) {
        if (complaint.complaintId == complaintId) {
            complaint.status = status;
            return complaint.status;
        }
    }
    return "Complaint not found.";
}

std::vector<std::string> getComplaintsByStatus(const std::string& status) {
    std::vector<std::string> complaints;
    for (const auto& complaint : cctnsDatabase) {
        if (complaint.status == status) {
            complaints.push_back(complaint.details);
        }
    }
    return complaints;
}

std::vector<std::string> getComplaintsByCitizen(const std::string& citizenId) {
    std::vector<std::string> complaints;
    for (const auto& complaint : cctnsDatabase) {
        if (complaint.citizenId == citizenId) {
            complaints.push_back(complaint.details);
        }
    }
    return complaints;
}

std::string getComplaintDetails(const std::string& complaintId) {
     for (const auto& complaint : cctnsDatabase) {
        if (complaint.complaintId == complaintId) {
         return complaint.details;
        }
     }
     return "Complaint not found.";
}

void updateComplaintStatus(const std::string& complaintId, const std::string& status) {
     for (auto& complaint : cctnsDatabase) {
         if (complaint.complaintId == complaintId) {
             complaint.status = status;
             return;
         }
     }
     return "Complaint not found.";
}

std::vector<std::string> getComplaintsByStatus(const std::string& status) {
     std::vector<std::string> complaints;
     for (const auto& complaint : cctnsDatabase) {
         if (complaint.status == status) {
             complaints.push_back(complaint.details);
         }
     }
     return complaints;
}

std::vector<std::string> getComplaintsByCitizen(const std::string& citizenId) {
     std::vector<std::string> complaints;
     for (const auto& complaint : cctnsDatabase) {
         if (complaint.citizenId == citizenId) {
             complaints.push_back(complaint.details);
         }
     }
     return complaints;
}

