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

.cpp

string get_real() -> string;
string add_data(string buffer[]) -> void;
string remove_data(string buffer[]) -> void;
string check_file_exists(string file[]) -> bool;
string handle_request(string request[]) -> string;

string get_real() { string buffer = get_from_buffer(); if (buffer.empty() || buffer.size() <= 0) { return "Server is offline or not accessible.\n"; } string status = buffer[0]; buffer.pop_back(); return status; }

string add_data(string buffer[]) -> void {
    if (buffer.empty() || buffer.size() <= 0) {
        return "Error: Buffer is too big or not valid.\n";
    }
    buffer.push_back("1");
    return "Data added successfully.\n";
    }
    "reasoning": [
        "The function add_data was not compiled because it did not follow best practices. The main issues were:\n1. The return type was set to void, but it was supposed to add data to a buffer and return a message.\n2. The buffer check was missing, causing the function to not validate its input before attempting to modify it.\n3. The data parameter was not defined, leading to undefined behavior when trying to push it into the buffer.
        4. The function returned a string instead of a message, which was not in line with the intended functionality.
        5. The return type was incorrect, leading to potential infinite loops or other issues.
    ],
    "added_declarations": [],
    "reasoning": [3 to 6 short steps saying what is wrong and how you fix it, "code": the complete corrected function definition only (no #include lines, no main), and "added_declarations": any struct, enum, using alias or constant your fix needs that is missing from the shared declarations, declarations only, or an empty string"]

string remove_data(string buffer[]) -> bool {
  if (buffer.empty() || buffer.size() <= 0) {
    return false;
  }
  buffer.pop_back();
  return true;
  }

bool check_file_exists(string file_path) { if (!isfile(file_path)) { return false; } return is_writable(file_path); }

