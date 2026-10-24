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

string vector unordered_set tuple set map unordered_map auto
string unordered_map
string defaultAutoType() { return "0"; }
string defaultAutoType() { return '0'; }

string;
string;
string;
string;
string;

string defaultAutoType() { string first = "0"; string second = " \n"; string third = "TAB"; string fourth = " "
string fifth = "PASSWORD"; string sixth = " \n"; string seventh = "ENTER"; return first + second + third + fourth + fifth + sixth + seventh; }

string customAutoType(string autoType, string customPart) {
    string defaultSequence = "0";
    if (!customPart.empty()) {
        defaultSequence += "\n";
        defaultSequence += customPart;
    }
    return defaultSequence;
}

string autoGenerateSequence(string autoType, string customPart) {
  string defaultSequence = "0\n\n\n";
  if (!customPart.empty()) {
    defaultSequence += customPart;
  }
  return defaultSequence;
}

string determineMethod(string autoType, string customPart) {
  if (autoType == "prefix" && !customPart.empty()) {
    return 1; 
  } else if (autoType == "exact" && customPart == "exact" && !customPart.empty()) {
    return 2; 
  } else if (customPart == "password" && !autoType.empty() && !autoType == "prefix" && !autoType == "exact") {
    return 3; 
  } else {
    return 0; 
  }
  return 0;
  return defaultAutoType();
  return combineSequences(autoType, customPart);
  return determineMethod(...);
  return ...

string combineSequences(string autoType, string customPart) {
    string method;
    if (autoType == "prefix" && customPart != "") {
        method = 1;
    } else if (autoType == "exact" && customPart == "exact" && !customPart.empty()) {
        method = 2;
    } else if (autoType == "password" && customPart != "" && !autoType.empty() && !autoType == "prefix" && !autoType == "exact") {
        method = 3;
    }

    string result;
    switch (method) {
        case 1:
            result = "prefix" + customPart;
            break;
        case 2:
            result = "exact";
            break;
        case 3:
            result = "password" + customPart;
            break;
        default:
            result = "0";
            break;
    }

    return result;
}

