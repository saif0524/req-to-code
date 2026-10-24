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

bool canTurnOnUnit(int maxUnits, int currentUnits);
void addUnitToQueue(std::queue<int>& queue, int unitId);
void processTurnOnRequest(int maxUnits, int currentUnits, int unitId);
void checkQueueAndSubmitRequest(std::queue<int>& queue, int thermostatId);
void turnOffUnit(int unitId);

bool canTurnOnUnit(int maxUnits, int currentUnits) {
  if (currentUnits < maxUnits) {
    return true;
  }
  return false;
}

void addUnitToQueue(std::queue<int>& queue, int unitId) {
  if (currentUnits < maxUnits) {
    queue.push(unitId);
  }
}

void processTurnOnRequest(int maxUnits, int currentUnits, int unitId) {
  if (currentUnits < maxUnits) {
    // Generate a request to turn on the unit
    // This can be implemented by calling a function like submitRequestToTurnOn(unitId);
    // For demonstration, we'll just print a message
    std::cout << "Request to turn on unit 

void checkQueueAndSubmitRequest(std::queue<int>& queue, int thermostatId) {
  if (!queue.empty()) {
    int unitId = queue.front();
    if (!thermostatNeedsUnit(thermostatId)) {
      submitRequestToTurnOn(unitId);
    }
    queue.pop();
  }
}

void turnOffUnit(int unitId) {
  if (isUnitOn(unitId)) {
    // Turn off the unit
    // This can be implemented by calling a function like turnOffUnitInThermostat(unitId);
    // For demonstration, we'll just print a message
    std::cout << "Unit 

