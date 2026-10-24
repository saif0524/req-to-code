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

bool validateOperatingSystem(const std::string& os);
bool validateArchitecture(const std::string& architecture);
bool validateFilename(const std::string& filename);
bool validateFileType(const std::string& filetype);
bool validateReleaseNotes(const std::string& releaseNotes);

bool validateOperatingSystem(const std::string& os) {
  std::vector<std::string> supportedOs = {"WINE", "32-bit MS Windows (95/98)", "32-bit MS Windows (NT/2000/XP)", "All 32-bit MS Windows (95/98/NT/2000/XP)", "Win2K", "WinXP", "Microsoft Windows Server 2003"};
  for (const auto& supported : supportedOs) {
    if (os == supported) {
      return true;
    }
  }
  return false;
}

bool validateArchitecture(const std::string& architecture) {
  std::vector<std::string> supportedArchitectures = {"i386"};
  for (const auto& supported : supportedArchitectures) {
    if (architecture == supported) {
      return true;
    }
  }
  return false;
}

bool validateFilename(const std::string& filename) {
  if (filename.empty()) {
    return false;
  }
  if (filename.find_last_of('.exe') == std::string::npos) {
    return false;
  }
  for (char c : filename) {
    if (!std::isalnum(c) && c != '_') {
      return false;
    }
  }
  return true;
}

bool validateFileType(const std::string& filetype) {
  if (filetype == "i386.zip" || filetype == "i386.exe") {
    return true;
  }
  return false;
}

bool validateReleaseNotes(const std::string& releaseNotes) {
  if (releaseNotes.empty()) {
    return false;
  }
  if (releaseNotes.find_first_of('\n') == std::string::npos) {
    return false;
  }
  for (char c : releaseNotes) {
    if (!std::isalnum(c) && c != ' ') {
      return false;
    }
  }
  return true;
}

