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

process_request(int unit_id, bool on_off);

void process_request(int unit_id, bool on_off) {
   // Check if the maximum number of heating or cooling units is already running
   if (max_units_running == MAX_UNITS) {
     // If the maximum number of units is reached, add the request to the LIFO queue
     queue.push(Request(unit_id, on_off));
   } else {
     // If the maximum number of units is not reached, turn on the requested unit
     if (on_off) {
       turn_on(unit_id);
     } else {
       turn_off(unit_id);
     }
   }
}

