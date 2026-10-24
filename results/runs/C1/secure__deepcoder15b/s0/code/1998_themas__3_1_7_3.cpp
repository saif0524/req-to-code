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

double check_exceeded_temp(double temp, double limit);
bool check_valid_temp(double temp, double limit);
void handle_invalid_temp_500(double temp, double limit);
void handle_invalid_temp_700(double temp, double limit);
void handle_invalid_temp_1000(double temp, double limit);

bool check_valid_temp(double temp, double limit) 
    { 
        if (temp < 0) 
        {
            return false;
        }
        if (temp > limit) 
        {
            return false;
        }
        return true;
    }

void handle_invalid_temp_500(double temp, double limit) {
  if (check_valid_temp(temp, limit)) {
    return false;
  }
  // Handle invalid temperature
  if (temp <= 0 || temp > limit) {
    // Generate a beep at 500Hz for 0.75 seconds
    double frequency = 500.0;
    double duration = 0.75;
    double interval = 1.0 / frequency;
    double current_time = 0.0;
    while (current_time < duration) {
      double next_time = current_time + interval;
      if (next_time > duration) {
        emitBeep(current_time, duration, frequency);
        break;
      }
      emitBeep(current_time, next_time, frequency);
      current_time = next_time;
    }
    // Now check if the temperature is valid
    bool should_reset = check_valid_temp(temp, limit);
    // Trigger a reset if needed
    return should_reset;
  }
  return false;
}

void handle_invalid_temp_700(double temp, double limit) {
  if (check_valid_temp(temp, limit)) {
    return false;
  }
  // Emit a beep at 700Hz for 0.75 seconds
  double frequency = 700.0;
  double duration = 0.75;
  double interval = 1.0 / frequency;
  double current_time = 0.0;
  bool should_reset = false;
  while (current_time < duration) {
    double next_time = current_time + interval;
    if (next_time > duration) {
      emitBeep(current_time, duration, frequency);
      break;
    }
    emitBeep(current_time, next_time, frequency);
    current_time = next_time;
  }
  should_reset = check_valid_temp(temp, limit);
  return should_reset;
  }
  "

void handle_invalid_temp_1000(double temp, double limit) {
  double frequency = 1000.0;
  double interval = 1.0 / frequency;
  double start_time = 0.0;
  double end_time = start_time + interval;
  double duration = end_time - start_time;

  double beep_duration = 0.5;
  while (start_time < end_time) {
    emitBeep(start_time, start_time + interval, frequency);
    start_time += interval;
  }
}

