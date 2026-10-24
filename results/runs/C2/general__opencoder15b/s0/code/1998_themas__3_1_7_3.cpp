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

std::pair<bool, int> alarm_event;
std::vector<std::pair<bool, int>> alarm_events;

void generate_alarm_beeps(bool is_temperature_exceeded, int temperature);
void record_alarm_event(bool is_temperature_exceeded, int temperature);
std::vector<std::pair<bool, int>> get_alarm_events();

void generate_alarm_beeps(bool is_temperature_exceeded, int temperature) {
    // Generate alternating beeps for temperature exceeded alarm
    if (is_temperature_exceeded) {
     for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
         // 1kHz beep
         beep(1000, 3);
        } else {
         // 15kHz beep
         beep(15000, 3);
        }
        // Wait for 1.5 seconds
        wait(1.5);
     }
    } else {
     for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
         // 500Hz beep
         beep(500, 3);
        } else {
         // 700Hz beep
         beep(700, 3);
        }
        // Wait for 1.5 seconds
        wait(1.5);
     }
    }
}

void record_alarm_event(bool is_temperature_exceeded, int temperature) {
   // Record the alarm event
   std::pair<bool, int> alarm_event = std::make_pair(is_temperature_exceeded, temperature);
   alarm_events.push_back(alarm_event);
}

std::vector<std::pair<bool, int>> get_alarm_events() {
   return alarm_events;
}

std::vector<std::pair<bool, int>> get_alarm_events() {
    return alarm_events;
}

