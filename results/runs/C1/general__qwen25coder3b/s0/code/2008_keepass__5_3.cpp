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

bool isGnuLicenseValid(const std::string& licenseText);
bool isSourceForgeAvailable();
bool isOfficialWebsiteAvailable();
bool isUninstallTraceless();
bool isLightProject();

bool isGnuLicenseValid(const std::string& licenseText) {
  const std::string copyrightNotice = "Copyright (C) 2003-2023 Dominik Reichl";
  const std::string version = "GNU General Public License version 2 or later";

  return licenseText.find(copyrightNotice) != std::string::npos &&
         licenseText.find(version) != std::string::npos;
}

bool isSourceForgeAvailable() {
  return isOfficialWebsiteAvailable();
}

bool isUninstallTraceless() {
  return isOfficialWebsiteAvailable();
}

bool isLightProject() {
  return isUninstallTraceless();
}

