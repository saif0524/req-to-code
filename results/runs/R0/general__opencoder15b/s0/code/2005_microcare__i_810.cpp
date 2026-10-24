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

std::string getVSPMasterInfo(const std::string& vspCode);
bool updateVSPMasterInfo(const std::string& vspCode, const std::string& updatedInfo);
bool deleteVSPMasterInfo(const std::string& vspCode);
bool addVSPMasterInfo(const std::string& vspCode, const std::string& newInfo);
std::string getVSPMasterInfoStatus(const std::string& vspCode);

std::string getVSPMasterInfo(const std::string& vspCode) {
  // Your implementation here
}

bool updateVSPMasterInfo(const std::string& vspCode, const std::string& updatedInfo) {
  // Your implementation here
}

bool deleteVSPMasterInfo(const std::string& vspCode) {
  // Your implementation here
}

bool addVSPMasterInfo(const std::string& vspCode, const std::string& newInfo) {
  // Your implementation here
}

std::string getVSPMasterInfoStatus(const std::string& vspCode) {
   std::string masterInfo = getVSPMasterInfo(vspCode);
   if (masterInfo.find("Status": "Active") != std::string::npos) {
       return "Active";
   } else {
       return "In-Active";
   }
}

