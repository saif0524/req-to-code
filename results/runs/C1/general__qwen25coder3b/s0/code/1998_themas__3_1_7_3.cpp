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

void generateTemperatureAlarmBeeps(bool isInvalidTemperature);
void generateTemperatureLimitAlarmBeeps(bool isTemperatureLimitExceeded);
void recordAlarmEvent(bool isInvalidTemperature, bool isTemperatureLimitExceeded);

void generateTemperatureAlarmBeeps(bool isInvalidTemperature) {
  int frequency = 500;
  int duration = 3000; // 3/4 seconds in milliseconds
  for (int i = 0; i < 10; i++) { // Output 10 beeps
    beep(frequency, duration);
    frequency = (frequency == 500) ? 700 : 500;
  }
}

void generateTemperatureLimitAlarmBeeps(bool isTemperatureLimitExceeded) {
  int frequency = 1000;
  int duration = 500; // 0.5 seconds in milliseconds
  for (int i = 0; i < 10; i++) { // Output 10 beeps
    beep(frequency, duration);
    frequency = (frequency == 1000) ? 1500 : 1000;
  }
}

struct AlarmEvent { bool isInvalidTemperature; bool isTemperatureLimitExceeded; int timestamp; }; const int MAX_EVENTS = 10; AlarmEvent alarmEvents[MAX_EVENTS]; int eventIndex = 0; void recordAlarmEvent(bool isInvalidTemperature, bool isTemperatureLimitExceeded) { if (eventIndex >= MAX_EVENTS) { // Handle full array case } else { alarmEvents[eventIndex].isInvalidTemperature = isInvalidTemperature; alarmEvents[eventIndex].isTemperatureLimitExceeded = isTemperatureLimitExceeded; alarmEvents[eventIndex].timestamp = time(NULL); eventIndex++; } }

