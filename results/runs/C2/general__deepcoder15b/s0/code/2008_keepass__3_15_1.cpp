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

string defaultAutoType() { return "0"; }
string vector() { return vector::default; }
tuple tuple() { return tuple::default; }
set set() { return set::default; }
map map() { return map::default; }
unordered_map unordered_map() { return unordered_map::default; }
string is used

string;
string;
string;
string;
string;

string generateSequence(string prefix, string customPart) {
  string result;
  if (prefix == "prefix" && customPart != "") {
    result = "prefix" + customPart;
  } else if (prefix == "exact" && customPart == "exact" && !customPart.empty()) {
    result = "exact";
  } else if (prefix == "password" && customPart != "" && !prefix.empty() && !prefix == "prefix" && !prefix == "exact") {
    result = "password" + customPart;
  }
  return result;
}

string customAutoType(string autoType, string customPart) {
    if (autoType == "prefix") {
        return autoType + customPart;
    } else if (autoType == "exact") {
        return "exact";
    } else if (autoType == "password") {
        return "password" + customPart;
    } else {
        return "0";
    }
    return null; // Or handle as needed
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

