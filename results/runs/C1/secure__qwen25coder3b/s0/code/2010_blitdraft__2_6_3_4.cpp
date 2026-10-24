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

void sendEmail(const std::string& subject, const std::string& body, const std::string& recipient);
std::string generateReleaseNotes(const std::string& buildVersion);
std::string formatEmailBody(const std::string& releaseNotes);
std::string constructEmail(const std::string& subject, const std::string& body);
void sendReleaseNotes(const std::string& buildVersion);

std::string generateReleaseNotes(const std::string& buildVersion) {
  return "Release Notes for Build Version: " + buildVersion;
}

std::string formatEmailBody(const std::string& releaseNotes) {
  std::string formattedBody;
  formattedBody.insert(0, "--- Release Notes Start ---\n");
  formattedBody += releaseNotes;
  formattedBody += "\n--- Release Notes End ---\n";
  return formattedBody;
}

std::string constructEmail(const std::string& subject, const std::string& body) { return subject + body; }

void sendReleaseNotes(const std::string& buildVersion) {
  std::string releaseNotes = generateReleaseNotes(buildVersion);
  std::string formattedBody = formatEmailBody(releaseNotes);
  std::string email = constructEmail("Release Notes", formattedBody);
  sendEmail("Release Notes", email, "project-team@example.com");
}

