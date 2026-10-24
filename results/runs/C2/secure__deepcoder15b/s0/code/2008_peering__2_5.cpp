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

string
string checkData(const string& cdns, const string& request)
std::string

string;
string;
string;
string;
string;

string(const vector<string>& cdns, const string& request) {
  vector<string> currentCDNs = cdns;
  int currentCDNIndex = 0;

  for (string& request : requests) {
    string handlerCDN = -1;
    string error = string();

    if (currentCDNIndex < currentCDNs.size()) {
      if (checkCDNCapacity(currentCDNs[currentCDNIndex], request)) {
        handlerCDN = currentCDNs[currentCDNIndex];
        currentCDNIndex = 0;
      } else if (currentCDNIndex > 0) {
        currentCDNIndex = currentCDNIndex - 1;
      }
    }

    if (handlerCDN == -1 && currentCDNIndex > 0) {
      error = error(
        handlerCDN, error
      );
    }

    if (handlerCDN == -1) {
      error = error(
        

string checkData(const string& cdns, const string& request) {
  return checkData(cdns, request);
}

std::string error(std::string cdns, std::string request) {
  string reason = checkData(cdns, request);
  if (reason) {
    log(
      checkData(cdns, request);
    );
    if (reason) {
      log(
        checkData(cdns, request);
      );
    }
    return string();
  }
  return string();
}

string error(string cdns, string request) {
  string reason = checkData(cdns, request);
  if (reason) {
    log(
      checkData(cdns, request),
      reason
    );
  }
  return string();
}

std::string error(std::string cdns, std::string request) {
  std::string reason = checkData(cdns, request);
  if (reason) {
    log(checkData(cdns, request));
  }
  return std::string();

