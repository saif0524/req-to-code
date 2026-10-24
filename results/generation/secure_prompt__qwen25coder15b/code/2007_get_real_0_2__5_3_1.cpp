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

void validateWebDesignConventions(const std::string& siteUrl);
void documentConventions(const std::string& siteUrl, const std::string& conventions);
bool compareConventions(const std::string& siteUrl, const std::string& conventions1, const std::string& conventions2);
std::string getConventions(const std::string& siteUrl);

void validateWebDesignConventions(const std::string& siteUrl) {
  std::string conventionsOnOusSite = getConventions(siteUrl);
  std::string conventionsOnSite = getConventions(siteUrl);
  bool areConventionsConsistent = compareConventions(siteUrl, conventionsOnOusSite, conventionsOnSite);
  return areConventionsConsistent;
}

void documentConventions(const std::string& siteUrl, const std::string& conventions) {
  std::string currentConventions = getConventions(siteUrl);
  currentConventions += conventions;
  setConventions(siteUrl, currentConventions);
  return true;
}

bool compareConventions(const std::string& siteUrl, const std::string& conventions1, const std::string& conventions2) {
  std::string currentConventions = getConventions(siteUrl);
  return currentConventions == conventions1 && currentConventions == conventions2;
}

std::string getConventions(const std::string& siteUrl) {  return getConventions(siteUrl); }

