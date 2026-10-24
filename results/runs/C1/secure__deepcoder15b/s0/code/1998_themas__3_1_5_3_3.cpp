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

unit_id: int, current_state: bool => bool;
unit_id: int => struct { unit_id: int; on_flag: bool };
unit_id: int => struct { unit_id: int; off_flag: bool };

bool unit_id(int unit_id) {
  return !current_state;
  }

struct unit_id(int unit_id) {
    return struct { unit_id: int; on_flag: bool } {
      unit_id: unit_id,
      on_flag: !current_state
    };
  },
  

struct unit_id(int unit_id) {
  return struct { unit_id: unit_id, off_flag: !current_state }; }

