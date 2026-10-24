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

initialize_temperature_range(std::string initialization_file_path);

void initialize_temperature_range(std::string initialization_file_path) {
   // Open the initialization file
   std::ifstream init_file(init_file_path);
   if (!init_file.is_open()) {
     throw std::runtime_error("Failed to open initialization file.");
   }

   // Read the valid temperature range from the initialization file
   double min_temp, max_temp;
   init_file >> min_temp >> max_temp;

   // Set the valid temperature range
   valid_temperature_range = std::make_pair(min_temp, max_temp);
}

