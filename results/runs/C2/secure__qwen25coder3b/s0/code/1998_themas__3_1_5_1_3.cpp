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

bool addUnitToQueue(std::queue<int>& queue, int unitId, int currentUnits) { if (currentUnits < maxUnits) { queue.push(unitId); return true; } return false; }

void processTurnOnRequest(int maxUnits, int currentUnits, int unitId) { if (currentUnits < maxUnits) { submitRequestToTurnOn(unitId); } else { std::cout << "Cannot turn on unit"; } }

void checkQueueAndSubmitRequest(std::queue<int>& queue, int thermostatId) { if (!queue.empty()) { int unitId = queue.front(); if (!thermostatNeedsUnit(thermostatId)) { submitRequestToTurnOn(unitId); } queue.pop(); } return; }

void turnOffUnit(int unitId) { if (isUnitOn(unitId)) { turnOffUnit(unitId); } else { return; } }

