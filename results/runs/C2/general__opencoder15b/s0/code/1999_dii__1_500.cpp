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

std::string getCountryCode();
std::string getCountryName();
std::string getCountryAbbreviation();
std::string getCountryOfficialName();
std::string getCountryStandardName();

DII::getCountryCode() {
    return countryCode;
}

std::string DII::getCountryName() {
     return countryName;
}

std::string DII::getCountryAbbreviation() {
     return countryAbbreviation;
}

std::string DII::getCountryOfficialName() {
     return countryOfficialName;
}

std::string DII::getCountryStandardName() {
     return countryStandardName;
}

