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

std::string generate_message(std::string message, std::ostream& stream);
std::string create_staff_code(const std::string& vsp_code);
void save_new_staff(std::string new_name, const std::string& new_type);
std::string message_stream;

std::string generate_message(std::string message, std::ostream& stream) {
  std::string result = "Generate a message when creating a new staff with existing name. The new staff must meet all mandatory criteria. The suffix is VSP Code + SC + 3 digits. If the new staff is valid, it will be saved automatically.\n";
  return result;
}

createstaff_code(std::string vsp_code) {
    std::string result = vsp_code + "-SC-3-digit number";
    return result;
}

void save_new_staff(std::string new_name, const std::string& new_type) {
  if (check_available(new_type)) {
    std::string data = createStaffData(new_name, new_type);
    // Update the data structure as needed
    return data;
  } else {
    // Handle error or return an appropriate message
    return;
  }
  // Generate the message
  std::string message = generate_message(

std::string message_stream() {
    std::string stream;
    std::streamStream(stream);
    return generate_message("", stream);
    }

