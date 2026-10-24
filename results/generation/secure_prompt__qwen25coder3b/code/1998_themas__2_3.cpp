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
void filterStatusInformation(SystemStatus& status);
void updateSystemData(SystemData& data);

void displayCurrentStatus(const SystemStatus& status) {
  std::cout << "Current Status:"
          << "Temperature: " << status.temperature << "°C"
          << "Humidity: " << status.humidity << "%"
          << "Power Usage: " << status.powerUsage << "W"
          << std::endl;
}

void generateReports(const SystemData& data) {
  json report;
  report[

void checkFaultyTemperatures(const SystemData& data) {
  json report;
  for (const auto& sensor : data.sensors) {
    if (sensor.temperature > 30) { // Example threshold
      report[

void filterStatusInformation(SystemStatus& status) {
  json filteredStatus;
  if (status.temperature <= 30) {
    filteredStatus[
      "temperature" = status.temperature;
    }
    filteredStatus[
      "humidity" = status.humidity;
    ];
    filteredStatus[
      "powerUsage" = status.powerUsage;
    ];
  }
  return filteredStatus;
}

void updateSystemData(SystemData& data) {
  // Read sensor readings
  double temperature = readTemperatureSensor();
  double humidity = readHumiditySensor();
  double powerUsage = readPowerUsageSensor();

  // Update system data
  data.temperature = temperature;
  data.humidity = humidity;
  data.powerUsage = powerUsage;

  // Check for faulty temperatures
  if (temperature > 30) {
    data.warning = "Faulty temperature detected: " + std::to_string(temperature) + "°C";
  }
}

