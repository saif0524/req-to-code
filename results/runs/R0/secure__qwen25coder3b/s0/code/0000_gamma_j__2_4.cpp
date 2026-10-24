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

bool validateBrowser(const std::string& browserVersion);
bool validateOperatingSystem(const std::string& osName, const std::string& osVersion);
bool validateDatabase(const std::string& databaseType);
bool validateUSBInterface(const std::string& usbInterfaceType);
bool validateDivers(const std::string& diversType);

bool validateBrowser(const std::string& browserVersion) {
  if (browserVersion == "Microsoft Internet Explorer version 6" || browserVersion == "Microsoft Internet Explorer version 7" || browserVersion == "Netscape Communicator Version 4" || browserVersion == "Netscape Communicator Version 5") {
    return true;
  }
  return false;
}

bool validateOperatingSystem(const std::string& osName, const std::string& osVersion) {
  if (osName == "Slackware Linux" && (osVersion == "2.6")) {
    return true;
  }
  return false;
}

bool validateDatabase(const std::string& databaseType) { return databaseType == "SQL"; }

bool validateUSBInterface(const std::string& usbInterfaceType) {
  if (usbInterfaceType == "Yoggie Corporation USB Interface" || usbInterfaceType == "Yoggie Corporation Divers") {
    return true;
  }
  return false;
}

bool validateDivers(const std::string& diversType) { if (diversType == "Yoggie Corporation USB Interface" || diversType == "Yoggie Corporation Divers") { return true; } return false; }

