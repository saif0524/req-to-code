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

No additional declarations needed.

string get_acm(string organizationName): string;
string get_IEEE(string organizationName): string;
string get_subgroup(string organizationName, string ACMLink, string IEEELink): string;

string get_acm(string name) { size_t minus_pos = name.find('-'); if (minus_pos != string::npos) { return name.substr(0, minus_pos) + '-' + name.substr(minus_pos + 1); } return "ACM"; }

string get_IEEE(string organizationName) {
    size_t hyphenPos = organizationName.find('-');
    if (hyphenPos != string::npos) {
        string partAfter = organizationName.substr(hyphenPos + 1);
        return partAfter + 

string get_acm(string organizationName) { size_t minus_pos = organizationName.find('-'); if (minus_pos != string::npos) { return organizationName.substr(0, minus_pos) + '-' + organizationName.substr(minus_pos + 1); } return "ACM"; }

