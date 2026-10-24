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

struct Sensor { double temperature; double humidity; double powerUsage; };

void displayCurrentStatus(const SystemStatus& status);
void generateReports(const SystemData& data);
void checkFaultyTemperatures(const SystemData& data);
void filterStatusInformation(SystemStatus& status);
void updateSystemData(SystemData& data);

struct SystemStatus { int temperature; int humidity; int powerUsage; }; void displayCurrentStatus(const SystemStatus& status) { std::cout << "Current Status:" << "Temperature: " << status.temperature << "°C" << "Humidity: " << status.humidity << "%" << "Power Usage: " << status.powerUsage << "W" << std::endl; }

void generateReports(const SystemStatus& data) { json report; report["temperature"] = data.temperature; report["humidity"] = data.humidity; report["powerUsage"] = data.powerUsage; std::cout << "Reports: " << report.dump() << std::endl; }

struct SystemData { double temperature; double humidity; double powerUsage; std::string warning; std::vector<Sensor> sensors; }; void checkFaultyTemperatures(const SystemData& data) { json report; for (const auto& sensor : data.sensors) { if (sensor.temperature > 30) { report[

void filterStatusInformation(SystemStatus& status) { json filteredStatus; if (status.temperature <= 30) { filteredStatus[

void updateSystemData(SystemData& data) { double temperature = readTemperatureSensor(); double humidity = readHumiditySensor(); double powerUsage = readPowerUsageSensor(); data.temperature = temperature; data.humidity = humidity; data.powerUsage = powerUsage; if (temperature > 30) { data.warning = "Faulty temperature detected: " + std::to_string(temperature) + "°C"; } }

