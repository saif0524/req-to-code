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

void calculateSystemAvailability(int startHour, int endHour, int daysPerYear, int plannedDowntime, int unplannedDowntime, int incidents, int restoreTime);
bool checkDowntime(int startHour, int endHour, int daysPerYear, int plannedDowntime, int unplannedDowntime, int incidents, int restoreTime);
int calculatePlannedDowntime(int plannedDowntime, int daysPerYear);
int calculateUnplannedDowntime(int unplannedDowntime, int daysPerYear);
int calculateIncidents(int incidents, int daysPerYear);

void calculateSystemAvailability(int startHour, int endHour, int daysPerYear, int plannedDowntime, int unplannedDowntime, int incidents, int restoreTime) {
  int totalPlannedDowntime = calculatePlannedDowntime(plannedDowntime, daysPerYear);
  int totalUnplannedDowntime = calculateUnplannedDowntime(unplannedDowntime, daysPerYear);
  int totalIncidents = calculateIncidents(incidents, daysPerYear);

  if (totalPlannedDowntime > plannedDowntime) {
    std::cout << "Error: Planned downtime exceeds allowed limit." << std::endl;
    return;
  }

  if (totalUnplannedDowntime > unplannedDowntime) {
    std::cout << "Error: Unplanned downtime exceeds allowed limit." << std::endl;
    return;
  }

  if (totalIncidents > incidents) {
    std::cout << "Error: Number of incidents exceeds allowed limit." << std::endl;
    return;
  }

  std::cout << "System availability is valid." << std::endl;
}

bool checkDowntime(int startHour, int endHour, int daysPerYear, int plannedDowntime, int unplannedDowntime, int incidents, int restoreTime) {
  int totalPlannedDowntime = calculatePlannedDowntime(plannedDowntime, daysPerYear);
  int totalUnplannedDowntime = calculateUnplannedDowntime(unplannedDowntime, daysPerYear);
  int totalIncidents = calculateIncidents(incidents, daysPerYear);

  if (totalPlannedDowntime > plannedDowntime) {
    std::cout << "Error: Planned downtime exceeds allowed limit." << std::endl;
    return false;
  }

  if (totalUnplannedDowntime > unplannedDowntime) {
    std::cout << "Error: Unplanned downtime exceeds allowed limit." << std::endl;
    return false;
  }

  if (totalIncidents > incidents) {
    std::cout << "Error: Number of incidents exceeds allowed limit." << std::endl;
    return false;
  }

  std::cout << "System availability is valid." << std::endl;
  return true;
}

int calculatePlannedDowntime(int plannedDowntime, int daysPerYear) { return plannedDowntime * daysPerYear; }

int calculateUnplannedDowntime(int unplannedDowntime, int daysPerYear) { return unplannedDowntime * daysPerYear; }

int calculateIncidents(int incidents, int daysPerYear) { return incidents * daysPerYear; }

