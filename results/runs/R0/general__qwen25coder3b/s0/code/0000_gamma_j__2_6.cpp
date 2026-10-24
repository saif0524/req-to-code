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

void generateOnlineHelp(const std::string& webInterfacePath);
void createOperationsAndMaintenanceManual(const std::string& manualPath);
void createUsersGuideBook(const std::string& guidePath);
void createInstallationInstructions(const std::string& instructionsPath);

void generateOnlineHelp(const std::string& webInterfacePath) {
  createOperationsAndMaintenanceManual(webInterfacePath + "/operations_and_maintenance_manual.pdf");
  createUsersGuideBook(webInterfacePath + "/users_guide_book.pdf");
  createInstallationInstructions(webInterfacePath + "/installation_instructions.pdf");
}

void createOperationsAndMaintenanceManual(const std::string& manualPath) {
  createManual(manualPath, "Operations and Maintenance Manual");
}

void createUsersGuideBook(const std::string& guidePath) {
  createManual(guidePath, "Users Guide Book");
}

void createInstallationInstructions(const std::string& instructionsPath) {
  createManual(instructionsPath, "Installation Instructions");
}

