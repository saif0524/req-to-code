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

std::map<std::string, double> generate_monthly_report(const std::vector<Claim>& claims) {
  std::map<std::string, double> report;
  for (const auto& claim : claims) {
   report[claim.provider]; // Add provider to report
   report[claim.provider] += claim.amount; // Add payment to report
  }
  return report;
}

generate_monthly_report(const std::vector<Claim>& claims);
generate_provider_report(const std::vector<Claim>& claims);
generate_syndrome_report(const std::vector<Claim>& claims);
generate_documentation_report(const std::vector<Claim>& claims);
generate_time_trends_report(const std::vector<Claim>& claims);

std::map<std::string, double> generate_monthly_report(const std::vector<Claim>& claims) {
  std::map<std::string, double> report;
  for (const auto& claim : claims) {
   report[claim.provider]; // Add provider to report
   report[claim.provider] += claim.amount; // Add payment to report
  }
  return report;
}

std::map<std::string, double> generate_provider_report(const std::vector<Claim>& claims) {
    std::map<std::string, double> report;
    for (const auto& claim : claims) {
     report[claim.provider]; // Add provider to report
     report[claim.provider] += claim.amount; // Add payment to report
    }
    return report;
}

std::map<std::string, double> generate_syndrome_report(const std::vector<Claim>& claims) {
     std::map<std::string, double> report;
     for (const auto& claim : claims) {
     report[claim.provider]; // Add provider to report
     report[claim.provider] += claim.amount; // Add payment to report
     }
     return report;
}

std::map<std::string, double> generate_documentation_report(const std::vector<Claim>& claims) {
    std::map<std::string, double> report;
    for (const auto& claim : claims) {
     report[claim.provider]; // Add provider to report
     report[claim.provider] += claim.amount; // Add payment to report
    }
    return report;
}

std::map<std::string, double> generate_time_trends_report(const std::vector<Claim>& claims) {
    std::map<std::string, double> report;
    for (const auto& claim : claims) {
     report[claim.provider]; // Add provider to report
     report[claim.provider] += claim.amount; // Add payment to report
    }
    return report;
}

