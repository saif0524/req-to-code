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

bool isUninstallClean(const std::string& path);
bool isGplCompliant(const std::string& licenseUrl);
bool isSourceForgeAvailable(const std::string& sourceForgeUrl);
bool isOfficialWebsiteAvailable(const std::string& officialWebsiteUrl);
bool isUninstallTraceless(const std::string& path);

bool isUninstallClean(const std::string& path) {
  if (std::filesystem::is_empty(path)) {
    return true;
  }
  return false;
}

bool isGplCompliant(const std::string& licenseUrl) {
  if (licenseUrl.find(".org/licenses/gpl.html") != std::string::npos) {
    return true;
  }
  return false;
}

bool isSourceForgeAvailable(const std::string& sourceForgeUrl) {
  std::filesystem::path urlPath(sourceForgeUrl);
  if (std::filesystem::exists(urlPath) &&
      std::filesystem::is_regular_file(urlPath) &&
      !std::filesystem::is_symlink(urlPath) &&
      !std::filesystem::is_directory(urlPath) &&
      std::filesystem::is_empty(urlPath) &&
      urlPath.extension() == "html" &&
      urlPath.is_valid()) {
    return true;
  }
  return false;
}

bool isOfficialWebsiteAvailable(const std::string& officialWebsiteUrl) {
  std::filesystem::path urlPath(officialWebsiteUrl);
  if (std::filesystem::exists(urlPath) &&
      std::filesystem::is_regular_file(urlPath) &&
      !std::filesystem::is_symlink(urlPath) &&
      !std::filesystem::is_directory(urlPath) &&
      std::filesystem::is_empty(urlPath) &&
      urlPath.extension() == "html") {
    return true;
  }
  return false;
}

bool isUninstallTraceless(const std::string& path) {
  if (std::filesystem::is_empty(path)) {
    return true;
  }
  return false;
}

