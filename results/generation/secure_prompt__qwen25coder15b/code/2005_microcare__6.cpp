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

void generateMonthlyReport(const std::vector<Claim>& cleanClaims, const std::vector<Claim>& claimsWithReservation, const std::vector<Provider>& providers);
void generateProviderReport(const std::vector<Provider>& providers);
void generateSyndromeReport(const std::vector<Provider>& providers);
void generatePatientPopulationReport(const std::vector<Provider>& providers);
void generatePrimaryClientReport(const std::vector<Provider>& providers);

void generateMonthlyReport(const std::vector<Claim>& cleanClaims, const std::vector<Claim>& claimsWithReservation, const std::vector<Provider>& providers) {
  // Filter claims based on the provided parameters
  std::vector<Claim> filteredClaims = filterClaims(cleanClaims, claimsWithReservation);

  // Generate reports using the shared functions
  generateProviderReport(providers);
  generateSyndromeReport(providers);
  generatePatientPopulationReport(providers);
  generatePrimaryClientReport(providers);

  // Return JSON object with the status of the report generation process
  return generateReportStatus("Report generation successful");
}

void generateProviderReport(const std::vector<Provider>& providers) {
  // Filter claims based on the provided parameters
  std::vector<Claim> filteredClaims = filterClaims(cleanClaims, claimsWithReservation);

  // Generate reports using the shared functions
  generateProviderReport(providers);

  // Return JSON object with the status of the report generation process
  return generateReportStatus("Report generation successful");
}

void generateSyndromeReport(const std::vector<Provider>& providers) {
  // Filter claims based on the provided parameters
  std::vector<Claim> filteredClaims = filterClaims(cleanClaims, claimsWithReservation);

  // Generate reports using the shared functions
  generateProviderReport(providers);
  generateSyndromeReport(providers);

  // Return JSON object with the status of the report generation process
  return generateReportStatus("Report generation successful");
}

void generatePatientPopulationReport(const std::vector<Claim>& cleanClaims, const std::vector<Claim>& claimsWithReservation) {
  // Filter claims based on the provided parameters
  std::vector<Claim> filteredClaims = filterClaims(cleanClaims, claimsWithReservation);

  // Map to store the counts of claims for each sex and age group
  std::map<std::pair<std::string, int>, int> sexAgeCounts;

  // Iterate through the filtered claims and count the number of claims for each sex and age group
  for (const auto& claim : filteredClaims) {
    std::string sex = claim.getSex();
    int age = claim.getAge();

    std::pair<std::string, int> key = {sex, age};
    sexAgeCounts[key]++;
  }

  // Generate the report
  std::string report = "Sex	Age	Count\n";

  // Iterate through the map and generate the report
  for (const auto& pair : sexAgeCounts) {
    report += pair.first.first + "	" + std::to_string(pair.first.second) + "	" + std::to_string(pair.second) + "\n";
  }

  // Return JSON object with the status of the report generation process
  return generateReportStatus("Report generation successful");
}

void generatePrimaryClientReport(const std::vector<Provider>& providers) {
  // Filter claims based on the provided parameters
  std::vector<Claim> filteredClaims = filterClaims(cleanClaims, claimsWithReservation);

  // Map to store the counts of primary clients for each provider
  std::map<std::string, int> primaryClientCounts;

  // Iterate through the filtered claims and count the number of primary clients for each provider
  for (const auto& claim : filteredClaims) {
    std::string primaryClient = claim.getPrimaryClient();

    // Increment the count for the primary client
    primaryClientCounts[primaryClient]++;
  }

  // Generate the report
  std::string report = "Primary Client	Count\n";

  // Iterate through the map and generate the report
  for (const auto& pair : primaryClientCounts) {
    report += pair.first + "	" + std::to_string(pair.second) + "\n";
  }

  // Return JSON object with the status of the report generation process
  return generateReportStatus("Report generation successful");
}

