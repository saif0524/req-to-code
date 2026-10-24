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

const std::string& getVspCodeProvidersName() const
const std::string& getVspPhysicalAddress() const
const std::string& getVspCommunicationAddress() const
const std::string& getVspHealthSubdistrictLocality() const
const std::string& getVsp FacilityType() const
const std::string& getVspRegistrationBody() const
const std::string& getVspDesignation() const
const std::string& getVspContactPerson() const
const std::string& getVspEmailId() const
const std::string& getVspStatus() const

int getVspContactNumber() int;

int getVspContactNumber() {
    int contactNumber = std::stoi(getVspContactPerson()[0].str());
    return contactNumber;
    }

