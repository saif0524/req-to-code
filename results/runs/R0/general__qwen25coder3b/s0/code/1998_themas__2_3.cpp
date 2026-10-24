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

void displayCurrentStatus(const SystemStatus& status);
void generateReports(const SystemData& data);
void checkFaultyTemperatures(const SystemData& data);
void filterSupervisorInfo(SystemStatus& status);
void updateSystemStatus(SystemStatus& status, const SystemData& data);

void displayCurrentStatus(const SystemStatus& status) {
  std::cout << "Current System Status:"
  << "Temperature: " << status.temperature << "°C"
  << "Heating: " << (status.heating ? "On" : "Off")
  << "Cooling: " << (status.cooling ? "On" : "Off")
  << std::endl;
}

void generateReports(const SystemData& data) {
  std::string report = "{\n\"temperature\": \"" + std::to_string(data.temperature) + "°C\",\n  \"heating\": \"" + (data.heating ? "On" : "Off") + "\",\n  \"cooling\": \"" + (data.cooling ? "On" : "Off") + "\"\n}";
  return report;
}

void checkFaultyTemperatures(const SystemData& data) {
  const int safeTemperature = 20; // Example safe temperature
  const int maxTemperature = 30; // Example max temperature

  if (data.temperature < safeTemperature || data.temperature > maxTemperature) {
    std::string warning = "{\n""reason": "Faulty Temperature",\n""temperature": "

void filterSupervisorInfo(SystemStatus& status) {
  status.temperature = "Temperature: " + std::to_string(status.temperature) + "°C";
  status.heating = "Heating: " + (status.heating ? "On" : "Off") + "";
  status.cooling = "Cooling: " + (status.cooling ? "On" : "Off") + "";
  std::string report = "{\n""temperature": "{status.temperature}",\n""heating": "{status.heating}",\n""cooling": "{status.cooling}"\n}";\nreturn report;\n}

void updateSystemStatus(SystemStatus& status, const SystemData& data) {
  const int safeTemperature = 20; // Example safe temperature
  const int maxTemperature = 30; // Example max temperature

  if (data.temperature < safeTemperature) {
    status.heating = false;
    status.cooling = true;
  } else if (data.temperature > maxTemperature) {
    status.heating = true;
    status.cooling = false;
  } else {
    status.heating = true;
    status.cooling = true;
  }

  std::string report = generateReports(status);
  std::cout << report << std::endl;
}

