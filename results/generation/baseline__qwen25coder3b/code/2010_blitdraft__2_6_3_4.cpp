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

void sendEmail(const std::string& emailSubject, const std::string& emailBody);
std::string generateReleaseNotes(const std::string& buildVersion);
std::string composeEmail(const std::string& releaseNotes);
void notifyProjectTeam(const std::string& emailSubject, const std::string& emailBody);
void deployToStaging(const std::string& buildVersion);

void sendEmail(const std::string& emailSubject, const std::string& emailBody) { notifyProjectTeam(emailSubject, emailBody); }

std::string generateReleaseNotes(const std::string& buildVersion) { return composeEmail("Release Notes for Build Version 

std::string composeEmail(const std::string& releaseNotes) { return "Release Notes for Build Version " + releaseNotes; }

void notifyProjectTeam(const std::string& emailSubject, const std::string& emailBody) { sendEmail(emailSubject, emailBody); }

void deployToStaging(const std::string& buildVersion) { std::string releaseNotes = generateReleaseNotes(buildVersion); std::string emailBody = composeEmail(releaseNotes); sendEmail("Release Notes for Build Version " + buildVersion, emailBody); notifyProjectTeam("Release Notes for Build Version " + buildVersion, emailBody); }

