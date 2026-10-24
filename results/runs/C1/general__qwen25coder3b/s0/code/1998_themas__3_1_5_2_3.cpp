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

void generateUnavailableEvent(const std::string& thermostatId, const std::string& unitId);
std::string getThermostatInfo(const std::string& thermostatId);
std::string getUnitStatus(const std::string& unitId);
std::string constructEventDescription(const std::string& thermostatInfo, const std::string& unitStatus);
void logEvent(const std::string& eventDescription);

void generateUnavailableEvent(const std::string& thermostatId, const std::string& unitId) {
  std::string thermostatInfo = getThermostatInfo(thermostatId);
  std::string unitStatus = getUnitStatus(unitId);
  std::string eventDescription = constructEventDescription(thermostatInfo, unitStatus);
  logEvent(eventDescription);
}

std::string getThermostatInfo(const std::string& thermostatId) { return getThermostatInfo(thermostatId); }

std::string getUnitStatus(const std::string& unitId) { return getUnitStatus(unitId); }

std::string constructEventDescription(const std::string& thermostatInfo, const std::string& unitStatus) { return "request denied: thermostat " + thermostatInfo + " unit " + unitStatus; }

void logEvent(const std::string& eventDescription) { std::cout << eventDescription << std::endl; }

