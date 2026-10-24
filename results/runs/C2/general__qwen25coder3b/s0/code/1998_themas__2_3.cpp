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
  std::string report = "{\n"temperature": "{data.temperature}"°C",
  "heating": "{data.heating ? "On" : "Off"}",
  "cooling": "{data.cooling ? "On" : "Off"}"\n}";\nreturn report;\n}

void checkFaultyTemperatures(const SystemData& data) {
  const int safeTemperature = 20; // Example safe temperature
  const int maxTemperature = 30; // Example max temperature

  std::string warning;

  if (data.temperature < safeTemperature || data.temperature > maxTemperature) {
    warning = "{\n"reason": "Faulty Temperature",\n"temperature": "{data.temperature}"°C\n}";
  }

  return;
}

void filterSupervisorInfo(SystemStatus& status) {
  std::string report = "{\n"temperature": "{status.temperature}"°C",
"heating": "{status.heating ? "On" : "Off"}",
"cooling": "{status.cooling ? "On" : "Off"}"\n}";\nreturn report;\n}

std::string updateSystemStatus(SystemStatus& status, const SystemData& data) {
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
  return report;
}

