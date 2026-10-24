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

std::vector<std::string> getRealProfiles();
std::map<std::string, std::string> parseProfile(std::string profile);
std::string getProfilePicture(std::string profile);
std::string getProfileName(std::string profile);
std::string getProfileBio(std::string profile);

std::vector<std::string> getRealProfiles() {
  // Fetch the profiles from the Get Real API
  std::vector<std::string> profiles = fetchProfilesFromAPI();

  // Parse each profile and store it in a map
  std::vector<std::map<std::string, std::string>> parsedProfiles;
  for (const auto& profile : profiles) {
    std::map<std::string, std::string> parsedProfile = parseProfile(profile);
    parsedProfiles.push_back(parsedProfile);
  }

  // Return the parsed profiles
  return parsedProfiles;
}

std::map<std::string, std::string> parseProfile(std::string profile) {
  std::map<std::string, std::string> parsedProfile;
  std::vector<std::string> profileAttributes = split(profile, ',');
  for (const auto& attribute : profileAttributes) {
    std::vector<std::string> attributePair = split(attribute, ':');
    parsedProfile[attributePair[0]] = attributePair[1];
  }
  return parsedProfile;
}

std::string getProfilePicture(std::string profile) {
  std::vector<std::string> profileAttributes = split(profile, ',');
  for (const auto& attribute : profileAttributes) {
    std::vector<std::string> attributePair = split(attribute, ':');
    if (attributePair[0] == "picture") {
      return attributePair[1];
    }
  }
  return "";
}

std::string getProfileName(std::string profile) {
  std::vector<std::string> profileAttributes = split(profile, ',');
  for (const auto& attribute : profileAttributes) {
    std::vector<std::string> attributePair = split(attribute, ':');
    if (attributePair[0] == "name") {
      return attributePair[1];
    }
  }
  return "";
}

std::string getProfileBio(std::string profile) {
   std::map<std::string, std::string> parsedProfile = parseProfile(profile);
   std::string bio = parsedProfile.find("bio") != parsedProfile.end() ? parsedProfile.at("bio") : "";
   return bio;
}

