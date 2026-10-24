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
    std::string masterInfo = getVSPMasterInfo(vspCode);
    nlohmann::json j = nlohmann::json::parse(masterInfo);
    return j.dump();
}

bool updateVSPMasterInfo(const std::string& vspCode, const std::string& updatedInfo) {
    std::string masterInfo = getVSPMasterInfo(vspCode);
    nlohmann::json j = nlohmann::json::parse(masterInfo);
    j.update(updatedInfo);
    return saveVSPMasterInfo(vspCode, j.dump());
}

bool deleteVSPMasterInfo(const std::string& vspCode) {
     std::string masterInfo = getVSPMasterInfo(vspCode);
     nlohmann::json j = nlohmann::json::parse(masterInfo);
     return saveVSPMasterInfo(vspCode, j.dump());
}

bool addVSPMasterInfo(const std::string& vspCode, const std::string& newInfo) {
     std::string masterInfo = getVSPMasterInfo(vspCode);
     nlohmann::json j = nlohmann::json::parse(masterInfo);
     j.update(newInfo);
     return saveVSPMasterInfo(vspCode, j.dump());
}

std::string getVSPMasterInfoStatus(const std::string& vspCode)
{
    std::string masterInfo = getVSPMasterInfo(vspCode);
    if (masterInfo.find("Status":"Active") != std::string::npos) {
        return "Active";
    } else {
        return "In-Active";
    }
}

