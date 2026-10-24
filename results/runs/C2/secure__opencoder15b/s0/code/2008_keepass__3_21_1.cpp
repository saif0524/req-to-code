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

setExpirationTime(std::string& tan, time_t expirationTime);
getExpirationTime(std::string& tan);
getCurrentTime();
TAN(const std::string& password);
~TAN();
bool useTAN(const std::string& tan);
bool validateTAN(const std::string& tan);
void expireTAN(const std::string& tan);
std::string getTANInfo(const std::string& tan);

createTAN(const std::string& password);
useTAN(const std::string& tan);
validateTAN(const std::string& tan);
expireTAN(const std::string& tan);
getTANInfo(const std::string& tan);

class TAN {
public:
    TAN(const std::string& password);
    ~TAN();
    bool useTAN(const std::string& tan);
    bool validateTAN(const std::string& tan);
    void expireTAN(const std::string& tan);
    std::string getTANInfo(const std::string& tan);
};

bool createTAN(const std::string& password) {
    std::string tan = generateTAN(password);
    saveTAN(tan, password);
    return true;
};

bool useTAN(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        return true;
    }
    return false;
};

bool validateTAN(const std::string& tan) {
    if (!TANExists(tan)) {
        return false;
    }
    if (getExpirationTime(tan) <= getCurrentTime()) {
        return false;
    }
    return true;
};

void expireTAN(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        setExpirationTime(tan, getCurrentTime());
    }
};

std::string getTANInfo(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        std::string info = "Expiration time: " + std::to_string(getExpirationTime(tan));
        return info;
    }
};

bool useTAN(const std::string& tan) { 
// Check if the TAN is valid and has not expired. 
if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) { 
// The TAN is valid and has not expired. 
return true; 
} 
// The TAN is not valid or has expired. 
return false; 
}

class TAN {
public:
    TAN(const std::string& password);
    ~TAN();
    bool useTAN(const std::string& tan);
    bool validateTAN(const std::string& tan);
    void expireTAN(const std::string& tan);
    std::string getTANInfo(const std::string& tan);
};

bool createTAN(const std::string& password) {
    std::string tan = generateTAN(password);
    saveTAN(tan, password);
    return true;
};

bool useTAN(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        return true;
    }
    return false;
};

bool validateTAN(const std::string& tan) {
    if (!TANExists(tan)) {
        return false;
    }
    if (getExpirationTime(tan) <= getCurrentTime()) {
        return false;
    }
    return true;
};

void expireTAN(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        setExpirationTime(tan, getCurrentTime());
    }
};

std::string getTANInfo(const std::string& tan) {
    if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
        std::string info = "Expiration time: " + std::to_string(getExpirationTime(tan));
        return info;
    }
};

// The function validateTAN() is missing a declaration for the TANExists() function. It should include the necessary shared declarations.

void expireTAN(const std::string& tan) {
     if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
         setExpirationTime(tan, getCurrentTime());
     }
}

void expireTAN(const std::string& tan) {
      if (validateTAN(tan) && getExpirationTime(tan) > getCurrentTime()) {
         setExpirationTime(tan, getCurrentTime());
      }
}

