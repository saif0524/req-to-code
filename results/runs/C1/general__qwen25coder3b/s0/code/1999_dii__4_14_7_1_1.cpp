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

std::vector<std::string> getExternalInterfaces();
std::vector<std::string> getDetailedInterfaceInfo();

std::vector<std::string> getExternalInterfaces() { return {"Interface1", "Interface2", "Interface3"}; }

std::vector<std::string> getDetailedInterfaceInfo() { return {}; }

