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

maxUnitsRunning: bool[maxUnitTypes];
queue: std::queue<request>;
request: struct {
   int unitType;
   bool isOn;
};
thermostat: std::array<struct { bool isOn; }, maxUnitTypes>;
std::queue<request> queue[maxUnitTypes];
struct { bool isOn; } thermostat[maxUnitTypes];
maxUnitsRunning: bool[maxUnitTypes];
queue: std::queue<request>;
request: struct {
  int unitType;
  bool isOn;
};
thermostat: std::array<struct { bool isOn; }, maxUnitTypes>;

void processRequest(int unitType, bool isOn);
void processQueue(int unitType);
void checkQueue(int unitType);
void turnOnUnit(int unitType);

void processRequest(int unitType, bool isOn) {
    // Check if the maximum number of heating or cooling units is already running
    if (maxUnitsRunning[unitType]) {
        // Add the request to the LIFO queue
        if (queue[unitType].empty()) {
            queue[unitType].push(request);
        } else {
            queue[unitType].push(queue[unitType].front());
            queue[unitType].pop();
        }
    } else {
        // Generate a request to turn on the requested unit
        request = { unitType, isOn: true };
        // Check the queue of waiting requests
        checkQueue(unitType);
        // Turn on the unit if the thermostat still needs it turned on
        if (thermostat[unitType].isOn && !thermostat[unitType].isOn) {
            turnOnUnit(unitType);
        }
    }
}

void processQueue(int unitType) {
    if (queue[unitType].empty()) {
     return;
    } else {
     request = queue[unitType].front();
      queue[unitType].pop();
     checkQueue(unitType);
      if (thermostat[unitType].isOn && !thermostat[unitType].isOn) {
       turnOnUnit(unitType);
     }
    }
}

void checkQueue(int unitType) {
    while (!queue[unitType].empty()) {
     request = queue[unitType].front();
      queue[unitType].pop();
      // Check if the request can be fulfilled
      // If the request can be fulfilled, remove the request from the queue and check the next request
      // If the next request cannot be fulfilled, return to the previous request and continue to check the next request
      // If the queue is empty, return without doing anything
    }
}

void turnOnUnit(int unitType) {
  // Check if the maximum number of heating or cooling units is already running
  if (maxUnitsRunning[unitType]) {
    // Add the request to the LIFO queue
    if (queue[unitType].empty()) {
      queue[unitType].push(request);
    } else {
      queue[unitType].push(queue[unitType] .front());
      queue[unitType].pop();
    }
  } else {
    // Generate a request to turn on the requested unit
    request = { unitType, isOn: true };
    // Check the queue of waiting requests
    checkQueue(unitType);
    // Turn on the unit if the thermostat still needs it turned on
    if (thermostat[unitType].isOn && !thermostat[unitType].isOn) {
      turnOnUnit(unitType);
    }
  }
}

