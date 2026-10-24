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

void generateHCSignal(const HeatingOrCoolingUnit& unit, const Status& status);
void outputStatus(const HeatingOrCoolingUnit& unit, const Status& status);
void generateEvent(const HeatingOrCoolingUnit& unit, const Status& oldStatus, const Status& newStatus);

void generateHCSignal(const HeatingOrCoolingUnit& unit, const Status& status) { issueSignal(unit, status); }

struct HeatingOrCoolingUnit {}; struct Status {}; void outputStatus(const HeatingOrCoolingUnit& unit, const Status& status) { issueSignal(unit, status); }

void generateEvent(const HeatingOrCoolingUnit& unit, const Status& oldStatus, const Status& newStatus) {
  // Store the old and new statuses locally
  Status oldStatusCopy = oldStatus;
  Status newStatusCopy = newStatus;

  // Output the statuses to a logging mechanism or report
  logEvent(unit, oldStatusCopy, newStatusCopy);
}

