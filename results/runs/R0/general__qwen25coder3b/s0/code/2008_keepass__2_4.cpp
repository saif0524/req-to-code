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

bool checkOperatingSystem(const std::string& os);
bool checkUserInterface(const std::string& ui);
bool validateFilenameArchitecture(const std::string& filename, const std::string& architecture);
bool validateSourceArchive(const std::string& archive, const std::string& platform);
bool validateReleaseNotes(const std::string& notes);

bool checkOperatingSystem(const std::string& os) {
  std::vector<std::string> supportedOs = {"WINE", "32-bit MS Windows (95/98)", "32-bit MS Windows (NT/2000/XP)", "All 32-bit MS Windows (95/98/NT/2000/XP)", "Win2K", "WinXP", "Microsoft Windows Server 2003"};
  for (const auto& supported : supportedOs) {
    if (os == supported) {
      return true;
    }
  }
  return false;
}

bool checkUserInterface(const std::string& ui) {
  std::vector<std::string> supportedUi = {"NET/Mono", "Win32 (MS Windows)"};
  for (const auto& supported : supportedUi) {
    if (ui == supported) {
      return true;
    }
  }
  return false;
}

bool validateFilenameArchitecture(const std::string& filename, const std::string& architecture) {
  if (filename.find(architecture) != std::string::npos) {
    return true;
  }
  return false;
}

bool validateSourceArchive(const std::string& archive, const std::string& platform) {
  if (archive.find(platform) != std::string::npos) {
    return true;
  }
  return false;
}

bool validateReleaseNotes(const std::string& notes) {
  std::vector<std::string> keywords = {"changes", "added", "fixed", "new", "improved", "bug", "fix", "enhancement", "update"};
  for (const auto& keyword : keywords) {
    if (notes.find(keyword) != std::string::npos) {
      return true;
    }
  }
  return false;
}

