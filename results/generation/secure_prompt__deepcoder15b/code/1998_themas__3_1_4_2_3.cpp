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

std::pair<bool, bool> check_condition_1(std::double temperature, std::double set_point, std::lock_guard<std::mutex> &lock);
std::pair<bool, bool> check_condition_2_above(std::double temperature, std::double set_point, std::lock_guard<std::mutex> &lock);
std::pair<bool, bool> check_condition_2_below(std::double temperature, std::double set_point, std::lock_guard<std::mutex> &lock);
void turn_off_heating_and_cooling(std::double temperature, std::double set_point);
void turn_on_heating(std::double temperature, std::double set_point);

pair<bool, bool> check_condition_1(double temperature, double set_point, lock) {
  lock.init();
  bool result = false;
  if (temperature == set_point) {
    result = false;
  } else {
    result = true;
  }
  lock.release();
  return {result, result};
}

pair<bool, bool> check_condition_2_above(std::double temperature, std::double set_point, std::lock_guard<std::mutex> &lock)
    {
      lock.init();
      bool result = false;
      if (temperature > set_point)
      {
        result = true;
      }
      lock.release();
      return {result, false};
    }
  }

pair<bool, bool> check_condition_2_below(std::double temperature, std::double set_point, std::lock_guard<std::mutex> &lock)
    {
        lock.init();
        bool result = false;
        if (temperature < set_point)
        {
            result = true;
        }
        lock.release();
        return {result, false};
    }

pair<bool, bool> turn_off_heating_and_cooling(double temperature, double set_point, lock) { pair<bool, bool> result = check_condition_1(temperature, set_point, lock); return result; }

pair<bool, bool> turn_on_heating(double temperature, double set_point, lock) { pair<bool, bool> result = check_condition_2_above(temperature, set_point, lock); return result; }

