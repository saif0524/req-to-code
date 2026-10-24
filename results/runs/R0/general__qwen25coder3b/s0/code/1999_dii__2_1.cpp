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

std::vector<std::string> getDatabaseEngineNames();
std::vector<std::string> getDetailedInterfaceInfo(const std::string& engineName);

class DatabaseEngines {
public:
  static std::vector<std::string> getDatabaseEngineNames() {
    return {"Sybase", "Oracle", "Informix"};
  }
};

std::vector<std::string> getDetailedInterfaceInfo(const std::string& engineName) {
  std::vector<std::string> engineNames = DatabaseEngines::getDatabaseEngineNames();
  for (const auto& name : engineNames) {
    if (name == engineName) {
      // Return detailed interface information for the given engine
      return {"Detailed interface information for " + engineName};
    }
  }
  // Return an empty vector if the engine name is not found
  return {};
}

